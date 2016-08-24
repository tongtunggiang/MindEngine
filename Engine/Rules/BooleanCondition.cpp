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

bool RuleBased::AndCondition::matches(DataNode * database, BindingList & bindings)
{
	return subMatches[0]->matches(database, bindings) &&
		subMatches[1]->matches(database, bindings);
}

//---------
// OR
OrCondition::OrCondition(Condition * one, Condition * two)
{
	subMatches[0] = one;
	subMatches[1] = two;
}

bool OrCondition::matches(DataNode * database, BindingList & bindings)
{
	return subMatches[0]->matches(database, bindings) ||
		subMatches[1]->matches(database, bindings);
}

//---------
// NOT
NotCondition::NotCondition(Condition * match) : match(match)
{
}

bool NotCondition::matches(DataNode * database, BindingList & bindings)
{
	return !match->matches(database, bindings);
}

}