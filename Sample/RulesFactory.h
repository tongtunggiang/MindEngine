#ifndef RULESFACTORY_H
#define RULESFACTORY_H

#include <vector>

#include "tinyxml2.h"
#include "DataGroupMatch.h"
#include "NumberDatumMatch.h"
#include "StringDatumMatch.h"
#include "Rule.h"

class RulesFactory
{

public:

	static void processRulesFile(tinyxml2::XMLDocument* doc, std::vector<RuleBased::Rule*> &rules);

	static RuleBased::Rule* processRule(tinyxml2::XMLElement* xmlNode);

};

#endif // RULESFACTORY_H

