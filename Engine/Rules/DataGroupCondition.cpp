#include "DataGroupCondition.h"
#include "IdCheck.h"

namespace RuleBased
{

bool DataGroupCondition::matchesNode(DataNode* node, BindingList &bindings)
{
	if (!node->isGroup())
		return false;

	bool identifierIsWildcard = IdCheck::isWildcard(name);
	if (!identifierIsWildcard &&
		name != node->getName())
	{
		return false;
	}

	DataGroup* group = (DataGroup*) node;

	// Check the match of every children in test item
	DataNodeCondition* match = leftMostChild;
	while (match)
	{
		if (!match->matchesChildren(group, bindings))
			return false;
		match = match->rightSibling;
	}

	//if (bindings && identifierIsWildcard)
	//if (identifierIsWildcard)
	{
		// Add to the binding list.
		bindings.push_back(node->getUniqueID());
	}

	return true;
}

}
