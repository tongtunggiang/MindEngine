#ifndef JOINNODE_H
#define JOINNODE_H

#include "ReteNode.h"

/**
* @brief Contains classes to represent Rule-based system's database,
* which stores knowledge available to the AI agent as well as the
* implementation of rules and the mechanism to match the rules
* and the data in the database.
*/
namespace RuleBased
{

/**
 * @brief Represents the type of join nodes.
 */
enum struct BooleanType
{
	AND,
	OR,
	NOT
};

/**
 * @brief Join nodes are responsible for matching two conditions and
 * filtering conflict facts (if there are any) before passing them to
 * terminal nodes. They receive input from upper level, the pattern nodes.
 * @see PatternNode
 */
class JoinNode : public ReteNode
{

public:

	/**
	 * @brief Creates a join node with type provided.
	 * @param booleanTypeName The name of the boolean type.
	 */
	JoinNode(const std::string& booleanTypeName);

	/**
	 * @return true if this node is a join node.
	 */
	virtual bool isJoinNode() const;

	/**
	 * @brief Add a successor node to current list. Join nodes accept any node
	 * type (except root node) to be their successors.
	 * @param node The node is being added as the successor node of this node.
	 * @return true if the node is successfully added, otherwise return false.
	 */
	virtual bool addSuccessorNode(ReteNode* node);

private:

	/**
	 * @brief Default constructor, marked as private so that no one can use it.
	 */
	JoinNode();

	/**
	 * @brief Type of this join node: and, or, or not?
	 */
	BooleanType booleanType;

};

}

#endif // JOINNODE_H
