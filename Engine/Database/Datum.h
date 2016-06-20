#ifndef DATUM_H
#define DATUM_H

#include "DataNode.h"

/**
 * @brief The Database namespace
 *
 * Contains classes to represent Rule-based system's Database,
 * which stores knowledge available to the AI agent
 */
namespace Database
{

/**
 * @brief The Datum class
 * A Datum consists of an identifier and and value. In Database's tree structure,
 * a leaf node is a Datum.
 * @see DataNode
 * @see DataGroup
 */
template<class T>
class Datum : public DataNode
{

public:

	/**
	 * @brief Datum constructor
	 * @param value the value that the Datum holds
	 */
	Datum(T value);

	/**
	 * @brief Datum constructor
	 * @param identifier a string parameter
	 * @param parent a DataNode pointer representing this node's parent in tree structure
	 * @param rightSibling a DataNode pointer representing this node's right sibling in tree
	 * @param value the value that the Datum holds
	 */
	Datum(const std::string& identifier, DataNode *parent, DataNode *rightSibling, T value);

	/**
	 * @brief ~Datum destructor
	 */
	virtual ~Datum();

	/**
	 * @brief setValue
	 * @param newValue The new value that is going to be assigned to the Datum
	 */
	void setValue(T newValue);

	/**
	 * @brief getValue
	 * @return The value that the datum is currently holding
	 */
	T getValue();

private:

	/**
	 * @brief value
	 * The value that the datum node holds
	 */
	T value;

};

}

#endif // DATUM_H
