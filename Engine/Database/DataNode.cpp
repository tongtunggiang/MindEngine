#include "DataNode.h"

namespace RuleBased
{

int DataNode::staticID = 0;

void DataNode::createUniqueID()
{
	id = staticID;
	staticID++;
}

DataNode::DataNode()
{
	name = "";
	rightSibling = NULL;

	createUniqueID();
}

DataNode::DataNode(const NodeName& name)
{
	this->name = name;
	this->rightSibling = NULL;

	createUniqueID();
}

DataNode::~DataNode()
{
	if (rightSibling != NULL)
		delete rightSibling;
}

NodeName DataNode::getName() const
{
	return name;
}

DataNode *DataNode::getRightSibling() const
{
	return rightSibling;
}

bool DataNode::isGroup() const
{
	return false;
}

bool DataNode::isLeaf() const
{
	return false;
}

void DataNode::setRightSibling(DataNode* sibling)
{
	sibling->rightSibling = rightSibling;
	rightSibling = sibling;
}

int DataNode::getUniqueID() const
{
	return id;
}

}
