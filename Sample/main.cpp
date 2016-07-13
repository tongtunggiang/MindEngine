#include <iostream>

#include "tinyxml2.h"

#include "DataGroup.h"
#include "Datum.h"

#include "DataGroupMatch.h"
#include "NumberDatumMatch.h"

using namespace RuleBased;

DataNode* constructDataTree()
{
    tinyxml2::XMLDocument doc;
    doc.LoadFile("Database.xml");

    if (doc.ErrorID() != 0)
    {
        std::cout << "Can't load the database file" << std::endl;
        return NULL;
    }

    std::cout << "Database file is loaded succesfully" << std::endl;
    tinyxml2::XMLElement *databaseNode = doc.FirstChildElement();

	DataNode* root = new DataNode(doc.RootElement()->Name(), NULL);
	std::cout << root->getIdentifier() << " " << root->getRightSibling() << std::endl;

    return NULL;
}

int main()
{
    DataNode* treeRoot = constructDataTree();

    return 0;
}
