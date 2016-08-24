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

// WARNING: ugly code, but I don't want to separate my recursive function
// Considering Abstract Factory design pattern for this
RuleBased::Condition * RulesFactory::createMatch(tinyxml2::XMLElement * xmlNode)
{	
	//----------
	// Create a boolean condition
	std::string id = std::string(xmlNode->Name());
	if (id == "and")
	{
		RuleBased::Condition* one = createMatch(xmlNode->FirstChildElement());
		RuleBased::Condition* two = createMatch(xmlNode->FirstChildElement()->NextSiblingElement());

		RuleBased::AndCondition* condition = new RuleBased::AndCondition(one, two);
		return condition;
	}
	else if (id == "or")
	{
		RuleBased::Condition* one = createMatch(xmlNode->FirstChildElement());
		RuleBased::Condition* two = createMatch(xmlNode->FirstChildElement()->NextSiblingElement());

		RuleBased::OrCondition* match = new RuleBased::OrCondition(one, two);
		return match;
	}
	else if (id == "not")
	{
		RuleBased::Condition* childMatch = createMatch(xmlNode->FirstChildElement());
		RuleBased::NotCondition* match = new RuleBased::NotCondition(childMatch);
		return match;
	}

	//----------
	// Create a data group condition
	if (xmlNode->FirstChildElement() != NULL)
	{
		std::cout << "Create a group condition, id: " << xmlNode->Name() << std::endl;
		RuleBased::DataGroupCondition* groupCondition = new RuleBased::DataGroupCondition();
		groupCondition->name = std::string(xmlNode->Name());
		groupCondition->leftMostChild = (RuleBased::DataGroupCondition*)createMatch(xmlNode->FirstChildElement());
		
		tinyxml2::XMLElement* xmlSibling = xmlNode->FirstChildElement()->NextSiblingElement();
		RuleBased::DataNodeCondition* sibling = groupCondition->leftMostChild->rightSibling;
		while (xmlSibling != NULL)
		{
			sibling = (RuleBased::DataNodeCondition*)createMatch(xmlSibling);
			xmlSibling = xmlSibling->NextSiblingElement();
			sibling = sibling->rightSibling;
		}

		return groupCondition;
	}

	//----------
	// Create a datum condition (based on name)
	if (id == "health" || id == "ammo") // Integer datum condition
	{
		std::cout << "Create an int condition, id: " << xmlNode->Name() << std::endl;
		int min, max;
		std::string valueStr = xmlNode->GetText();
		getMinMaxValueFromString(valueStr, min, max);
		RuleBased::IntegerLeafCondition* leafCondition = new RuleBased::IntegerLeafCondition(id, min, max);
		leafCondition->rightSibling = NULL;
		return leafCondition;
	}
	else if (id == "weapon" || id == "job") // String datum condition
	{
		std::cout << "Create a string condition, id: " << xmlNode->Name() << std::endl;
		std::string value = std::string(xmlNode->GetText());
		RuleBased::StringLeafCondition* leafCondition = new RuleBased::StringLeafCondition(id, value);
		leafCondition->rightSibling = NULL;
		return leafCondition;
	}

	return NULL;
}

void RulesFactory::getMinMaxValueFromString(std::string & str, int & min, int & max)
{
	// Extract min and max value from the string
	// Pattern of min-max string: <minvalue>-<maxvalue>
	// Example: 0-50
	int minusIndex;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '-')
		{
			minusIndex = i;
			break;
		}
	}

	int minStrLength = minusIndex;
	int maxStrLength = str.length() - minStrLength - 1;

	std::string minStr = str.substr(0, minStrLength);
	std::string maxStr = str.substr(minusIndex + 1, maxStrLength);

	min = std::stoi(minStr);
	max = std::stoi(maxStr);

	std::cout << str << ": " << min << ", " << max << std::endl;
}
