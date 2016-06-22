#ifndef DATANODEMATCH_H
#define DATANODEMATCH_H

#include "Match.h"
#include "DataGroup.h"

/**
 * @brief Contains the implementation of rules as well as the mechanism to match the rules
 * and the data in the database.
 */
namespace Rules
{

/**
 * @brief A struct derived from Match, it is responsible for matching a
 * single DataNode in the database.
 *
 * Conceptually, the match class could match the whole database in
 * a single operation: it is only ever fed the whole database, so
 * it can do with that what it likes. However in practical, the vast
 * majority of matching requirements involve trying to find a single
 * item in the database. This struct's match method iterates through
 * the items in the database, and calls matchesNode on each one. Matches
 * items can be implemented in sub-classes to check if the item fulfils
 * the mtach criteria.
 *
 * Data node matches are arranged into tree, just like how data nodes
 * are.
 *
 * @see Match
 */
struct DataNodeMatch : public Match
{
	/**
	 * @brief The right sibling of this node in match tree.
	 */
	DataNodeMatch* rightSibling;

	/**
	 * @brief Matches the given database by checking each element in the database against the matchesNode method.
	 * @param database The database to match on.
	 * @param bindings When part of the if clause matches a wild card, it is added to the bindings. This parameter is both input and output parameter.
	 * @return true if matches, else returns false.
	 */
	virtual bool matches(const Database::DataNode *database, void *bindings);

	/**
	 * @brief Matches all the children of the given group to see if any of them pass the matchesNode test.
	 * This is used in the implementation of the matches method to iterate through items in the database.
	 * @param group The group to match on.
	 * @param bindings When part of the if clause matches a wild card, it is added to the bindings. This parameter is both input and output parameter.
	 * @return true if matches, else return false.
	 */
	bool matchesChildren(const Database::DataGroup *group, void *bindings);

	/**
	 * @brief Matches the data node from the database against the criteria in this match.
	 * @param node The database to match on.
	 * @param bindings When part of the if clause matches a wild card, it is added to the bindings. This parameter is both input and output parameter.
	 * @return true if matches, else return false.
	 */
	virtual bool matchesNode(const Database::DataNode *node, void *bindings) = 0;

};

}

#endif // DATANODEMATCH_H
