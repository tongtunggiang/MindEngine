#include "DataGroupMatch.h"
#include "IdCheck.h"

namespace RuleBased
{

bool DataGroupMatch::matchesNode(DataNode* node, BindingList &bindings)
{
	if (!node->isGroup())
		return false;

	bool identifierIsWildcard = IdCheck::isWildcard(identifier);
	if (!identifierIsWildcard &&
		identifier != node->getIdentifier())
	{
		return false;
	}

	DataGroup* group = (DataGroup*) node;

	// Check the match of every children in test item
	DataNodeMatch* match = leftMostChild;
	while (match)
	{
		if (!match->matchesChildren(group, bindings))
			return false;
		match = match->rightSibling;
	}

	//if (bindings && identifierIsWildcard)
	if (identifierIsWildcard)
	{
		// Add to the binding list.
		bindings[identifier] = node;
	}

	return true;
}

}
