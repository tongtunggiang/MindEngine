#include "JoinNode.h"

namespace RuleBased
{

JoinNode::JoinNode(const std::string& booleanTypeName)
{
	if (booleanTypeName == "and")
	{
		booleanType = BooleanType::AND;
	}
	else if (booleanTypeName == "or")
	{
		booleanType = BooleanType::OR;
	}
	else if (booleanTypeName == "not")
	{
		booleanType = BooleanType::NOT;
	}
}

bool JoinNode::isJoinNode() const
{
	return true;
}

bool JoinNode::addSuccessorNode(ReteNode* node)
{
	if (!node->isRootNode())
	{
		successorNodes.push_back(node);
		return true;
	}

	return false;
}





// This method is totally useless :p
// Few blank lines above just for isolating it from useful ones.
JoinNode::JoinNode() : ReteNode()
{
}

}
