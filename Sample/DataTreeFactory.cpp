#include "DataTreeFactory.h"
#include "DataClasses.h"
#include "DataGroup.h"
#include "LeafDataNode.h"

#include <iostream>

using namespace RuleBased;
using namespace tinyxml2;

DataNode* DataTreeFactory::process(XMLDocument* doc, DataClasses* classes)
{
	XMLElement* elem = getFirstNode(doc);

	DataGroup* database = new DataGroup("database");
	while (elem != NULL)
	{
		DataNode* child = processXMLElement(elem, classes);

		if (child != NULL)
		{
			if (database->getLeftMostChild() == NULL)
			{
				database->setLeftMostChild(child);
			}
			else
			{
				database->getRightMostChild()->setRightSibling(child);
			}
		}

		elem = elem->NextSiblingElement();
	}

	return database;
}

DataNode* DataTreeFactory::processXMLElement(XMLElement *element, DataClasses* classes)
{
	std::string elementName = element->Name();
	DataNode* prototype = classes->enquireClass(elementName);
	if (prototype == NULL)
		return NULL;

	DataNode* product = prototype->clone();
	updateValuesForDataNodeFromXML(element, product);
	return product;
}

void DataTreeFactory::updateValuesForDataNodeFromXML(XMLElement *element, DataNode *node)
{
	if (node == NULL)
		return;

	if (node->isGroup())
	{
		DataGroup* group = (DataGroup*)node;
		updateValuesForDataNodeFromXML(element->FirstChildElement(),
									   group->getLeftMostChild());
		if (group->getLeftMostChild() != NULL)
		{
			DataNode* sibling = group->getLeftMostChild()->getRightSibling();
			XMLElement* xmlSibling = element->FirstChildElement()->NextSiblingElement();
			while (sibling != NULL)
			{
				updateValuesForDataNodeFromXML(xmlSibling, sibling);
				sibling = sibling->getRightSibling();
				xmlSibling = xmlSibling->NextSiblingElement();
			}
		}
	}
	else
	{
		std::cout << "Value read from XML: " << element->Name() << "=" << element->GetText() << std::endl;

		std::string valueType = element->Attribute("type");
		if (valueType == "string")
		{
			LeafDataNode<std::string>* leaf = (LeafDataNode<std::string>*)node;
			leaf->setValue(std::string(element->GetText()));
		}
		else if (valueType == "int")
		{
			LeafDataNode<int>* leaf = (LeafDataNode<int>*)node;
			int value = std::stoi(element->GetText());
			leaf->setValue(value);
		}
		else if (valueType == "float")
		{
			LeafDataNode<float>* leaf = (LeafDataNode<float>*)node;
			float value = std::stof(element->GetText());
			leaf->setValue(value);
		}
		else if (valueType == "bool")
		{
			LeafDataNode<bool>* leaf = (LeafDataNode<bool>*)node;
			if (std::string(element->GetText()) == "true")
			{
				leaf->setValue(true);
			}
			else
			{
				leaf->setValue(false);
			}
		}
	}
}

XMLElement* DataTreeFactory::getFirstNode(XMLDocument *doc)
{
	return doc->FirstChildElement()->FirstChildElement();
}
