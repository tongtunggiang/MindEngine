#ifndef MATCH_H
#define MATCH_H

#include "DataNode.h"

/**
 * @brief Contains the implementation of rules as well as the mechanism to match the rules
 * and the data in the database.
 */
namespace Rules
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
	virtual bool matches(const Database::DataNode* database, void *bindings) = 0;
};

}

#endif // MATCH_H
