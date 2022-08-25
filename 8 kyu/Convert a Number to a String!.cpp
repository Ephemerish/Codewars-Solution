//Description:
//
//We need a function that can transform a number(integer) into a string.
//
//What ways of achieving this do you know ?
//Examples(input-- > output) :
//
//	123  -- > "123"
//	999  -- > "999"
//	- 100 -- > "-100"

#include <string>
#include <sstream>

std::string number_to_string(int num)
{
    std::string str;
    std::stringstream stream;
    stream << num;
    stream >> str;
    return str;
}
