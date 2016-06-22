#ifndef DATAGROUP_H
#define DATAGROUP_H

#include "DataNode.h"

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent.
 */
namespace Database
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
	 * @param identifier a string parameter.
	 * @param rightSibling a DataNode pointer representing this node's right sibling in tree.
	 * @param leftMostChild a DataNode pointer representing this node's left most child in tree.
	 */
	DataGroup(const std::string& identifier, DataNode *rightSibling, DataNode *leftMostChild);

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
	 * @brief Allows user to check whether this node is a DataGroup or not.
	 * @return true if this node is a DataGroup, otherwise returns false.
	 */
	bool isGroup();

private:

	/**
	 * @brief The left most child of this node in tree structure.
	 */
	DataNode* leftMostChild;

};

}

#endif // DATAGROUP_H
