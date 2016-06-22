#ifndef DATAGROUPMATCH_H
#define DATAGROUPMATCH_H

#include "DataNodeMatch.h"

/**
 * @brief Contains the implementation of rules as well as the mechanism to match the rules
 * and the data in the database.
 */
namespace Rules
{

/**
 * @brief Matches a group of data in the database.
 * This is done by building a match data structure that mirrors the data structure that is being searched for in the database.
 */
struct DataGroupMatch
{

	/**
	 * @brief The identifier to match.
	 */
	Database::IdType identifier;

	/**
	 * @brief The first sub-match in this group.
	 */
	DataNodeMatch* leftMostChild;

	/**
	 * @brief Tries to match the given data node from the database against the criteria.
	 * Method used: a recursive matching algorithm that travels down the given node, trying to match it against the structure of this match and its children.
	 * @param node The database to match on.
	 * @param bindings When part of the if clause matches a wild card, it is added to the bindings. This parameter is both input and output parameter.
	 * @return true if matches, otherwise return false.
	 */
	virtual bool matchesNode(const Database::DataNode* node, void *bindings);

};

}

#endif // DATAGROUPMATCH_H
