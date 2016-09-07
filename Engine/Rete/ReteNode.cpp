#include "ReteNode.h"

namespace RuleBased
{

ReteNode::ReteNode()
{
	// empty body
}

bool ReteNode::isJoinNode() const
{
	return false;
}

bool ReteNode::isPatternNode() const
{
	return false;
}

bool ReteNode::isRootNode() const
{
	return false;
}

const std::vector<ReteNode*>& ReteNode::getSuccessorNodes()
{
	return successorNodes;
}

//bool ReteNode::isRuleNode() const
//{
//	return false;
//}

}
