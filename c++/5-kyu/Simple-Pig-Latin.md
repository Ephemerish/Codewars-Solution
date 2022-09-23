## Description

Move the first letter of each word to the end of it, then add "ay" to the end of the word. Leave punctuation marks untouched.

### Examples
```cpp
pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
pigIt('Hello world !');     // elloHay orldway !
```

**Kata's link:** [Simple Pig Latin](https://www.codewars.com/kata/520b9d2ad5c005041100000f/cpp)

## Best Practices

**First:**
```cpp
#include <string>
#include <regex>
using namespace std;
string pig_it(string Z) {
    regex reg(("(\\w)(\\w*)(\\s|$)"));
    return regex_replace(Z, reg, "$2$1ay$3");
}
```

**Second:**
```cpp
#include<iostream>
#include<sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string pig_it(string str)
{
  
  string punctuation = "!.,:;?";
  string result = "";
  stringstream ss;
  ss << str;

  for (char ch; ss.get(ch);) { //read char and whitespace
    
    if (isspace(ch))
      result += ch;
        
    else {
      ss.putback(ch); //read a word from the stream
      string word;
      ss >> word;
      
      if (find(punctuation.begin(), punctuation.end(), word[0]) == punctuation.end()) {
        word.push_back(word[0]);
        word.erase(word.begin());
        word.push_back('a');
        word.push_back('y');
      }
      result += word;
    }
  }

  return result;
}
```

## My Solutions
```cpp
std::string pig_it(std::string str)
{
  
   int n = str.size(), s = 0;
    std::string result;
    for (int index = 0; index <= n; index++)
    {
        if ((str[index] == ' ') || (index == n))
        {
            if (s + 1 == index - 1)
                result += str[s+1];

            else
                result += str.substr(s + 1, index - s - 1);
            result += str[s];
            result += "ay";
            if (index < n)
                result += " ";
            s = index + 1;
        }
      
      while (str[index] == '!' || str[index] == '?' || str[index] == '.' || str[index] == ',')
            if (index + 2 < n)
            {
                result += str[index];
                result += " ";
                index += 2;
                s += 2;
            }

            else
            {
                result += str[index];
                index++;
                break;
            }

    }
  return result;
}
```
