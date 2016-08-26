#ifndef MATCH_H
#define MATCH_H

#include "DataNode.h"
#include <vector>

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

/**
 * @brief The list used to store unique IDs of database nodes which match the condition.
 */
typedef std::vector<int> BindingList;

/**
 * @brief Provides the mechanism to match the data item from the rule with any item inside the database. This struct represents the condition part (aka. the if part) of the rule.
 */
struct Condition
{
	/**
	 * @brief Check the match on the database.
	 * @param database The database to match on.
	 * @param bindings When part of the if clause matches a wild card, it is added to the bindings. This parameter is both input and output parameter.
	 * @return true if matches, else returns false.
	 */
	virtual bool matches(DataNode* database, BindingList &bindings) = 0;
};

}

#endif // MATCH_H
