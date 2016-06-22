#include "DataNodeMatch.h"

namespace Rules
{

bool DataNodeMatch::matches(const Database::DataNode *database, void *bindings)
{
	return matchesChildren((const Database::DataGroup*) database, bindings);
}

bool DataNodeMatch::matchesChildren(const Database::DataGroup *group, void *bindings)
{
	const Database::DataNode* node = group->getLeftMostChild();
	while (node)
	{
		if (matchesNode(node, bindings))
			return true;
		node = node->getRightSibling();
	}

	return false;
}

}
