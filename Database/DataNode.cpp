#include "DataNode.h"

namespace Database
{

DataNode::DataNode()
{
	identifier = "";
	parent = NULL;
	rightSibling = NULL;
}

DataNode::DataNode(const std::string &identifier, const DataNode* parent, const DataNode* rightSibling)
{
	this->identifier = identifier;
	this->parent = parent;
	this->rightSibling = rightSibling;
}

DataNode::~DataNode()
{
	if (rightSibling != NULL)
		delete rightSibling;

	if (parent != NULL)
		delete parent;
}

const std::string& DataNode::getIdentifier()
{
	return identifier;
}

const DataNode* DataNode::getParent()
{
	return parent;
}

const DataNode* DataNode::getRightSibling()
{
	return rightSibling;
}

}
