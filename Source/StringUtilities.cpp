#include "StringUtilities.h"
#include <cctype>

void StringUtilities::trimString(std::string& str)
{
	//str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	//str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
	//str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());

	int i = 0;
	while (i < str.length())
	{
		if (isRedundantSpace(str[i], str[i + 1]))
			str.erase(str.begin() + i);
		else
			i++;
	}
}

bool StringUtilities::isRedundantSpace(char c, char cNext)
{
	if (c == '\n' ||
		c == '\t' ||
		c == '\r' ||
		(c == ' ' && (!std::isdigit(cNext))))
		return true;

	return false;
}
