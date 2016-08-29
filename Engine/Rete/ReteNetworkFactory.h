#ifndef RETENETWORKFACTORY_H
#define RETENETWORKFACTORY_H

#include "RootNode.h"
#include "PatternNode.h"
#include "JoinNode.h"

#include "DataGroupCondition.h"
#include "NumberLeafCondition.h"
#include "StringLeafCondition.h"

#include "tinyxml2.h"

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

	void processRuleNode(tinyxml2::XMLElement* xmlNode);

	RuleBased::ReteNode* processConditionNode(tinyxml2::XMLElement* conditionNode);

	RuleBased::JoinNode* createJoinNode(tinyxml2::XMLElement* conditionNode);

	RuleBased::PatternNode* createPatternNode(tinyxml2::XMLElement* conditionNode);

private:

    /**
     * @brief The root of the Rete network, in which the database will be passed for matching.
     */
    RootNode* networkRoot;

    /**
     * @brief Singleton variable of the factory.
     */
    static ReteNetworkFactory* factory;

};

}

#endif // RETENETWORKFACTORY_H
