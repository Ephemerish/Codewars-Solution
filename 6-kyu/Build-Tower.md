## Description

**Build Tower**

Build a pyramid-shaped tower given a positive integer number of floors. A tower block is represented with "*" character.

For example, a tower with 3 floors looks like this:

    [
      "  *  ",
      " *** ", 
      "*****"
    ]

And a tower with 6 floors looks like this:

    [
      "     *     ", 
      "    ***    ", 
      "   *****   ", 
      "  *******  ", 
      " ********* ", 
      "***********"
    ]

**Kata's link:** [Build Tower](https://www.codewars.com/kata/576757b1df89ecf5bd00073b/cpp)

## Best Practices

**First:**
```cpp
#include <string>
#include <vector>

using namespace std;

vector<string> towerBuilder(unsigned nFloors) {
  vector <string> vect;
  for(unsigned i = 0, k = 1; i < nFloors; i++, k+=2)
    vect.push_back(string(nFloors-i-1, ' ') + string(k, '*') + string(nFloors-i-1, ' '));
  return {vect};
}
```

**Second:**
```cpp
include <string>
#include <vector>

std::vector<std::string> towerBuilder(unsigned nFloors) {
  std::vector<std::string> tower;
  for(unsigned i = 1; i <= nFloors; i++){
     std::string floor = std::string(nFloors - i, ' ') + std::string(i*2 - 1, '*') + std::string(nFloors - i, ' ');
     tower.push_back(floor);
   }
   return tower;    
};
```

## My Solutions
```cpp
#include <string>
#include <vector>

std::vector<std::string> towerBuilder(unsigned nFloors)
{
  std::vector<std::string> tower;
  for (uint i = 0; i < nFloors; i++)
  {
    std::string stars = "", spaces = "", floor = "";
    for (uint x = 0; x < i * 2 + 1; x++)
      stars += '*';
    for (uint x = 0; x < nFloors - i - 1; x++)
      spaces += ' ';
    floor = spaces + stars + spaces;
    tower.push_back(floor);
  }
  return tower;
}
```
