#ifndef DATANODE_H
#define DATANODE_H

#include <string>

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

typedef std::string NodeName;

/**
 * @brief Currently set the type of the ID of data nodes as string.
 * @todo  Use name with strings may decrease performance with large systems due to string-matching operations. Will change this to integer or unsigned integer as soon as I find a way to match name with human-readable strings.
 */
//typedef std::string IdType;

/**
 * @brief Base class of each node in the database tree. Since every node needs
 * an name, but non-leaf nodes contain their children, while leaf
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
	 * @param name an ID parameter.
	 */
	DataNode(const NodeName& name);

	/**
	 * @brief ~DataNode destructor.
	 */
	virtual ~DataNode() = 0;


	/**
	 * @brief The data nodes have unique identifiers.
	 * @return The name of this node.
	 */
	NodeName getName() const;

	/**
	 * @brief Set new sibling for the current data node and keep the current right sibling as new right sibling's sibling.
	 * @param sibling The new right sibling of this DataNode object.
	 */
	void setRightSibling(DataNode* sibling);

	/**
	 * @brief Data nodes are put into a left-most child, right sibling tree. This function is used to get the sibling next to current node.
	 * @return The right sibling node of this node, or NULL if this node is the right most child.
	 */
	DataNode* getRightSibling() const;

	/**
	 * @brief Allows user to check whether this node is a DataGroup or not.
	 * @return true if this node is a DataGroup, otherwise returns false.
	 */
	virtual bool isGroup() const;

	/**
	 * @brief Allows user to check whether this node is a Leaf node or not.
	 * @return true if this node is a Datum, otherwise returns false.
	 */
	virtual bool isLeaf() const;

	/**
	 * @return The value of this node's unique ID.
	 */
	int getUniqueID() const;

    /**
     * @brief Find a node in a tree (identified by its root) which has same ID with provided one.
     * @param root The root of the data tree is being traversed.
     * @param id The desired ID of the data node.
     * @return The data node has desired ID, or NULL if can't find.
     */
    static DataNode* getNodeByID(DataNode* root, int id);

protected:

	/**
	 * @brief Each item of data should be identified to know what the value means.
	 */
	NodeName name;

	/**
	 * @brief The right sibling node of this node, or NULL if this node is the right most child.
	 */
	DataNode* rightSibling;

	/**
	 * @brief The unique ID of the node.
	 */
	int id;

private:

	static int staticID;

	void createUniqueID();

};

}

#endif // DATANODE_H
