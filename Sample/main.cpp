#include <iostream>

#include "tinyxml2.h"

#include "DataGroup.h"
#include "Datum.h"

#include "DataGroupMatch.h"
#include "NumberDatumMatch.h"

using namespace RuleBased;

#define XML_FILE "Database.xml"

tinyxml2::XMLDocument* readXmlFile(std::string fileName);
DataNode* processNode(tinyxml2::XMLNode* xmlNode);

int main()
{
	tinyxml2::XMLDocument* doc = readXmlFile(XML_FILE);

	processNode(doc->FirstChild());

    return 0;
}

tinyxml2::XMLDocument* readXmlFile(std::string fileName)
{
	std::cout << "Loading XML file " << fileName << std::endl;
	tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();
	doc->LoadFile(fileName.c_str());
	std::cout << "XML file is successfully loaded" << fileName << std::endl;

	return doc;
}

DataNode* processNode(tinyxml2::XMLNode* xmlNode)
{
	if (xmlNode == NULL)
		return NULL;

	tinyxml2::XMLElement* element = xmlNode->ToElement();
	std::cout << element->Name() << " " << element->GetText() << std::endl;

	processNode(xmlNode->FirstChild());
	
	tinyxml2::XMLNode* rightSibling = xmlNode->NextSibling();
	while (rightSibling != NULL)
	{
		processNode(rightSibling);
		rightSibling = rightSibling->NextSibling();
	}

	return NULL;
}
