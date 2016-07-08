#include "DataGroupMatch.h"

namespace RuleBased
{

bool DataGroupMatch::matchesNode(const DataNode* node, void *bindings)
{
	if (!node->isGroup())
		return false;

	/**
	 * @todo Add check for wildcard identifier with strings.
	 */
	if (identifier != node->getIdentifier())
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
	 * @todo Add check for wildcards here.
	 */
	if (bindings)
	{
		// Add to the binding list.
	}

	return true;
}

}
