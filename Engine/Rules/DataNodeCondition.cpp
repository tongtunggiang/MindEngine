#include "DataNodeCondition.h"

namespace RuleBased
{

DataNodeCondition::DataNodeCondition()
{
	rightSibling = NULL;
}

DataNodeCondition::DataNodeCondition(NodeName &name)
{
	this->name = name;
	rightSibling = NULL;
}

bool DataNodeCondition::matches(DataNode *database)
{
    return matchesChildren((DataGroup*) database);
}

bool DataNodeCondition::matchesChildren(DataGroup *group)
{
	DataNode* node = group->getLeftMostChild();
	while (node)
	{
        if (matchesNode(node))
			return true;
		node = node->getRightSibling();
	}

	return false;
}

}
