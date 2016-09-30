#include "JoinNode.h"

namespace RuleBased
{

JoinNode::JoinNode(const std::string& booleanTypeName, size_t hashCode)
	: hashCode(hashCode)
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

bool JoinNode::addInput(size_t key)
{
	if (inputLists.size() >= 2)
		return false;

	inputLists[key] = BindingList();

	return true;
}

bool JoinNode::updateInput(size_t key, BindingList & input)
{
	if (!inputLists.count(key))
	{
		return false;
	}

	inputLists[key] = input;
	return true;
}

size_t JoinNode::getHashCode()
{
	return hashCode;
}





// This method is totally useless :p
// Few blank lines above just for isolating it from useful ones.
JoinNode::JoinNode() : ReteNode()
{
}

}
