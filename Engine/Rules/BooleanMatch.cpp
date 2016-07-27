#include "BooleanMatch.h"

namespace RuleBased
{

//---------
// AND
AndMatch::AndMatch(Match * one, Match * two)
{
	subMatches[0] = one;
	subMatches[1] = two;
}

bool RuleBased::AndMatch::matches(DataNode * database, BindingList & bindings)
{
	return subMatches[0]->matches(database, bindings) &&
		subMatches[1]->matches(database, bindings);
}

//---------
// OR
OrMatch::OrMatch(Match * one, Match * two)
{
	subMatches[0] = one;
	subMatches[1] = two;
}

bool OrMatch::matches(DataNode * database, BindingList & bindings)
{
	return subMatches[0]->matches(database, bindings) ||
		subMatches[1]->matches(database, bindings);
}

//---------
// NOT
NotMatch::NotMatch(Match * match) : match(match)
{
}

bool NotMatch::matches(DataNode * database, BindingList & bindings)
{
	return !match->matches(database, bindings);
}

}