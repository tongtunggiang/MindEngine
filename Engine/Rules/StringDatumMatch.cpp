#include "StringDatumMatch.h"
#include "IdCheck.h"

#include <iostream>
#include <typeinfo>

namespace RuleBased
{

bool StringDatumMatch::matchesNode(DataNode * node, BindingList & bindings)
{
	//std::cout << "Test node: " << identifier << " against data item: " << node->getIdentifier() << std::endl;

	if (!node->isDatum())
		return false;

	bool idIsWildcard = IdCheck::isWildcard(identifier);
	if (!idIsWildcard &&
		identifier != node->getIdentifier())
		return false;

	Datum<std::string> *datum = (Datum<std::string>*)node;

	if (datum->getValue() == matchValue)
	{
		if (idIsWildcard)
		{
			bindings[identifier] = node;
		}
		return true;
	}

	return false;
}

StringDatumMatch::StringDatumMatch(IdType identifier, std::string & matchValue)
	: identifier(identifier), matchValue(matchValue)
{
}

}