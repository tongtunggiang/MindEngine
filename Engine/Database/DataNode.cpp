#include "DataNode.h"

namespace RuleBased
{

DataNode::DataNode()
{
	identifier = "";
	rightSibling = NULL;
}

DataNode::DataNode(const IdType & identifier, DataNode * rightSibling)
{
	this->identifier = identifier;
	this->rightSibling = rightSibling;
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

DataNode* DataNode::addRightSibling(IdType id)
{
	DataNode* sibling = new DataNode(id, rightSibling);
	rightSibling = sibling;
	return sibling;
}

}
