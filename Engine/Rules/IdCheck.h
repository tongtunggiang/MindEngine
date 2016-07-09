#ifndef IDCHECK_H
#define IDCHECK_H

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
 * @brief Provides methods to check the IDs.
 */
class IdCheck
{

public:

	/**
	 * @brief Check if the given database item's identifier is a wildcard or not.
	 * @see IdType
	 * @return True if it is a wildcard.
	 */
	static bool isWildcard(IdType identifier);

};

}

#endif // IDCHECK_H
