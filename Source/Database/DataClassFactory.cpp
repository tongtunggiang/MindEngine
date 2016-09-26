#include "DataClassFactory.h"
#include <string>
#include "DataGroup.h"
#include "LeafDataNode.h"

namespace RuleBased {

DataClassFactory* DataClassFactory::instance = NULL;

DataClassFactory::DataClassFactory()
{
}

DataClassFactory* DataClassFactory::get()
{
    if (instance == NULL)
    {
        instance = new DataClassFactory();
    }

    return instance;
}

void DataClassFactory::processXMLFile(tinyxml2::XMLDocument* doc)
{
    tinyxml2::XMLElement* classElement = doc
            ->FirstChildElement("classes")
            ->FirstChildElement("class");

    while (classElement != NULL)
    {
        createDataClass(classElement);
        classElement = classElement->NextSiblingElement();
    }
}

DataNode* DataClassFactory::createDataClass(tinyxml2::XMLElement* element)
{
    if (element == NULL)
        return NULL;

    std::string type = element->Attribute("type");
    if (isPrimitiveType(type))
    {
        std::string name = element->GetText();
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
