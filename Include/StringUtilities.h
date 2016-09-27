#ifndef STRINGUTILITIES_H
#define STRINGUTILITIES_H

#include <string>

class StringUtilities
{

public:

	/**
	 * @brief Trim the redundant spaces, tabs and new line characters from the string.
	 * @param str The string would be trimmed.
	 */
	static void trimString(std::string& str);

private:

	static bool isRedundantSpace(char c, char cNext);
};

#endif // STRINGUTILITIES_H
