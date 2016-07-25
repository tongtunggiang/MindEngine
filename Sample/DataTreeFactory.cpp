#include "DataTreeFactory.h"

RuleBased::DataNode * DataTreeFactory::processDataNode(tinyxml2::XMLElement * xmlNode)
{
	if (xmlNode == NULL)
		return NULL;
	// If a xml node has a text, it must be a Datum
	if (xmlNode->GetText() != NULL)
	{
		std::string xmlNodeType = xmlNode->Name();
		if (xmlNodeType == "ammo" || xmlNodeType == "clips" || xmlNodeType == "health")
		{
			RuleBased::Datum<int>* result = new RuleBased::Datum<int>(
				xmlNode->Name(),
				std::stoi(std::string(xmlNode->GetText())));
			return result;
		}
		else
		{
			RuleBased::Datum<std::string>* result = new RuleBased::Datum<std::string>(
				xmlNode->Name(),
				xmlNode->GetText());
			return result;
		}

		return new RuleBased::Datum<int>(
			xmlNode->Name(),
			0);
	}

	// Else, it is a data group
	RuleBased::DataGroup* result = new RuleBased::DataGroup(xmlNode->Name());

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
