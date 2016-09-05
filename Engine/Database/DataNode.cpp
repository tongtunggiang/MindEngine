#include "DataNode.h"
#include "DataGroup.h"

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

DataNode* DataNode::getNodeByID(DataNode *root, int id)
{
    if (root == NULL)
        return NULL;

    if (id == root->getUniqueID())
        return root;

    if (root->isGroup())
    {
        DataGroup* group = (DataGroup*)root;
        DataNode* node = group->getLeftMostChild();
        while (node != NULL)
        {
            DataNode* result = getNodeByID(node, id);
            if (result != NULL)
                return result;
        }
    }

    return NULL;
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
