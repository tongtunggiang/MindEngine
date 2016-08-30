#ifndef NUMBERDATUMMATCH_H
#define NUMBERDATUMMATCH_H

#include "DataNodeCondition.h"
#include "LeafDataNode.h"

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

/**
 * @brief A struct provides mechanism for matching two Leaf nodes whose values
 * is number values (int, float,...).
 *
 * It uses the range-based approach, since every number values in game is
 * limited in a specific range, for example: HP is from 0 to 100, ammo is
 * from 0 to 50, and so on. That means, the comparision operators greater
 * than, greater than or equal, equal, less than, less than or equal can
 * be combined into a single match struct.
 *
 * @note This struct acts not only as the mechanism of matching two number
 * Leaf nodes, it also is the example of how to implement your own type of matching
 * with other data structures.
 *
 * @see Condition
 * @see DataNodeCondition
 */
template<typename T>
struct NumberLeafCondition : public DataNodeCondition
{
	/**
	 * @brief The minimum value of the matching range (inclusive).
	 */
	T min;

	/**
	 * @brief The maximum value of the matching range (inclusive).
	 */
	T max;

	/**
	* @brief The name to match.
	*/
	NodeName name;

	/**
	 * @brief Matches the given database node.
	 * @param node The database node to match on.
	 * @param bindings When part of the if clause matches a wild card, it is added to the bindings. This parameter is both input and output parameter.
	 * @return true if matches, else return false.
	 */
	virtual bool matchesNode(DataNode *node, BindingList &bindings);

	/**
	 * @brief Create a match object with the given name and range.
	 * This range-based approach allows you to match a range with more flexibility. For example,
	 * if you want to check the HP of the agent is lower than 80, you just create a matching range
	 * of [0, 79] (since both limits are inclusive).
	 * @note Remember to have max value greater than or equal to the min value.
	 */
	NumberLeafCondition(NodeName name, T min, T max);

	/**
	 * @brief Create a match object with the given name and range.
	 * @note Remember to have max value greater than or equal to the min value.
	 */
	NumberLeafCondition(const char* name, T min, T max);
};

typedef NumberLeafCondition<int> IntegerLeafCondition;
typedef NumberLeafCondition<float> FloatLeafCondition;

}

#endif // NUMBERDATUMMATCH_H
