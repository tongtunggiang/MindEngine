#include <iostream>

#include "DataTreeFactory.h"
#include "RulesFactory.h"
#include "ReteNetworkFactory.h"

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
	RuleBased::ReteNetworkFactory::getFactoryInstance()->processRulesFile(doc);

	return 0;
}

// Function definition
tinyxml2::XMLDocument* readXmlFile(std::string fileName)
{
	//std::cout << "Loading XML file " << fileName << std::endl;
	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();
	doc->LoadFile(fileName.c_str());
	//std::cout << "XML file is successfully loaded" << std::endl;

	return doc;
}

void traverseTree(DataNode* root)
{
	if (root == NULL)
		return;
	std::cout << root->getName() << " ";

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
		NodeName rootID = root->getName();

		if (rootID == "ammo" || rootID == "clips" || rootID == "health")
		{
			LeafDataNode<int>* datum = (LeafDataNode<int>*)root;
			std::cout << datum->getValue() << " ";
		}
		else
		{
			LeafDataNode<std::string>* datum = (LeafDataNode<std::string>*)root;
			std::cout << datum->getValue() << " ";
		}
	}
}
