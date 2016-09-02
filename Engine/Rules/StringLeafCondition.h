#ifndef STRINGDATUMMATCH_H
#define STRINGDATUMMATCH_H

#include "DataNodeCondition.h"
#include "LeafDataNode.h"

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
 * @brief A struct provides mechanism for matching a leaf node with a test leaf node whose values
 * are string values.
 *
 * @see Condition
 * @see DataNodeCondition
 * @see NumberLeafCondition
 */
struct StringLeafCondition : public DataNodeCondition
{
	/**
	 * @brief The test value to match with value in the database.
	 */
    std::string matchValue;

	/**
	 * @brief Matches the given database node.
	 * @param node The database node to match on.
	 * @param bindings When part of the if clause matches a wild card, it is added to the bindings. This parameter is both input and output parameter.
	 * @return true if matches, else return false.
	 */
	virtual bool matchesNode(DataNode *node, BindingList &bindings);

	/**
	 * @brief Create a match object with the given name and match value.
	 * @param name The name of the node.
	 * @param matchValue The match value that is being matched.
	 */
	StringLeafCondition(NodeName name, std::string& matchValue);

	/**
	 * @brief Create a match object with the given name and match value.
	 * @param name The name of the node.
	 * @param matchValue The match value that is being matched.
	 */
	StringLeafCondition(const char* name, const char* matchValue);

};

}

#endif // !STRINGDATUMMATCH_H
