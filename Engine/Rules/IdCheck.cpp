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
    // A wildcard contains a question mark at the beginning of the matching pattern
	// For example: "?person" will match every name appeared in database like "Mark", "John",...
    if (identifier[0] == '?')
        return true;

	return false;
}

}
