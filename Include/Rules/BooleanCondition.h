#ifndef BOOLEANMATCH_H
#define BOOLEANMATCH_H

#include "Condition.h"

/**
* @brief Contains classes to represent Rule-based system's database,
* which stores knowledge available to the AI agent as well as the
* implementation of rules and the mechanism to match the rules
* and the data in the database.
*/
namespace RuleBased
{

/**
 * @brief Provide mechanism to match two match objects with AND boolean operator.
 */
struct AndCondition : public Condition
{
	/**
	 * @brief Two match object that is going to be applied the AND operator.
	 */
	Condition* subMatches[2];

	/**
	 * @brief Create an and-match object given two sub matches.
	 */
	AndCondition(Condition *one, Condition* two);

	/**
	 * @brief Matches the given database by trying its to sub-matches in turn.
	 * @return If either of two sub-matches return false, then this method returns false, otherwise returns true.
	 */
    virtual bool matches(DataNode* database);

};

/**
* @brief Provide mechanism to match two match objects with OR boolean operator.
*/
struct OrCondition : public Condition
{
	/**
	 * @brief Two match object that is going to be applied the OR operator.
	 */
	Condition* subMatches[2];

	/**
	 * @brief Create an or-match object given two sub matches.
	 */
	OrCondition(Condition *one, Condition* two);

	/**
	 * @brief Matches the given database by trying its to sub-matches in turn.
	 * @return If either of two sub-matches return false, then this method returns false, otherwise returns true.
	 */
    virtual bool matches(DataNode* database);
};

/**
* @brief The match which matches negatively to its child.
*/
struct NotCondition : public Condition
{
	/**
	 * @brief The child match: if this match succeeds, then this instance fails, and vice versa.
	 */
	Condition* match;

	/**
	 * @brief Create a not-match object given the child match.
	 */
	NotCondition(Condition* match);

	/**
	 * @brief Matches the given database.
	 * @return true if the child match is not matches, otherwise returns false.
	 */
    virtual bool matches(DataNode* database);
};

}

#endif
