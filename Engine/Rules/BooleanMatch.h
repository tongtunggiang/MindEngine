#ifndef BOOLEANMATCH_H
#define BOOLEANMATCH_H

#include "Match.h"

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
struct AndMatch : public Match
{
	/**
	 * @brief Two match object that is going to be applied the AND operator.
	 */
	Match* subMatches[2];

	/**
	 * @brief Create an and-match object given two sub matches.
	 */
	AndMatch(Match *one, Match* two);

	/**
	 * @brief Matches the given database by trying its to sub-matches in turn.
	 * @return If either of two sub-matches return false, then this method returns false, otherwise returns true.
	 */
	virtual bool matches(DataNode* database, BindingList &bindings);

};

/**
* @brief Provide mechanism to match two match objects with OR boolean operator.
*/
struct OrMatch : public Match
{
	/**
	 * @brief Two match object that is going to be applied the OR operator.
	 */
	Match* subMatches[2];

	/**
	 * @brief Create an or-match object given two sub matches.
	 */
	OrMatch(Match *one, Match* two);

	/**
	 * @brief Matches the given database by trying its to sub-matches in turn.
	 * @return If either of two sub-matches return false, then this method returns false, otherwise returns true.
	 */
	virtual bool matches(DataNode* database, BindingList &bindings);
};

/**
* @brief The match which matches negatively to its child.
*/
struct NotMatch : public Match
{
	/**
	 * @brief The child match: if this match succeeds, then this instance fails, and vice versa.
	 */
	Match* match;

	/**
	 * @brief Create a not-match object given the child match.
	 */
	NotMatch(Match* match);

	/**
	 * @brief Matches the given database.
	 * @return true if the child match is not matches, otherwise returns false.
	 */
	virtual bool matches(DataNode* database, BindingList &bindings);
};

}

#endif