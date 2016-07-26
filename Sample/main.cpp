#include <iostream>

#include "DataTreeFactory.h"
#include "RulesFactory.h"

using namespace RuleBased;

#define DATABASE_FILE "Database.xml"
#define RULES_FILE "Rules.xml"

// Function declarations
tinyxml2::XMLDocument* readXmlFile(std::string fileName);
void traverseTree(DataNode* root);

// Main function
int main()
{
	// Construct data tree
	tinyxml2::XMLDocument* doc = readXmlFile(DATABASE_FILE);

	DataGroup* root = (DataGroup*)DataTreeFactory::processDataNode(doc->FirstChildElement());

	std::cout << std::endl << "Traverse the built tree:" << std::endl;
	traverseTree(root);
	std::cout << std::endl << std::endl;

	// Create Rule objects
	delete doc;
	std::vector<Rule*> rules;
	doc = readXmlFile(RULES_FILE);
	RulesFactory::processRulesFile(doc, rules);
	std::cout << std::endl << std::endl;

	BindingList bindings;
	for (int i = 0; i < rules.size(); i++)
	{
		//DataNode* characterNode = root->getLeftMostChild();
		//bool ruleMatch = false;

		//std::cout << "Checking rule: " << rules[i]->action << "... ";
		//while (characterNode != NULL)
		//{
		//	if (rules[i]->ifClause == NULL)
		//		continue;

		//	if (rules[i]->ifClause->matches(characterNode, bindings))
		//	{
		//		ruleMatch = true;
		//		break;
		//	}

		//	characterNode = characterNode->getRightSibling();
		//}

		//if (ruleMatch)
		//	std::cout << "   -->> MATCH" << std::endl;
		//else
		//	std::cout << std::endl;

		if (rules[i]->ifClause->matches(root, bindings))
		{
			std::cout << "Rule has action " << rules[i]->action << "  >>>  MATCH!" << std::endl;
		}
		else
		{
			std::cout << "Rule has action " << rules[i]->action << std::endl;
		}
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