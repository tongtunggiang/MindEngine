#include "PatternNode.h"

namespace RuleBased
{

PatternNode::PatternNode() : ReteNode()
{
}

bool PatternNode::isPatternNode() const
{
	return true;
}

bool PatternNode::addSuccessorNode(ReteNode *node)
{
	if (node->isJoinNode())
	{
		successorNodes.push_back(node);
		return true;
	}

	return false;
}

}
