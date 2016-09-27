#include "DataClassFactory.h"
#include <string>
#include "DataGroup.h"
#include "LeafDataNode.h"
#include "StringUtilities.h"

namespace RuleBased
{

DataClassFactory::DataClassFactory()
{
	// empty body
}

DataClasses* DataClassFactory::createClassesFromXMLFile(tinyxml2::XMLDocument* doc)
{
	if (doc == NULL)
		return NULL;

    tinyxml2::XMLElement* classElement = doc
            ->FirstChildElement("classes")
            ->FirstChildElement("class");

	DataClasses* classes = new DataClasses();
    while (classElement != NULL)
    {
        DataNode* createdClass = createDataClass(classElement);
		std::string createdClassName = createdClass->getName();
		classes->addNewClass(createdClassName, createdClass);

        classElement = classElement->NextSiblingElement();
    }

	return classes;
}

DataNode* DataClassFactory::createDataClass(tinyxml2::XMLElement* element)
{
    if (element == NULL)
        return NULL;

    std::string type = element->Attribute("type");
    if (isPrimitiveType(type))
    {
        std::string name = element->GetText();
		StringUtilities::trimString(name);
        if (type == "int")
        {
            return createLeafDataNode<int>(name, 0);
        }
        if (type == "float")
        {
            return createLeafDataNode<float>(name, 0.0f);
        }
        if (type == "bool")
        {
            return createLeafDataNode<bool>(name, true);
        }
        if (type == "string")
        {
            return createLeafDataNode<std::string>(name, "");
        }
    }
    else
    {
        return createDataGroup(element);
    }

    return NULL;
}

DataGroup* DataClassFactory::createDataGroup(tinyxml2::XMLElement *element)
{
    std::string name = element->FirstChildElement("name")->GetText();
	StringUtilities::trimString(name);
    DataGroup* group = new DataGroup(name);

    tinyxml2::XMLElement* firstXMLChild = element->FirstChildElement("class");
    if (firstXMLChild != NULL)
    {
        group->setLeftMostChild(createDataClass(firstXMLChild));
        DataNode* sibling = group->getLeftMostChild()->getRightSibling();
        tinyxml2::XMLElement* xmlSibling = firstXMLChild->NextSiblingElement("class");
        while (xmlSibling != NULL)
        {
            sibling = createDataClass(xmlSibling);
            xmlSibling = xmlSibling->NextSiblingElement();
            sibling = sibling->getRightSibling();
        }
    }

    return group;
}

bool DataClassFactory::isPrimitiveType(const std::string& type)
{
    if (type == "int" || type == "float" ||
        type == "bool" || type == "string")
        return true;

    return false;
}

}
