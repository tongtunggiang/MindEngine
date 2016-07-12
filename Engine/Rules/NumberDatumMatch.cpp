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
		identifier != node->identifier)
		return false;

	Datum<T> *datum = (Datum<T>*)node;

	/**
	 * @todo Need adding bindings mechanism here
	 */
	if (min <= datum->value && datum->value <= max)
	{
		if (idIsWildcard)
		{
			// Add to the binding list.
			bindings[identifier] = node;
		}
		return true;
	}
}

}
