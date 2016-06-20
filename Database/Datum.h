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
class Datum
{

public:

	/**
	 * @brief Datum default constructor
	 */
	Datum();

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
