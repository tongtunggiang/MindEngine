#ifndef STRINGDATUMMATCH_H
#define STRINGDATUMMATCH_H

#include "DataNodeMatch.h"
#include "Datum.h"

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
 * @brief A struct provides mechanism for matching two Datum whose values
 * is string values.
 *
 * @see Match
 * @see DataNodeMatch
 * @see NumberDatumMatch
 */
struct StringDatumMatch : public DataNodeMatch
{
	/**
	 * @brief The test value to match with value in the database.
	 */
	std::string matchValue;

	/**
	* @brief The identifier to match.
	*/
	IdType identifier;

	/**
	 * @brief Matches the given database node.
	 * @param node The database node to match on.
	 * @param bindings When part of the if clause matches a wild card, it is added to the bindings. This parameter is both input and output parameter.
	 * @return true if matches, else return false.
	 */
	virtual bool matchesNode(DataNode *node, BindingList &bindings);

	/**
	 * @brief Create a match object with the given identifier and match value.
	 */
	StringDatumMatch(IdType identifier, std::string& matchValue);

};

}

#endif // !STRINGDATUMMATCH_H
