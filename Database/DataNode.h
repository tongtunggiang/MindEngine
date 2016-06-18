#ifndef DATANODE_H
#define DATANODE_H

#include <string>

/**
 * @brief The Database namspace
 *
 * Contains classes to represent Rule-based system's Database,
 * which stores knowledge available to the AI agent
 */
namespace Database
{

/**
 * @brief The DataNode class
 * Base class of each node in the database tree. Since every node needs
 * an identifier, but non-leaf nodes contain their children, while leaf
 * nodes store values.
 */
class DataNode
{

public:

	/**
	 * @brief DataNode default constructor
	 */
	DataNode();

	/**
	 * @brief DataNode constructor
	 * @param identifier a string parameter
	 * @param parent a DataNode pointer representing this node's parent in tree structure
	 * @param rightSibling a DataNode pointer representing this node's right sibling in tree structure
	 */
	DataNode(const std::string& identifier, const DataNode* parent, const DataNode* rightSibling);

	/**
	 * @brief ~DataNode destructor
	 */
	virtual ~DataNode();


	/**
	 * @brief getIdentifier
	 * @return The identifier of this node
	 */
	const std::string& getIdentifier();

	/**
	 * @brief getParent
	 * @return The parent node of this node, or NULL if this node is the root of the tree
	 */
	const DataNode* getParent();

	/**
	 * @brief getRightSibling
	 * @return The right sibling node of this node, or NULL if this node is the right most child
	 */
	const DataNode* getRightSibling();

protected:

	/**
	 * @brief identifier
	 * Each item of data should be identified to know what the value means.
	 */
	std::string identifier;

	/**
	 * @brief parent
	 * The parent node of this node, or NULL if this node is the root of the tree
	 */
	DataNode* parent;

	/**
	 * @brief rightSibling
	 * The right sibling node of this node, or NULL if this node is the right most child
	 */
	DataNode* rightSibling;

};

}

#endif // DATANODE_H
