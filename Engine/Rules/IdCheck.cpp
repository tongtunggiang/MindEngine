#include "IdCheck.h"

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

bool IdCheck::isWildcard(IdType identifier)
{
	// A wildcard contains a question mark
	// For example: "?person" will match every name appeared in database like "Mark", "John",...
	std::size_t foundQuestionMark = identifier.find('?');

	// Found a question mark in identifier parameter
	if (foundQuestionMark != std::string::npos)
		return true;

	return false;
}

}
