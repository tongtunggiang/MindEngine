#include <iostream>

#include "tinyxml2.h"

#include "DataGroup.h"
#include "Datum.h"

#include "DataGroupMatch.h"
#include "NumberDatumMatch.h"

using namespace RuleBased;

#define XML_FILE "Database.xml"

tinyxml2::XMLDocument* readXmlFile(std::string fileName);

DataNode* processNode(tinyxml2::XMLElement* xmlNode);

void traverseTree(DataNode* root);

int main()
{
	tinyxml2::XMLDocument* doc = readXmlFile(XML_FILE);

	DataNode* root = processNode(doc->FirstChildElement());

	std::cout << "Traverse the built tree:" << std::endl;
	traverseTree(root);
	return 0;
}

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
	std::cout << root->getIdentifier() << std::endl;
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
}

// Damn ugly code - luckily it's just a demo
DataNode* processNode(tinyxml2::XMLElement* xmlNode)
{
	if (xmlNode == NULL)
		return NULL;

	// If a xml node has a text, it must be a Datum
	if (xmlNode->GetText() != NULL)
	{
		std::string xmlNodeType = xmlNode->Name();
		if (xmlNodeType == "name" || xmlNodeType == "type")
		{
			Datum<std::string>* result = new Datum<std::string>(
				xmlNode->Name(),
				xmlNode->GetText());
			return result;
		}
		else if (xmlNodeType == "ammo" || xmlNodeType == "clips")
		{
			Datum<int>* result = new Datum<int>(
				xmlNode->Name(),
				std::stoi(std::string(xmlNode->GetText())));
			return result;
		}

		return new Datum<int>(
			xmlNode->Name(),
			0);
	}

	// Else, it is a data group
	DataGroup* result = new DataGroup(xmlNode->Name());

	result->setLeftMostChild(processNode(xmlNode->FirstChildElement()));

	if (xmlNode->FirstChildElement() != NULL)
	{
		tinyxml2::XMLElement* rightSibling = xmlNode->FirstChildElement()->NextSiblingElement();
		while (rightSibling != NULL)
		{
			result->getLeftMostChild()->setRightSibling(processNode(rightSibling));
			rightSibling = rightSibling->NextSiblingElement();
		}
	}

	return result;
}
