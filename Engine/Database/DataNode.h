#ifndef DATANODE_H
#define DATANODE_H

#include <string>

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent.
 */
namespace Database
{

/**
 * @brief Base class of each node in the database tree. Since every node needs
 * an identifier, but non-leaf nodes contain their children, while leaf
 * nodes store values.
 * @see DataGroup
 * @see Datum
 */
class DataNode
{

public:

	/**
	 * @brief DataNode default constructor.
	 */
	DataNode();

	/**
	 * @brief DataNode constructor with parameters.
	 * @param identifier a string parameter.
	 * @param parent a DataNode pointer representing this node's parent in tree structure.
	 * @param rightSibling a DataNode pointer representing this node's right sibling in tree. structure
	 */
	DataNode(const std::string& identifier, DataNode *parent, DataNode *rightSibling);

	/**
	 * @brief ~DataNode destructor.
	 */
	virtual ~DataNode();


	/**
	 * @brief The data nodes have unique identifiers.
	 * @return The identifier of this node.
	 */
	const std::string& getIdentifier();

	/**
	 * @brief Data nodes are put into a left-most child, right sibling tree. This function returns the pointer to the parent of this node.
	 * @return The parent node of this node, or NULL if this node is the root of the tree.
	 */
	const DataNode* getParent();

	/**
	 * @brief Data nodes are put into a left-most child, right sibling tree. This function is used to get the sibling next to current node.
	 * @return The right sibling node of this node, or NULL if this node is the right most child.
	 */
	const DataNode* getRightSibling();

	/**
	 * @brief Allows user to check whether this node is a DataGroup or not.
	 * @return true if this node is a DataGroup, otherwise returns false.
	 */
	virtual bool isGroup();

	/**
	 * @brief Allows user to check whether this node is a Datum or not.
	 * @return true if this node is a Datum, otherwise returns false.
	 */
	virtual bool isDatum();

protected:

	/**
	 * @brief Each item of data should be identified to know what the value means.
	 * @todo Use identifier with strings may decrease performance with large systems due to string-matching operations. Will change this to integer or unsigned integer as soon as I find a way to match identifier with human-readable strings.
	 */
	std::string identifier;

	/**
	 * @brief The parent node of this node, or NULL if this node is the root of the tree.
	 */
	DataNode* parent;

	/**
	 * @brief The right sibling node of this node, or NULL if this node is the right most child.
	 */
	DataNode* rightSibling;

};

}

#endif // DATANODE_H
