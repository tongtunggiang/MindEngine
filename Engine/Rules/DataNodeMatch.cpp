#include "DataNodeMatch.h"

namespace RuleBased
{

bool DataNodeMatch::matches(const DataNode *database, void *bindings)
{
	return matchesChildren((const DataGroup*) database, bindings);
}

bool DataNodeMatch::matchesChildren(const DataGroup *group, void *bindings)
{
	const DataNode* node = group->getLeftMostChild();
	while (node)
	{
		if (matchesNode(node, bindings))
			return true;
		node = node->getRightSibling();
	}

	return false;
}

}
