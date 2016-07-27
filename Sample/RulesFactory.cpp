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
	//			<character>
	//				<weapon>Knife</weapon>
	//			</character>
	//		</if>
	//		<action>Hit</action>
	RuleBased::Rule* result = new RuleBased::Rule();
	tinyxml2::XMLElement* ifClauseNode = xmlNode->FirstChildElement("if");
	tinyxml2::XMLElement* actionNode = xmlNode->FirstChildElement("action");

	result->ifClause = createMatch(ifClauseNode->FirstChildElement());
	result->action = actionNode->GetText();
	return result;
}

RuleBased::Match * RulesFactory::createMatch(tinyxml2::XMLElement * xmlNode)
{
	// Create a data group match
	if (xmlNode->FirstChildElement() != NULL)
	{
		std::cout << "Create a group match, id: " << xmlNode->Name() << std::endl;
		RuleBased::DataGroupMatch* groupMatch = new RuleBased::DataGroupMatch();
		groupMatch->identifier = std::string(xmlNode->Name());
		groupMatch->leftMostChild = (RuleBased::DataNodeMatch*)createMatch(xmlNode->FirstChildElement());
		
		tinyxml2::XMLElement* xmlSibling = xmlNode->FirstChildElement()->NextSiblingElement();
		RuleBased::DataNodeMatch* sibling = groupMatch->leftMostChild->rightSibling;
		while (xmlSibling != NULL)
		{
			sibling = (RuleBased::DataNodeMatch*)createMatch(xmlSibling);
			xmlSibling = xmlSibling->NextSiblingElement();
			sibling = sibling->rightSibling;
		}

		return groupMatch;
	}

	// Create a datum match (based on identifier)
	std::string id = std::string(xmlNode->Name());
	if (id == "health") // Integer datum match
	{
		std::cout << "Create an int match, id: " << xmlNode->Name() << std::endl;
		RuleBased::IntegerDatumMatch* datumMatch = new RuleBased::IntegerDatumMatch("health", 0, 20); // fix later
		datumMatch->rightSibling = NULL;
		return datumMatch;
	}
	else if (id == "weapon" || id == "job") // String datum match
	{
		std::cout << "Create a string match, id: " << xmlNode->Name() << std::endl;
		std::string value = std::string(xmlNode->GetText());
		RuleBased::StringDatumMatch* datumMatch = new RuleBased::StringDatumMatch(id, value);
		datumMatch->rightSibling = NULL;
		return datumMatch;
	}

	return NULL;
}
