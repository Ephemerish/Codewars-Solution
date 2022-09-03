## Description:

Check to see if a string has the same amount of 'x's and 'o's.The method must return a boolean and be case insensitive.The string can contain any char.

### Examples input / output:

	XO("ooxx") = > true
	XO("xooxx") = > false
	XO("ooxXm") = > true
	XO("zpzpzpp") = > true // when no 'x' and 'o' is present should return true
	XO("zzoo") = > false

**Kata's link:** [Exes and Ohs](https://www.codewars.com/kata/55908aad6620c066bc00002a/cpp)

## Best Practices

**First:**
```cpp
#include <algorithm>
bool XO(const std::string& str)
{
  int xCount = std::count(str.begin(), str.end(), 'x') + std::count(str.begin(), str.end(), 'X');
  int oCount = std::count(str.begin(), str.end(), 'o') + std::count(str.begin(), str.end(), 'O');
  return xCount ==  oCount;
}
```

**Second:**
```cpp
#include <string>

bool XO(const std::string& str)
{
  int counter = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == 'x' || str[i] == 'X')
      counter++;

    if (str[i] == 'o' || str[i] == 'O')
      counter--;
  }

  return counter == 0;
}
```

## My Solutions
```cpp
bool XO(const std::string& str)
{
    int xCounter = 0, oCounter = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'x' || str[i] == 'X')
            xCounter++;
        else if (str[i] == 'o' || str[i] == 'O')
            oCounter++;
    }
    if (xCounter == oCounter)
        return true;
    else
        return false;
}
```