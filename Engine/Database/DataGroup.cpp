#include "DataGroup.h"

namespace Database
{

DataGroup::DataGroup()
	: DataNode()
{
	leftMostChild = NULL;
}

DataGroup::DataGroup(const std::string &identifier, DataNode *parent, DataNode *rightSibling, DataNode* leftMostChild)
	: DataNode(identifier, parent, rightSibling)
{
	this->leftMostChild = leftMostChild;
}

DataGroup::~DataGroup()
{
	if (leftMostChild != NULL)
		delete leftMostChild;
}

const DataNode* DataGroup::getLeftMostChild()
{
	return leftMostChild;
}

bool DataGroup::isGroup()
{
	return true;
}

}
