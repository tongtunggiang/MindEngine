#include "DataNode.h"

namespace RuleBased
{

DataNode::DataNode()
{
	identifier = "";
	rightSibling = NULL;
}

DataNode::DataNode(const IdType & identifier)
{
	this->identifier = identifier;
	this->rightSibling = NULL;
}

DataNode::~DataNode()
{
	if (rightSibling != NULL)
		delete rightSibling;
}

IdType DataNode::getIdentifier() const
{
	return identifier;
}

DataNode *DataNode::getRightSibling() const
{
	return rightSibling;
}

bool DataNode::isGroup() const
{
	return false;
}

bool DataNode::isDatum() const
{
	return false;
}

void DataNode::setRightSibling(DataNode* sibling)
{
	sibling->rightSibling = rightSibling;
	rightSibling = sibling;
}

}
