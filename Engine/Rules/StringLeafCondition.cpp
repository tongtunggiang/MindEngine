#include "StringLeafCondition.h"
#include "IdCheck.h"

#include <iostream>
#include <typeinfo>

namespace RuleBased
{

bool StringLeafCondition::matchesNode(DataNode * node, BindingList & bindings)
{
	//std::cout << "Test node: " << identifier << " against data item: " << node->getIdentifier() << std::endl;

	if (!node->isLeaf())
		return false;

	bool idIsWildcard = IdCheck::isWildcard(identifier);
	if (!idIsWildcard &&
		identifier != node->getIdentifier())
		return false;

	LeafDataNode<std::string> *datum = (LeafDataNode<std::string>*)node;

	if (datum->getValue() == matchValue)
	{
		if (idIsWildcard)
		{
			bindings[identifier] = node;
		}
		return true;
	}

	return false;
}

StringLeafCondition::StringLeafCondition(IdType identifier, std::string & matchValue)
	: identifier(identifier), matchValue(matchValue)
{
}

}