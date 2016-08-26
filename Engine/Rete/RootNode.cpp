#include "RootNode.h"

namespace RuleBased
{

RootNode::RootNode() : ReteNode()
{
}

bool RootNode::isRootNode() const
{
	return true;
}

bool RootNode::addSuccessorNode(ReteNode* node)
{
	if (node->isPatternNode())
	{
		successorNodes.push_back(node);
		return true;
	}

	return false;
}

}