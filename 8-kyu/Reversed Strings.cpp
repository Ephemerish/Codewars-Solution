
//Description:
//
//Complete the solution so that it reverses the string passed into it.
//
//'world' = > 'dlrow'
//'word' = > 'drow'

#include <iostream>
#include <string>

std::string reverseString(std::string string)
{

    std::string stringReverse = string;

    for (int x = 0, len = string.length(); x < len; x++)
    {
        stringReverse[len - x - 1] = string[x];
    }

    std::cout << stringReverse;

    return stringReverse;
}