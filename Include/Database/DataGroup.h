#ifndef DATAGROUP_H
#define DATAGROUP_H

#include "DataNode.h"

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

/**
 * @brief Represents a non-leaf node, which contains children.
 * Its children can be any DataNode object: either another DataGroup,
 * or a Datum only.
 * @see DataNode
 * @see Datum
 */
class DataGroup : public DataNode
{

public:

	/**
	 * @brief DataGroup default constructor.
	 */
	DataGroup();

	/**
	 * @brief DataGroup constructor.
	 * @param name a string parameter.
	 * @param leftMostChild a DataNode pointer representing this node's left most child in tree.
	 */
	DataGroup(const std::string& name);

	/**
	 * @brief ~DataGroup destructor.
	 */
	virtual ~DataGroup();

	/**
	 * @brief Data nodes are put into a left-most child, right sibling tree. This function returns the pointer to the left most child of this node.
	 * @return The left most child of this data group node.
	 */
	DataNode* getLeftMostChild() const;

	/**
	 * @brief Data nodes are put into a left-most child, right sibling tree. This function returns the pointer to the right most child of this node.
	 * @return The right most child of this data group node.
	 */
	DataNode* getRightMostChild() const;

	virtual DataNode* clone();

	/**
	 *
	 */
	void setLeftMostChild(DataNode* child);

	/**
	 * @brief Allows user to check whether this node is a DataGroup or not.
	 * @return true if this node is a DataGroup, otherwise returns false.
	 */
	bool isGroup() const;
	
	/**
	 * @brief Checks whether the given data node can be cast in to a DataGroup.
	 * @return true if this node can be casted, otherwise returns false.
	 */
	static bool canCastToDataGroup(DataNode* node);

	/**
	 * @brief Casts the given DataNode to DataGroup.
	 * @return The casted group (or NULL if failed).
	 * @note Remember to check the possibiliy of casting the node, using check function.
	 * @see canCastToDataGroup
	 */
	static DataGroup* castToDataGroup(DataNode* node);

private:

	/**
	 * @brief The left most child of this node in tree structure.
	 */
	DataNode* leftMostChild;

};

}

#endif // DATAGROUP_H
