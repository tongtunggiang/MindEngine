#include "NumberDatumMatch.h"
#include "IdCheck.h"

namespace RuleBased
{

template<typename T>
bool NumberDatumMatch<T>::matchesNode(DataNode *node, BindingList &bindings)
{
	if (!node->isDatum())
		return false;

	bool idIsWildcard = IdCheck::isWildcard(identifier);
	if (!idIsWildcard &&
		identifier != node->getIdentifier())
		return false;

	Datum<T> *datum = (Datum<T>*)node;

	/**
	 * @todo Need adding bindings mechanism here
	 */
	if (min <= datum->getValue() && datum->getValue() <= max)
	{
		if (idIsWildcard)
		{
			// Add to the binding list.
			bindings[identifier] = node;
		}
		return true;
	}

	return false;
}

template<typename T>
NumberDatumMatch<T>::NumberDatumMatch(IdType identifier, T min, T max)
	: identifier(identifier), min(min), max(max)
{
}

template struct NumberDatumMatch<int>;
template struct NumberDatumMatch<float>;

}
