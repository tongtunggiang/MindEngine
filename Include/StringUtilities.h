#ifndef STRINGUTILITIES_H
#define STRINGUTILITIES_H

#include <string>
#include <iostream>

namespace RuleBased
{

/**
 * @brief The print log to stdin macro.
 */
#define LOG(x) (std::cout << x << std::endl)

class StringUtilities
{

public:

	/**
	 * @brief Trim the redundant spaces, tabs and new line characters from the string.
	 * @param str The string would be trimmed.
	 */
	static void trimString(std::string& str);

	/**
	 * @brief Check if the given string is primitive type or not.
	 * @param str The string will be checked.
	 * @return true if str represents a primitive type.
	 */
	static bool isPrimitiveTypeName(const std::string& str);

private:

	static bool isRedundantSpace(char c, char cNext);

};

}

#endif // STRINGUTILITIES_H
