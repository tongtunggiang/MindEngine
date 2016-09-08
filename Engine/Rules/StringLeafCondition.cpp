#include "StringLeafCondition.h"
#include "IdCheck.h"

#include <iostream>
#include <typeinfo>

namespace RuleBased
{

bool StringLeafCondition::matchesNode(DataNode * node)
{
	//std::cout << "Test node: " << name << " against data item: " << node->getName() << std::endl;

	if (!node->isLeaf())
		return false;

	bool idIsWildcard = IdCheck::isWildcard(name);
	if (!idIsWildcard &&
		name != node->getName())
		return false;

	LeafDataNode<std::string> *datum = (LeafDataNode<std::string>*)node;

	if (datum->getValue() == matchValue)
    {
		return true;
	}

	return false;
}

StringLeafCondition::StringLeafCondition(NodeName& name, std::string & matchValue)
	: matchValue(matchValue), DataNodeCondition(name)
{
}

StringLeafCondition::StringLeafCondition(const char* name, const char* matchValue)
	: DataNodeCondition()
{
	this->name = NodeName(name);
	this->matchValue = std::string(matchValue);
}

}
