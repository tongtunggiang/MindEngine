#include <iostream>

#include "tinyxml2.h"

#include "DataGroup.h"
#include "Datum.h"

#include "DataGroupMatch.h"
#include "NumberDatumMatch.h"

using namespace RuleBased;

DataNode* constructDataTree()
{
	std::cout << "Constructing the data tree" << std::endl;

    tinyxml2::XMLDocument doc;
    doc.LoadFile("Database.xml");

    if (doc.ErrorID() != 0)
    {
        std::cout << "Can't load the database file" << std::endl;
        return NULL;
    }

    std::cout << "Database file is loaded succesfully" << std::endl;
    tinyxml2::XMLElement *traverseNode = doc.FirstChildElement();

	// Traverse the XML tree
	while (traverseNode->FirstChildElement() != NULL)
	{
		tinyxml2::XMLElement *traverseNodeSiblings = traverseNode;
		while (traverseNodeSiblings->NextSiblingElement() != NULL)
		{
			std::cout << traverseNode->Name() << "  ";
			traverseNodeSiblings = traverseNodeSiblings->NextSiblingElement();
		} 
		traverseNode = traverseNode->FirstChildElement();
		std::cout << std::endl;
	}

    return NULL;
}

int main()
{
    DataNode* treeRoot = constructDataTree();

    return 0;
}
