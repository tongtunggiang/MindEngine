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

/**
 * @brief Currently set the type of the ID of data nodes as string.
 * @todo  Use identifier with strings may decrease performance with large systems due to string-matching operations. Will change this to integer or unsigned integer as soon as I find a way to match identifier with human-readable strings.
 */
typedef std::string IdType;

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
	 * @param identifier an ID parameter.
	 */
	DataNode(const IdType& identifier);

	/**
	 * @brief ~DataNode destructor.
	 */
	virtual ~DataNode();


	/**
	 * @brief The data nodes have unique identifiers.
	 * @return The identifier of this node.
	 */
	IdType getIdentifier() const;

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
	 * @brief Allows user to check whether this node is a Datum or not.
	 * @return true if this node is a Datum, otherwise returns false.
	 */
	virtual bool isDatum() const;

protected:

	/**
	 * @brief Each item of data should be identified to know what the value means.
	 */
	IdType identifier;

	/**
	 * @brief The right sibling node of this node, or NULL if this node is the right most child.
	 */
	DataNode* rightSibling;

};

}

#endif // DATANODE_H
