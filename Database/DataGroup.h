#ifndef DATAGROUP_H
#define DATAGROUP_H

#include "DataNode.h"

/**
 * @brief The Database namspace
 *
 * Contains classes to represent Rule-based system's Database,
 * which stores knowledge available to the AI agent
 */
namespace Database
{

/**
 * @brief The DataGroup class
 * Represents a non-leaf node, which contains children.
 * Its children can be any DataNode object: either another data group,
 * or a datum only.
 */
class DataGroup : public DataNode
{

public:

	/**
	 * @brief DataGroup default constructor
	 */
	DataGroup();

	/**
	 * @brief DataGroup constructor
	 * @param identifier a string parameter
	 * @param parent a DataNode pointer representing this node's parent in tree structure
	 * @param rightSibling a DataNode pointer representing this node's right sibling in tree
	 * @param leftMostChild a DataNode pointer representing this node's left most child in tree
	 */
	DataGroup(const std::string& identifier, const DataNode* parent, const DataNode* rightSibling, const DataNode* leftMostChild);

	/**
	 * @brief ~DataGroup destructor
	 */
	virtual ~DataGroup();

	/**
	 * @brief getLeftMostChild
	 * @return The left most child of this data group node
	 */
	const DataNode* getLeftMostChild();

private:

	/**
	 * @brief leftMostChild
	 * The left most child of this node in tree structure
	 */
	DataNode* leftMostChild;

};

}

#endif // DATAGROUP_H
