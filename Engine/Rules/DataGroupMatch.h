#ifndef DATAGROUPMATCH_H
#define DATAGROUPMATCH_H

#include "DataNodeMatch.h"

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
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
	IdType identifier;

	/**
	 * @brief The first sub-match in this group.
	 */
	DataNodeMatch* leftMostChild;

	/**
	 * @brief Tries to match the given data node from the database against the criteria.
	 * Method used: a recursive matching algorithm that travels down the given node, trying to match it against the structure of this match and its children.
	 * @param node The database node to match on.
	 * @param bindings When part of the if clause matches a wild card, it is added to the bindings. This parameter is both input and output parameter.
	 * @return true if matches, otherwise return false.
	 */
	virtual bool matchesNode(const DataNode* node, void *bindings);

};

}

#endif // DATAGROUPMATCH_H
