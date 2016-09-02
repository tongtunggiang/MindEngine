#include "ReteNetworkFactory.h"
#include <string>
#include <iostream>

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
	LOG("RETE: Start constructing Rete network");

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

	LOG("RETE: Finish constructing Rete network");
}

void ReteNetworkFactory::processRuleNode(tinyxml2::XMLElement* ruleNode)
{
	LOG("RETE:   Process rule node: " + std::string(ruleNode->Name()));

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

	LOG("");
}

ReteNode* ReteNetworkFactory::processConditionNode(tinyxml2::XMLElement* conditionNode)
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

JoinNode* ReteNetworkFactory::createJoinNode(tinyxml2::XMLElement* conditionNode)
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
		LOG("RETE:     Creating a join node, type " + xmlNodeName + ", children: " 
			+ leftChild->Name() + "-" + rightChild->Name());
	}
	else if (xmlNodeName == "not")
	{
		// Unary boolean operators
		tinyxml2::XMLElement* child = conditionNode->FirstChildElement();

		ReteNode* tmp = processConditionNode(child);
		tmp->addSuccessorNode(result);
		LOG("RETE:     Creating a join node, type " + xmlNodeName + ", child: "
			+ child->Name());
	}

	return result;
}

PatternNode* ReteNetworkFactory::createPatternNode(tinyxml2::XMLElement* conditionNode)
{
	LOG("RETE:     Creating a pattern node");
	DataNodeCondition* condition = createCondition(conditionNode);

	PatternNode* result = new PatternNode((DataGroupCondition*)condition);

	networkRoot->addSuccessorNode(result);

	return result;
}

DataNodeCondition* ReteNetworkFactory::createCondition(tinyxml2::XMLElement* conditionNode)
{
	if (conditionNode->Attribute("type") != NULL)
	{
		std::string type = conditionNode->Attribute("type");
		if (type == "int")
		{
			return createNumberLeafCondition<int>(conditionNode);
		}
		
		if (type == "float")
		{
			return createNumberLeafCondition<float>(conditionNode);
		}
		
		if (type == "string")
		{
			return createStringLeafCondition(conditionNode);
		}
	}
	else
	{
		return createDataGroupCondition(conditionNode);
	}
}

DataGroupCondition* ReteNetworkFactory::createDataGroupCondition(tinyxml2::XMLElement* conditionNode)
{
	LOG("RETE:       Create a data group condition " + std::string(conditionNode->Name()));
	DataGroupCondition* condition = new DataGroupCondition();
	condition->name = std::string(conditionNode->Name());
	condition->leftMostChild = createCondition(conditionNode->FirstChildElement());

	tinyxml2::XMLElement* xmlSibling = conditionNode->FirstChildElement()->NextSiblingElement();
	DataNodeCondition* sibling = condition->leftMostChild->rightSibling;
	while (xmlSibling != NULL)
	{
		sibling = createCondition(xmlSibling);
		xmlSibling = xmlSibling->NextSiblingElement();
		sibling = sibling->rightSibling;
	}

	return condition;
}

StringLeafCondition* ReteNetworkFactory::createStringLeafCondition(tinyxml2::XMLElement* conditionNode)
{
	LOG("RETE:       Create a string leaf condition " + std::string(conditionNode->Name()) + " - " + std::string(conditionNode->GetText()));
	return new StringLeafCondition(conditionNode->Name(),
								   conditionNode->GetText());
}

}
