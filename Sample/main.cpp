#include <iostream>
#include <vector>

#include "tinyxml2.h"

#include "DataGroup.h"
#include "Datum.h"

#include "DataGroupMatch.h"
#include "NumberDatumMatch.h"
#include "StringDatumMatch.h"

#include "Rule.h"

using namespace RuleBased;

#define DATABASE_FILE "Database.xml"
#define RULES_FILE "Rules.xml"

// Function declarations
tinyxml2::XMLDocument* readXmlFile(std::string fileName);

DataNode* processDataNode(tinyxml2::XMLElement* xmlNode);

void traverseTree(DataNode* root);

Rule* processRule(tinyxml2::XMLElement* xmlNode);

void processRulesFile(tinyxml2::XMLDocument* doc, std::vector<Rule*> &rules);

// Main function
int main()
{
	// Construct data tree
	tinyxml2::XMLDocument* doc = readXmlFile(DATABASE_FILE);

	DataGroup* root = (DataGroup*)processDataNode(doc->FirstChildElement());

	std::cout << std::endl << "Traverse the built tree:" << std::endl;
	traverseTree(root);
	std::cout << std::endl << std::endl;

	// Create Rule objects
	delete doc;
	std::vector<Rule*> rules;
	doc = readXmlFile(RULES_FILE);
	processRulesFile(doc, rules);
	std::cout << std::endl << std::endl;

	BindingList bindings;
	for (int i = 0; i < rules.size(); i++)
	{
		DataNode* characterNode = root->getLeftMostChild();
		bool ruleMatch = false;

		std::cout << "Checking rule: " << rules[i]->action << "... ";
		while (characterNode != NULL)
		{
			if (rules[i]->ifClause == NULL)
				continue;

			if (rules[i]->ifClause->matches(characterNode, bindings))
			{
				ruleMatch = true;
				break;
			}

			characterNode = characterNode->getRightSibling();
		}

		if (ruleMatch)
			std::cout << "Match" << std::endl;
		else
			std::cout << "Not match" << std::endl;
	}

	return 0;
}

// Function definition
tinyxml2::XMLDocument* readXmlFile(std::string fileName)
{
	std::cout << "Loading XML file " << fileName << std::endl;
	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();
	doc->LoadFile(fileName.c_str());
	std::cout << "XML file is successfully loaded" << std::endl;

	return doc;
}

void processRulesFile(tinyxml2::XMLDocument* doc, std::vector<Rule*> &rules)
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
		Rule* rule = processRule(ruleElement);
		rules.push_back(rule);
		ruleElement = ruleElement->NextSiblingElement();
	}
}

Rule* processRule(tinyxml2::XMLElement* xmlNode)
{
	// Example of the structure of a 'rule' node:
	//		<if>
	//	        <weapon>Knife</weapon>
	//		</if>
	//		<action>Hit</action>
	Rule* result = new Rule();
	tinyxml2::XMLElement* ifClauseNode = xmlNode->FirstChildElement("if");
	tinyxml2::XMLElement* actionNode = xmlNode->FirstChildElement("action");

	std::cout << actionNode->GetText();

	if (std::string(ifClauseNode->FirstChildElement()->Name()) == "health")
	{
		std::cout << " (number) " << ifClauseNode->FirstChildElement()->Name() << " " << ifClauseNode->FirstChildElement()->GetText() << std::endl;

		IntegerDatumMatch* datumMach = new IntegerDatumMatch("health", 0, 20);
		result->ifClause = datumMach;
	}
	else
	{
		std::cout << " (string) " << ifClauseNode->FirstChildElement()->Name() << " " << ifClauseNode->FirstChildElement()->GetText() << std::endl;

		StringDatumMatch* datumMatch = new StringDatumMatch(
			std::string(ifClauseNode->FirstChildElement()->Name()),
			std::string(ifClauseNode->FirstChildElement()->GetText()));
		result->ifClause = datumMatch;
	}

	result->action = actionNode->GetText();
	return result;
}

void traverseTree(DataNode* root)
{
	if (root == NULL)
		return;
	std::cout << root->getIdentifier() << " ";

	if (root->isGroup())
	{
		DataGroup* rootGroup = (DataGroup*)root;
		traverseTree(rootGroup->getLeftMostChild());

		if (rootGroup->getLeftMostChild() != NULL)
		{
			DataNode* sibling = rootGroup->getLeftMostChild()->getRightSibling();
			while (sibling != NULL)
			{
				traverseTree(sibling);
				sibling = sibling->getRightSibling();
			}
		}
	}
	else
	{
		IdType rootID = root->getIdentifier();

		if (rootID == "ammo" || rootID == "clips" || rootID == "health")
		{
			Datum<int>* datum = (Datum<int>*)root;
			std::cout << datum->getValue() << " ";
		}
		else
		{
			Datum<std::string>* datum = (Datum<std::string>*)root;
			std::cout << datum->getValue() << " ";
		}
	}
}

// Damn ugly code - luckily it's just a demo
DataNode* processDataNode(tinyxml2::XMLElement* xmlNode)
{
	if (xmlNode == NULL)
		return NULL;
	// If a xml node has a text, it must be a Datum
	if (xmlNode->GetText() != NULL)
	{
		std::string xmlNodeType = xmlNode->Name();
		if (xmlNodeType == "ammo" || xmlNodeType == "clips" || xmlNodeType == "health")
		{
			Datum<int>* result = new Datum<int>(
				xmlNode->Name(),
				std::stoi(std::string(xmlNode->GetText())));
			return result;
		}
		else
		{
			Datum<std::string>* result = new Datum<std::string>(
				xmlNode->Name(),
				xmlNode->GetText());
			return result;
		}

		return new Datum<int>(
			xmlNode->Name(),
			0);
	}

	// Else, it is a data group
	DataGroup* result = new DataGroup(xmlNode->Name());

	result->setLeftMostChild(processDataNode(xmlNode->FirstChildElement()));

	if (xmlNode->FirstChildElement() != NULL)
	{
		tinyxml2::XMLElement* rightSibling = xmlNode->FirstChildElement()->NextSiblingElement();
		while (rightSibling != NULL)
		{
			result->getLeftMostChild()->setRightSibling(processDataNode(rightSibling));
			rightSibling = rightSibling->NextSiblingElement();
		}
	}

	return result;
}
