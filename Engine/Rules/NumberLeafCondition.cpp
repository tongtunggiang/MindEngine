#include "NumberLeafCondition.h"
#include "IdCheck.h"

namespace RuleBased
{

template<typename T>
bool NumberLeafCondition<T>::matchesNode(DataNode *node, BindingList &bindings)
{
	if (!node->isLeaf())
		return false;

	bool idIsWildcard = IdCheck::isWildcard(identifier);
	if (!idIsWildcard &&
		identifier != node->getIdentifier())
		return false;

	LeafDataNode<T> *datum = (LeafDataNode<T>*)node;

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
NumberLeafCondition<T>::NumberLeafCondition(IdType identifier, T min, T max)
	: identifier(identifier), min(min), max(max)
{
}

template struct NumberLeafCondition<int>;
template struct NumberLeafCondition<float>;

}
