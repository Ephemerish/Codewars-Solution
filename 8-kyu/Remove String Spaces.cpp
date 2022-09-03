//Description:
//
//Simple, remove the spaces from the string, then return the resultant string.

#include <string>

std::string no_space(const std::string& x)
{
	std::string y = x;
	y.erase(remove(y.begin(), y.end(), ' '), y.end());
	return y;
}