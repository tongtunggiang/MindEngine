#ifndef RULESFACTORY_H
#define RULESFACTORY_H

#include <vector>

#include "tinyxml2.h"
#include "DataGroupMatch.h"
#include "NumberDatumMatch.h"
#include "StringDatumMatch.h"
#include "BooleanMatch.h"
#include "Rule.h"

class RulesFactory
{

public:

	static void processRulesFile(tinyxml2::XMLDocument* doc, std::vector<RuleBased::Rule*> &rules);

	static RuleBased::Rule* processRule(tinyxml2::XMLElement* xmlNode);

	static RuleBased::Match* createMatch(tinyxml2::XMLElement* xmlNode);

	static void getMinMaxValueFromString(std::string &str, int &min, int &max);

};

#endif // RULESFACTORY_H

