#ifndef PATTERNNODE_H
#define PATTERNNODE_H

#include "ReteNode.h"
#include "DataGroupCondition.h"

#include "tinyxml2.h"

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

/**
 * @brief Represents pattern nodes (aka. alpha nodes) of the Rete network.
 * The database will be passed into these pattern nodes which transfer the
 * matched facts to join nodes to perform Boolean operations.
 * @see ReteNode
 * @see JoinNode
 */
class PatternNode : public ReteNode
{

public:

	/**
	 * @brief Construct a pattern node with a condition;
	 * @param condition The condition that is associated with the pattern node.
	 */
	PatternNode(DataGroupCondition* condition);

	/**
	 * @brief A pattern node is a node which performs tests to the database
	 * (aka. working memory) and passes down all matched facts. Pattern nodes
	 * are also referred as alpha nodes.
	 * @return true if this node is a pattern node.
	 */
	virtual bool isPatternNode() const;

    /**
     * @brief Add a successor node to current list.
     * @param node The node is being added as the successor node of this node.
     * @return true of the node is successfully added, otherwise return false.
     */
    virtual bool addSuccessorNode(ReteNode *node);

private:

	/**
	* @brief Default constructor.
	*/
	PatternNode();

private:

    /**
     * @brief The condition associated with this pattern node.
     * The matching process would be performed upon this condition.
     * @see DataNodeCondition
     */
    DataNodeCondition* condition;

};

}

#endif // PATTERNNODE_H
