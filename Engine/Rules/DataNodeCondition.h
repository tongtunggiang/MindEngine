#ifndef DATANODEMATCH_H
#define DATANODEMATCH_H

#include "Condition.h"
#include "DataGroup.h"

#include <string>

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

/**
 * @brief A struct derived from Condition, it is responsible for matching a
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
 * @see Condition
 */
struct DataNodeCondition : public Condition
{
	/**
	 * @brief Default constructor.
	 */
	DataNodeCondition();

	/**
	 * @brief The right sibling of this node in match tree.
	 */
	DataNodeCondition* rightSibling;

	/**
	 * @brief Matches the given database by checking each element in the database against the matchesNode method.
	 * @param database The database node to match on.
	 * @param bindings When part of the if clause matches a wild card, it is added to the bindings. This parameter is both input and output parameter.
	 * @return true if matches, else returns false.
	 */
	virtual bool matches(DataNode *database, BindingList &bindings);

	/**
	 * @brief Matches all the children of the given group to see if any of them pass the matchesNode test.
	 * This is used in the implementation of the matches method to iterate through items in the database.
	 * @param group The group to match on.
	 * @param bindings When part of the if clause matches a wild card, it is added to the bindings. This parameter is both input and output parameter.
	 * @return true if matches, else return false.
	 */
	bool matchesChildren(DataGroup *group, BindingList &bindings);

	/**
	 * @brief Matches the data node from the database against the criteria in this match.
	 * @param node The database node to match on.
	 * @param bindings When part of the if clause matches a wild card, it is added to the bindings. This parameter is both input and output parameter.
	 * @return true if matches, else return false.
	 */
	virtual bool matchesNode(DataNode *node, BindingList &bindings) = 0;

};

}

#endif // DATANODEMATCH_H
