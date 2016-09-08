#include "BooleanCondition.h"

namespace RuleBased
{

//---------
// AND
AndCondition::AndCondition(Condition * one, Condition * two)
{
	subMatches[0] = one;
	subMatches[1] = two;
}

bool RuleBased::AndCondition::matches(DataNode * database)
{
    return subMatches[0]->matches(database) &&
        subMatches[1]->matches(database);
}

//---------
// OR
OrCondition::OrCondition(Condition * one, Condition * two)
{
	subMatches[0] = one;
	subMatches[1] = two;
}

bool OrCondition::matches(DataNode * database)
{
    return subMatches[0]->matches(database) ||
        subMatches[1]->matches(database);
}

//---------
// NOT
NotCondition::NotCondition(Condition * match) : match(match)
{
}

bool NotCondition::matches(DataNode * database)
{
    return !match->matches(database);
}

}
