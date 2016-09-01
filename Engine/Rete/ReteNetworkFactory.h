#ifndef RETENETWORKFACTORY_H
#define RETENETWORKFACTORY_H

#include "RootNode.h"
#include "PatternNode.h"
#include "JoinNode.h"

#include "DataGroupCondition.h"
#include "NumberLeafCondition.h"
#include "StringLeafCondition.h"

#include "tinyxml2.h"

#include <iostream>
#include <sstream>
#include <string>

#define LOG(x) (std::cout << x << std::endl)

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

/**
 * @brief Is responsible for constructing Rete network, with input is a XML document.
 */
class ReteNetworkFactory
{

public:

	/**
	 * @return Singleton instance of the factory.
	 */
	static ReteNetworkFactory* getFactoryInstance();

	/**
	 * @brief Parses in a XML document and converts it into Rete network.
	 * @param doc The XMLDocument type object which represents the XML file being parsed
	 */
    void processRulesFile(tinyxml2::XMLDocument* doc);

private:

	/**
	 * @brief Private constructor.
	 */
	ReteNetworkFactory();

private:

    /**
     * @brief The root of the Rete network, in which the database will be passed for matching.
     */
    RootNode* networkRoot;

    /**
     * @brief Singleton variable of the factory.
     */
    static ReteNetworkFactory* factory;

// Helper functions
private:

	void processRuleNode(tinyxml2::XMLElement* xmlNode);

	ReteNode* processConditionNode(tinyxml2::XMLElement* conditionNode);

	JoinNode* createJoinNode(tinyxml2::XMLElement* conditionNode);

	PatternNode* createPatternNode(tinyxml2::XMLElement* conditionNode);

	DataNodeCondition* createCondition(tinyxml2::XMLElement* conditionNode);

	DataGroupCondition* createDataGroupCondition(tinyxml2::XMLElement* conditionNode);

	StringLeafCondition* createStringLeafCondition(tinyxml2::XMLElement* conditionNode);

	template<typename T>
	NumberLeafCondition<T>* createNumberLeafCondition(tinyxml2::XMLElement* conditionNode);

	template<typename T>
	void getMinMaxValueFromString(const char* str, T &min, T &max);

};

//--------
// createNumberLeafCondition
template<typename T>
NumberLeafCondition<T>* ReteNetworkFactory::createNumberLeafCondition(tinyxml2::XMLElement* conditionNode)
{
	T min, max;
	getMinMaxValueFromString(conditionNode->GetText(), min, max);
	LOG("RETE:       Create a number leaf condition " + std::string(conditionNode->Name()));
	return new NumberLeafCondition<T>(conditionNode->Name(), min, max);
}

template NumberLeafCondition<int>* ReteNetworkFactory::createNumberLeafCondition<int>(tinyxml2::XMLElement* conditionNode);
template NumberLeafCondition<float>* ReteNetworkFactory::createNumberLeafCondition<float>(tinyxml2::XMLElement* conditionNode);

//--------
// getMinMaxValueFromString
template<typename T>
void ReteNetworkFactory::getMinMaxValueFromString(const char* str, T &min, T &max)
{
	std::string cppStr = (std::string(str));
	std::istringstream stream(cppStr);

	stream >> min;
	stream >> max;
}

template void ReteNetworkFactory::getMinMaxValueFromString<int>(
	const char* str, int &min, int &max);
template void ReteNetworkFactory::getMinMaxValueFromString<float>(
	const char* str, float &min, float &max);

}

#endif // RETENETWORKFACTORY_H
