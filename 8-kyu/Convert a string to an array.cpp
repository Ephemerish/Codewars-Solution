//Description:
//
//Write a function to split a stringand convert it into an array of words.
//Examples(Input ==> Output) :
//
//	"Robin Singh" ==> ["Robin", "Singh"]
//
//	"I love arrays they are my favorite" ==> ["I", "love", "arrays", "they", "are", "my", "favorite"]

#include <vector>
#include <string>
#include <bits/stdc++.h>

std::vector<std::string> string_to_array(const std::string& s)
{
    std::vector<std::string> out;
    std::string word = "";
    for (auto x : s)
    {
        if (x == ' ')
        {
            out.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }
    out.push_back(word);

    return out;
}