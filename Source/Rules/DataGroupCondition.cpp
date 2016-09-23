#include "DataGroupCondition.h"
#include "IdCheck.h"

namespace RuleBased
{

bool DataGroupCondition::matchesNode(DataNode* node)
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
        if (!match->matchesChildren(group))
			return false;
		match = match->rightSibling;
    }

	return true;
}

}
