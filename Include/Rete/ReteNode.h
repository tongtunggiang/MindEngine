#ifndef RETENODE_H
#define RETENODE_H

#include "Condition.h"

#include <vector>

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

/**
 * @brief The base class of every node in Rete network. Every node
 * type (root node, pattern node, join node and rule node) is derived
 * from this type.
 */
class ReteNode
{

public:

	/**
	 * @brief Default constructor.
	 */
    ReteNode();

	/**
	 * @brief A join node is a node which performs Boolean operations upon the
	 * results passed down from pattern nodes. Another name for join nodes is
	 * beta nodes.
	 * @return true if this node is a join node.
	 */
	virtual bool isJoinNode() const;

	/**
	 * @brief A pattern node is a node which performs tests to the database
	 * (aka. working memory) and passes down all matched facts. Pattern nodes
	 * are also referred as alpha nodes.
	 * @return true if this node is a pattern node.
	 */
	virtual bool isPatternNode() const;

	/**
	 * @brief Rete network has an entry point called root node. The database
	 * will be passed into the network through this node.
	 * @return true if this node is a root node.
	 */
	virtual bool isRootNode() const;

	//virtual bool isRuleNode() const;

	/**
	 * @brief Add a successor node to current list.
	 * @param node The node is being added as the successor node of this node.
	 * @return true if the node is successfully added, otherwise return false.
	 */
    virtual bool addSuccessorNode(ReteNode* node) = 0;

	/**
	 * @brief Access to successor nodes of this Rete node.
	 * @return The array which holds the successor nodes of this Rete node.
	 */
	const std::vector<ReteNode*>& getSuccessorNodes();

protected:

    /**
     * @brief The array holds the nodes can be visited from current node.
     * Note that there is no opposite way, since the graph is directed acyclic.
     */
    std::vector<ReteNode*> successorNodes;

};

}

#endif // RETENODE_H
