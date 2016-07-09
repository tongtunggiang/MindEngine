#include "DataGroupMatch.h"
#include "IdCheck.h"

namespace RuleBased
{

bool DataGroupMatch::matchesNode(const DataNode* node, void *bindings)
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

	DataNodeMatch* match = leftMostChild;
	while (match)
	{
		if (!match->matchesChildren(group, bindings))
			return false;
		match = match->rightSibling;
	}	

	/**
	 * @todo Need adding bindings mechanism here
	 */
	if (bindings && identifierIsWildcard)
	{
		// Add to the binding list.
	}

	return true;
}

}
