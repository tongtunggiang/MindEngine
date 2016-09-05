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

bool DataNodeCondition::matches(DataNode *database, BindingList &bindings)
{
	return matchesChildren((DataGroup*) database, bindings);
}

bool DataNodeCondition::matchesChildren(DataGroup *group, BindingList &bindings)
{
	DataNode* node = group->getLeftMostChild();
	while (node)
	{
		if (matchesNode(node, bindings))
			return true;
		node = node->getRightSibling();
	}

	return false;
}

}
