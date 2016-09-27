#include "DataGroup.h"

#include <iostream>

namespace RuleBased
{

DataGroup::DataGroup()
	: DataNode()
{
	leftMostChild = NULL;
}

DataGroup::DataGroup(const std::string &name)
	: DataNode(name)
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

DataNode* DataGroup::getRightMostChild() const
{
	DataNode* rightMostChild = leftMostChild;
	while (rightMostChild != NULL)
	{
		if (rightMostChild->getRightSibling() == NULL)
		{
			return rightMostChild;
		}
		rightMostChild = rightMostChild->getRightSibling();
	}

	return NULL;
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
	if (node->isLeaf())
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

DataNode* DataGroup::clone()
{
	DataGroup* instance = new DataGroup(this->name);

	instance->setLeftMostChild(this->leftMostChild->clone());

	DataNode* traverse = this->leftMostChild->getRightSibling();
	while (traverse != NULL)
	{
		instance->getRightMostChild()->setRightSibling(traverse->clone());
		traverse = traverse->getRightSibling();
	}

	return instance;
}

}
