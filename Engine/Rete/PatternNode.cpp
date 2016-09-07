#include "PatternNode.h"

namespace RuleBased
{

PatternNode::PatternNode() : ReteNode()
{
    condition = NULL;
}


PatternNode::PatternNode(DataGroupCondition* condition, size_t hashCode)
	: condition(condition), hashCode(hashCode)
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

void PatternNode::match(DataNode *database)
{
    nodesToMatch.clear();
    findNodesToMatchInDatabase(database, nodesToMatch);

    outputBindings.clear();
    for (int i = 0; i < nodesToMatch.size(); i++)
    {
		// ATTENTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		BindingList fuck;
        if (condition->matches(nodesToMatch[i], fuck))
        {
            outputBindings.push_back(nodesToMatch[i]->getUniqueID());
        }
    }
}

void PatternNode::findNodesToMatchInDatabase(DataNode *database, std::vector<DataNode*> &outNodes)
{
    if (database == NULL)
        return;

    if (database->getName() == condition->name)
    {
        outNodes.push_back(database);
    }

    if (database->isGroup())
    {
        DataGroup* group = (DataGroup*)database;
        DataNode* node = group->getLeftMostChild();

        while (node != NULL)
        {
            findNodesToMatchInDatabase(node, outNodes);
            node = node->getRightSibling();
        }
    }
}

size_t PatternNode::getHashCode()
{
	return hashCode;
}

}
