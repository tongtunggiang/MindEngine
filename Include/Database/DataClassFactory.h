#ifndef DATACLASSFACTORY_H
#define DATACLASSFACTORY_H

#include <string>

#include "DataGroup.h"
#include "LeafDataNode.h"
#include "tinyxml2.h"

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

/**
 * @brief The singleton class is responsible for creating prototypes of DataNode objects based on the Data Class XML file.
 */
class DataClassFactory
{

public:

    /**
     * @return The singleton instance of the factory.
     */
    static DataClassFactory* get();

    /**
     * @brief Traverse through the XML file and create data classes.
     * @param The provided XML file.
     */
    void processXMLFile(tinyxml2::XMLDocument* doc);

private:

    /**
     * @brief Private constructor.
     */
    DataClassFactory();

    DataNode* createDataClass(tinyxml2::XMLElement* element);
    bool isPrimitiveType(const std::string& type);
    DataGroup* createDataGroup(tinyxml2::XMLElement* element);

    template<typename T>
    LeafDataNode<T>* createLeafDataNode(const std::string& name, T value);

private:

    static DataClassFactory* instance;

};

//------
// Template instantiation
template<typename T>
LeafDataNode<T>* DataClassFactory::createLeafDataNode(const std::string& name, T value)
{
    return new LeafDataNode<T>(name, value);
}

template LeafDataNode<int>*
DataClassFactory::createLeafDataNode<int>(
        const std::string& name,
        int value);

template LeafDataNode<float>*
DataClassFactory::createLeafDataNode<float>(
        const std::string& name,
        float value);

template LeafDataNode<std::string>*
DataClassFactory::createLeafDataNode<std::string>(
        const std::string& name,
        std::string value);

template LeafDataNode<bool>*
DataClassFactory::createLeafDataNode<bool>(
        const std::string& name,
        bool value);

}

#endif // DATACLASSFACTORY_H
