#include "DataGroup.h"

namespace Database
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

}
