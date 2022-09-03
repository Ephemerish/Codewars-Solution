//Description:
//
//Complete the function that accepts a string parameter, and reverses each word in the string.All spaces in the string should be retained.
//Examples
//
//"This is an example!" ==> "sihT si na !elpmaxe"
//"double  spaces" ==> "elbuod  secaps"

#include <string>
#include <algorithm>

std::string reverse_words(std::string str)
{
    int n = str.size(), s = 0, e;
    std::string result(n, '\0');
    for (int index = 0; index <= n; index++)
    {
        if ((str[index] == ' ') || (index == n))
        {
            e = n - index;
            reverse(str.begin() + s, str.end() - e);
            s = index + 1;
        }
    }
    return str;
}