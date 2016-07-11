#include "DataNodeMatch.h"

namespace RuleBased
{

bool DataNodeMatch::matches(DataNode *database, BindingList &bindings)
{
	return matchesChildren((DataGroup*) database, bindings);
}

bool DataNodeMatch::matchesChildren(DataGroup *group, BindingList &bindings)
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
