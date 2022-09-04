## Description:

Write a function to split a stringand convert it into an array of words.

### Examples(Input ==> Output) :

	"Robin Singh" ==> ["Robin", "Singh"]

	"I love arrays they are my favorite" ==> ["I", "love", "arrays", "they", "are", "my", "favorite"]

**Kata's link:** [Convert a string to an array](https://www.codewars.com/kata/57e76bc428d6fbc2d500036d/cpp)

## Best Practices

**First:**
```cpp
#include <vector>
#include <string>
using namespace std;

vector<string> string_to_array(const string& s) {
  vector<string> res;
  stringstream ss(s + " ");
  string word;

  while (getline(ss, word, ' ')) res.push_back(word);
  return res;
}
```

**Second:**
```cpp
#include <vector>
#include <string>

std::vector<std::string> string_to_array(const std::string& str) {
    if(str.empty())
      return std::vector<std::string>{""};
    std::vector<std::string> ans;
    int i = 0;
    while(i <= str.size()){
      std::string s;
      while(str[i] != ' ' && i != str.size()){
        s += str[i];
        i++;
      }      
      ans.push_back(s);
      i++;
    }
  return ans;
}
```

## My Solutions
```cpp
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
```