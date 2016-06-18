#include "DataGroup.h"

namespace Database
{

DataGroup::DataGroup()
	: DataNode()
{
	leftMostChild = NULL;
}

DataGroup::DataGroup(const std::string &identifier, const DataNode *parent, const DataNode *rightSibling, const DataNode *leftMostChild)
	: DataNode(identifier, parent, rightSibling), leftMostChild(leftMostChild)
{
}

DataGroup::~DataGroup()
{
	if (leftMostChild != NULL)
		delete leftMostChild;
}

DataGroup::getLeftMostChild()
{
	return leftMostChild;
}

}
