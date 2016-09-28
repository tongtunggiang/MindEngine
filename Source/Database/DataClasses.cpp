#include "DataClasses.h"

namespace RuleBased
{

DataClasses::DataClasses()
{
	classes.clear();
}

void DataClasses::addNewClass(const std::string &name, DataNode *newClass, bool overrideExisting)
{
	if (classes.count(name) == 0)
	{
		classes[name] = newClass;
	}
	else
	{
		if (overrideExisting)
		{
			classes[name] = newClass;
		}
		else
		{
			return;
		}
	}
}

DataNode* DataClasses::enquireClass(const std::string& name)
{
	if (classes.count(name) > 0)
		return classes[name];

	return NULL;
}

}
