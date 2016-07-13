#include "DataGroup.h"

#include <iostream>

namespace RuleBased
{

DataGroup::DataGroup()
	: DataNode()
{
	leftMostChild = NULL;
}

DataGroup::DataGroup(const std::string &identifier, DataNode *rightSibling, DataNode* leftMostChild)
	: DataNode(identifier, rightSibling)
{
	this->leftMostChild = leftMostChild;
}

DataGroup::~DataGroup()
{
	if (leftMostChild != NULL)
		delete leftMostChild;
}

DataNode* DataGroup::getLeftMostChild() const
{
	return leftMostChild;
}

bool DataGroup::isGroup()
{
	return true;
}

bool DataGroup::canCastToDataGroup(DataNode* node)
{
	if (node->isDatum())
		return false;
	return true;
}

DataGroup * DataGroup::castToDataGroup(DataNode* node)
{
	if (!canCastToDataGroup(node))
		return NULL;

	if (node->isGroup())
		return (DataGroup*)node;

	DataGroup* castResult;
	castResult = (DataGroup*)node;
	std::cout << "castResult: " << castResult->isGroup() << std::endl;
	return castResult;
}

}
