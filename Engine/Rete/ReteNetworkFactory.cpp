#include "ReteNetworkFactory.h"
#include <string.h>

namespace RuleBased
{

ReteNetworkFactory* ReteNetworkFactory::factory = NULL;

ReteNetworkFactory::ReteNetworkFactory()
{
	networkRoot = new RootNode();
}

ReteNetworkFactory* ReteNetworkFactory::getFactoryInstance()
{
	if (factory == NULL)
	{
		factory = new ReteNetworkFactory;
	}

	return factory;
}

void ReteNetworkFactory::processRulesFile(tinyxml2::XMLDocument* doc)
{
	tinyxml2::XMLElement* ruleElement = doc
		->FirstChildElement("rules")
		->FirstChildElement("rule");

	// Traverse all rule elements in Rules.xml file
	// and extract conditions and actions associated
	// with the rules
	while (ruleElement != NULL)
	{
		processRuleNode(ruleElement);
		ruleElement = ruleElement->NextSiblingElement();
	}
}

void ReteNetworkFactory::processRuleNode(tinyxml2::XMLElement* ruleNode)
{
	// Example of the structure of a 'rule' node:
	//		<if>
	//			<character>
	//				<weapon>Knife</weapon>
	//			</character>
	//		</if>
	//		<action>Hit</action>
	tinyxml2::XMLElement* ifClauseNode = ruleNode->FirstChildElement("if");
	processConditionNode(ifClauseNode->FirstChildElement());

	tinyxml2::XMLElement* actionNode = ruleNode->FirstChildElement("action");
}

RuleBased::ReteNode* ReteNetworkFactory::processConditionNode(tinyxml2::XMLElement* conditionNode)
{
	std::string xmlNodeName = conditionNode->Name();
	
	// Create a join node
	if (xmlNodeName == "and" || xmlNodeName == "or" || xmlNodeName == "not")
	{
		return createJoinNode(conditionNode);
	}

	// Create a pattern node
	return createPatternNode(conditionNode);
}

RuleBased::JoinNode* ReteNetworkFactory::createJoinNode(tinyxml2::XMLElement* conditionNode)
{
	// The boolean operators are organized as operator trees, for example:
	//            AND
	//           /   \
	//         OR     C
	//        /  \
	//       A    B
	// represents the condition: (A or B) and C
	//
	// We will extract join nodes (represent boolean operators) and pattern nodes from if nodes.

	std::string xmlNodeName = conditionNode->Name();

	RuleBased::JoinNode* result = new RuleBased::JoinNode(xmlNodeName);
	if (xmlNodeName == "and" || xmlNodeName == "or" || xmlNodeName == "not")
	{
		// Binary boolean operators
		tinyxml2::XMLElement* leftChild = conditionNode->FirstChildElement();
		tinyxml2::XMLElement* rightChild = leftChild->NextSiblingElement();

		ReteNode* tmpLeft = processConditionNode(leftChild);
		tmpLeft->addSuccessorNode(result);
		
		ReteNode* tmpRight = processConditionNode(rightChild);
		tmpRight->addSuccessorNode(result);
	}
	else if (xmlNodeName == "not")
	{
		// Unary boolean operators
		tinyxml2::XMLElement* child = conditionNode->FirstChildElement();

		ReteNode* tmp = processConditionNode(child);
		tmp->addSuccessorNode(result);
	}

	return result;
}

RuleBased::PatternNode* ReteNetworkFactory::createPatternNode(tinyxml2::XMLElement* conditionNode)
{
	RuleBased::PatternNode* result;

	networkRoot->addSuccessorNode(result);

	return result;
}

}
