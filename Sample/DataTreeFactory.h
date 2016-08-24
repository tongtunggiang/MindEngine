#ifndef DATATREEFACTORY_H
#define DATATREEFACTORY_H

#include "tinyxml2.h"
#include "DataGroup.h"
#include "LeafDataNode.h"

#define DATABASE_FILE "Database.xml"

class DataTreeFactory
{

public:

	static RuleBased::DataNode* processDataNode(tinyxml2::XMLElement* xmlNode);

};

#endif // DATATREEFACTORY_H
