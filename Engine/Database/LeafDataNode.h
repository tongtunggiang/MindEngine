#ifndef DATUM_H
#define DATUM_H

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
 * @brief A Leaf node consists of an name and and value.
 * @see DataNode
 * @see DataGroup
 */
template<class T>
class LeafDataNode : public DataNode
{

public:

	/**
	 * @brief Leaf node constructor.
	 * @param value the value that the Leaf node holds.
	 */
	LeafDataNode(T value) : DataNode(), value(value) {}

	/**
	 * @brief Leaf node constructor.
	 * @param name a string parameter.
	 * @param value the value that the Leaf node holds.
	 */
	LeafDataNode(const std::string& name, T value) : DataNode(name), value(value) {}

	/**
	 * @brief ~Leaf node destructor
	 */
	virtual ~LeafDataNode() {}

	/**
	 * @brief To change the value of the Leaf node.
	 * @param newValue The new value that is going to be assigned to the Leaf node.
	 */
	void setValue(T newValue) { value = newValue; }

	/**
	 * @brief To get the value of the Leaf node.
	 * @return The value that the Leaf node is currently holding.
	 */
	T getValue() const { return value; }

	/**
	 * @brief Allows user to check whether this node is a Leaf node or not.
	 * @return true if this node is a Leaf node, otherwise returns false.
	 */
	bool isLeaf() const { return true;  }

private:

	/**
	 * @brief The value that the Leaf node holds.
	 */
	T value;

};

}

#endif // DATUM_H
