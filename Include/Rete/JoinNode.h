#ifndef JOINNODE_H
#define JOINNODE_H

#include "ReteNode.h"
#include <map>
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
class JoinNode : public ReteNode, public IHashedReteNode
{

public:

	/**
	 * @brief Creates a join node with type provided.
	 * @param booleanTypeName The name of the boolean type.
	 */
	JoinNode(const std::string& booleanTypeName, size_t hashCode);

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

	/**
	 * @brief Add new input array to this join node.
	 * @param key The reference key to the input.
	 * @return true if the input is successfully added.
	 * @note If there are already two inputs in the list, you can no longer add more.
	 */
	bool addInput(size_t key);

	/**
	 * @brief Update the input array with key provided.
	 * @param key The reference key to the input.
	 * @param input The input array.
	 * @return true if the input is successfully updated.
	 */
    bool updateInput(size_t key, VariableBindings& input);

public:

	// Begin IHashedReteNode interface
	virtual size_t getHashCode();
	// End IHashedReteNode interface;

private:

	/**
	 * @brief Default constructor, marked as private so that no one can use it.
	 */
	JoinNode();

	/**
	 * @brief Type of this join node: and, or, or not?
	 */
	BooleanType booleanType;

	size_t hashCode;

	/**
	 * @brief The map holding two input arrays of this JoinNode object.
	 */
    std::map<size_t, VariableBindings> inputLists;

};

}

#endif // JOINNODE_H
