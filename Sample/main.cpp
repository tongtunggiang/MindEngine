#include <iostream>

#include "DataTreeFactory.h"
#include "RulesFactory.h"
#include "ReteNetworkFactory.h"
#include "DataClassFactory.h"

using namespace RuleBased;

#define DATABASE_FILE "Database.xml"
#define RULES_FILE "Rules.xml"
#define CLASS_FILE "DatabaseClasses.xml"

// Function declarations
tinyxml2::XMLDocument* readXmlFile(std::string fileName);
void traverseTree(DataNode* root);

// Main function
int main()
{
    tinyxml2::XMLDocument* doc = readXmlFile(CLASS_FILE);
    DataClassFactory* factory = new DataClassFactory();
	DataClasses* classes = factory->createClassesFromXMLFile(doc);
	if (classes->enquireClass("character"))
	{
		std::cout << "Boo";
	}

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
