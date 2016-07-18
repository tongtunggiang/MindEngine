#include "DataGroup.h"

#include <iostream>

namespace RuleBased
{

DataGroup::DataGroup()
	: DataNode()
{
	leftMostChild = NULL;
}

DataGroup::DataGroup(const std::string &identifier)
	: DataNode(identifier)
{
	this->leftMostChild = NULL;
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

void DataGroup::setLeftMostChild(DataNode * child)
{
	if (leftMostChild == NULL)
	{
		leftMostChild = child;
	}
	else
	{
		child->setRightSibling(leftMostChild);
		leftMostChild = child;
	}
}

bool DataGroup::isGroup() const
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
