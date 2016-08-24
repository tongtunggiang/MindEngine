#ifndef MATCH_H
#define MATCH_H

#include "DataNode.h"
#include <map>

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

/**
* @brief The list of bound actions is simply a list of strings representing actions (for now).
* I use list of strings for output actions because 1/ the action should be freed from function
* signatures and 2/ the AI engine should only produce 'decisions', rather than carry out the
* actions - that is the job of the agent itself.
* @note The output actions list would be used to carry out actions later by the agent. The
* approach here is to find appropriate methods on the script files to execute.
*/
typedef std::map<std::string, DataNode*> BindingList;

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
