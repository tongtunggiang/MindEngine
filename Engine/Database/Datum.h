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
 * @brief A Datum consists of an identifier and and value. In Database's tree structure,
 * a leaf node is a Datum.
 * @see DataNode
 * @see DataGroup
 */
template<class T>
class Datum : public DataNode
{

public:

	/**
	 * @brief Datum constructor.
	 * @param value the value that the Datum holds.
	 */
	Datum(T value) : DataNode(), value(value) {}

	/**
	 * @brief Datum constructor.
	 * @param identifier a string parameter.
	 * @param value the value that the Datum holds.
	 */
	Datum(const std::string& identifier, T value) : DataNode(identifier), value(value) {}

	/**
	 * @brief ~Datum destructor
	 */
	virtual ~Datum() {}

	/**
	 * @brief To change the value of the Datum.
	 * @param newValue The new value that is going to be assigned to the Datum.
	 */
	void setValue(T newValue) { value = newValue; }

	/**
	 * @brief To get the value of the Datum.
	 * @return The value that the datum is currently holding.
	 */
	T getValue() const { return value; }

	/**
	 * @brief Allows user to check whether this node is a Datum or not.
	 * @return true if this node is a Datum, otherwise returns false.
	 */
	bool isDatum() { return true;  }

private:

	/**
	 * @brief The value that the datum node holds.
	 */
	T value;

};

}

#endif // DATUM_H
