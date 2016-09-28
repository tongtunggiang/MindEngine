#ifndef DATATREEFACTORY_H
#define DATATREEFACTORY_H

#include "tinyxml2.h"
#include "DataClasses.h"

#define DATABASE_FILE "Database.xml"

class DataTreeFactory
{

public:

	RuleBased::DataNode* process(tinyxml2::XMLDocument* doc, RuleBased::DataClasses* classes);

private:

	tinyxml2::XMLElement* getFirstNode(tinyxml2::XMLDocument* doc);
	RuleBased::DataNode* processXMLElement(tinyxml2::XMLElement* element, RuleBased::DataClasses* classes);
	void updateValuesForDataNodeFromXML(tinyxml2::XMLElement* element, RuleBased::DataNode* node);

};

#endif // DATATREEFACTORY_H
