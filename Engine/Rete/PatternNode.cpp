#include "PatternNode.h"

namespace RuleBased
{

PatternNode::PatternNode() : ReteNode()
{
    condition = NULL;
}


PatternNode::PatternNode(DataGroupCondition* condition) : condition(condition)
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
    outputBindings.clear();

	std::vector<DataNode*> nodes;
	findNodesToMatchInDatabase(database, nodes);
	for (int i = 0; i < nodes.size(); i++)
	{
		condition->matches(nodes[i], outputBindings);
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

}
