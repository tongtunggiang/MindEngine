#include "RulesFactory.h"
#include <iostream>

void RulesFactory::processRulesFile(tinyxml2::XMLDocument * doc, std::vector<RuleBased::Rule*>& rules)
{
	// Get all elements with tag 'rule'
	// This is the structure of Rules.xml
	// <rules>
	//     <rule>
	//         <if> </if>
	//         <action> </action>
	//     </rule>
	// </rules>
	tinyxml2::XMLElement* ruleElement = doc->FirstChildElement()->FirstChildElement();

	// Construct Rule object by those 'rule' elements
	while (ruleElement != NULL)
	{
		RuleBased::Rule* rule = processRule(ruleElement);
		rules.push_back(rule);
		ruleElement = ruleElement->NextSiblingElement();
	}
}

RuleBased::Rule * RulesFactory::processRule(tinyxml2::XMLElement * xmlNode)
{
	// Example of the structure of a 'rule' node:
	//		<if>
	//	        <weapon>Knife</weapon>
	//		</if>
	//		<action>Hit</action>
	RuleBased::Rule* result = new RuleBased::Rule();
	tinyxml2::XMLElement* ifClauseNode = xmlNode->FirstChildElement("if");
	tinyxml2::XMLElement* actionNode = xmlNode->FirstChildElement("action");

	std::cout << actionNode->GetText();

	if (std::string(ifClauseNode->FirstChildElement()->Name()) == "health")
	{
		std::cout << " (number) " << ifClauseNode->FirstChildElement()->Name() << " " << ifClauseNode->FirstChildElement()->GetText() << std::endl;

		RuleBased::IntegerDatumMatch* datumMach = new RuleBased::IntegerDatumMatch("health", 0, 20);
		result->ifClause = datumMach;
	}
	else
	{
		std::cout << " (string) " << ifClauseNode->FirstChildElement()->Name() << " " << ifClauseNode->FirstChildElement()->GetText() << std::endl;

		std::string id = std::string(ifClauseNode->FirstChildElement()->Name());
		std::string value = std::string(ifClauseNode->FirstChildElement()->GetText());
		RuleBased::StringDatumMatch* datumMatch = new RuleBased::StringDatumMatch(id, value);
		result->ifClause = datumMatch;
	}

	result->action = actionNode->GetText();
	return result;
}
