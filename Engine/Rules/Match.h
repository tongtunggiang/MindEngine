#ifndef MATCH_H
#define MATCH_H

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
 * @brief Provides the mechanism to match the data item from the rule with any item inside the database.
 */
struct Match
{
	/**
	 * @brief Check the match on the database.
	 * @param database The database to match on.
	 * @param bindings When part of the if clause matches a wild card, it is added to the bindings. This parameter is both input and output parameter.
	 * @return true if matches, else returns false.
	 */
	virtual bool matches(const DataNode* database, void *bindings) = 0;
};

/**
 * @brief Check if the given database item's identifier is a wildcard or not.
 * @see IdType
 * @return True if it is a wildcard.
 */
bool isWildcard(IdType identifier);
{
	// A wildcard contains a question mark
	// For example: ?person will match every name appeared in database like Mark, John,...
	std::size_t foundQuestionMark = identifier.find('?');

	// Found a question mark in identifier parameter
	if (foundQuestionMark != std::string::npos)
		return true;

	return false;
}

}

#endif // MATCH_H
