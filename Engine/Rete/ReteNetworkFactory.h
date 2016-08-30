#ifndef RETENETWORKFACTORY_H
#define RETENETWORKFACTORY_H

#include "RootNode.h"
#include "PatternNode.h"
#include "JoinNode.h"

#include "DataGroupCondition.h"
#include "NumberLeafCondition.h"
#include "StringLeafCondition.h"

#include "tinyxml2.h"

#include <sstream>

/**
 * @brief Contains classes to represent Rule-based system's database,
 * which stores knowledge available to the AI agent as well as the
 * implementation of rules and the mechanism to match the rules
 * and the data in the database.
 */
namespace RuleBased
{

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

template<typename T>
NumberLeafCondition<T>* ReteNetworkFactory::createNumberLeafCondition(tinyxml2::XMLElement* conditionNode)
{
	T min, max;
	getMinMaxValueFromString(conditionNode->GetText(), min, max);
	return NumberLeafCondition<T>(conditionNode->Name(), min, max);
}

template<typename T>
void ReteNetworkFactory::getMinMaxValueFromString(const char* str, T &min, T &max)
{
	std::istringstream(std::string(str));

	stream >> min;
	stream >> max;
}

}

#endif // RETENETWORKFACTORY_H
