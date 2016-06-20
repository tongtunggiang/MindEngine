#ifndef RULE_H
#define RULE_H

#include "Match.h"

/**
 * @brief Contains the implementation of rules as well as the mechanism to match the rules
 * and the data in the database.
 */
namespace Rules
{

/**
 * @brief Represent a rule in a Rule-based system. A rule has two components: an if clause is going to be used to match against the database and a function to perform any action required.
 */
class Rule
{

public:

	/**
	 * @brief Consist of a set of data items, in a similar format to those in the database.
	 */
	Match* ifClause;

	/**
	 * @brief The action is going to be carried out when the rule matches.
	 * @todo Examine the performance and reusability of using a method. If it is hard to expand, find a way to use a struct/class instead.
	 */
	virtual void action() = 0;

};

}

#endif // RULE_H
