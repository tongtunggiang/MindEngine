#ifndef DATACLASSES_H
#define DATACLASSES_H

#include "DataNode.h"
#include <map>
#include <string>

namespace RuleBased
{

/**
 * @brief Stores the data classes construct by the Data Class Factory.
 * @see DataClassFactory
 */
class DataClasses
{

public:

	/**
	 * @brief Default constructor.
	 */
	DataClasses();

public:

	/**
	 * @brief Add new class to current set.
	 * @param name The name of the class.
	 * @param newClass The actual class is to be added.
	 * @param overrideExisting If this flag is true, the existing class with same name will be removed to make room for new class. If the flag is false, this function will change nothing to the set of classes.
	 */
	void addNewClass(const std::string& name, DataNode* newClass, bool overrideExisting = false);

	/**
	 * @brief Check if the class with provided name inside the set of classes.
	 * @param name The name of the class that is wanted to be checked.
	 * @return A DataNode object if there is a class in the set with that name, otherwise return NULL.
	 */
	DataNode* enquireClass(const std::string& name);

private:

	/**
	 * @brief The set of created classes.
	 */
	std::map<std::string, DataNode*> classes;

};

}

#endif // DATACLASSES_H
