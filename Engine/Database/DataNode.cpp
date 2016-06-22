#include "DataNode.h"

namespace Database
{

DataNode::DataNode()
{
	identifier = "";
	rightSibling = NULL;
}

DataNode::DataNode(const std::string &identifier, DataNode* rightSibling)
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

}
