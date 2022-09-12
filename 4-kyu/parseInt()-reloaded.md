## Description

In this kata we want to convert a string into an integer. The strings simply represent the numbers in words.

### Examples:

* "one" => 1
* "twenty" => 20
* "two hundred forty-six" => 246
* "seven hundred eighty-three thousand nine hundred and nineteen" => 783919

### Additional Notes:

* The minimum number is "zero" (inclusively)
* The maximum number, which must be supported is 1 million (inclusively)
* The "and" in e.g. "one hundred and twenty-four" is optional, in some cases it's present and in others it's not
  * All tested numbers are valid, you don't need to validate them



**Kata's link:** [parseInt() reloaded](https://www.codewars.com/kata/525c7c5ab6aecef16e0001a5/cpp)

## Best Practices

**First:**
```cpp
#include <string>
#include <map>

long parse_int(const std::string& number) {
  std::map<std::string, int> mapping = {
    {"zero", 0}, {"and", 0}, {"hundred", 100},  {"thousand", 1000}, {"million", 1000000},  
    {"one", 1}, {"two",   2}, {"three",  3}, {"four", 4}, {"five", 5}, 
    {"six", 6}, {"seven", 7}, {"eight",  8}, {"nine", 9}, {"ten", 10},
    {"eleven",  11}, {"twelve",    12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15},
    {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, 
    {"twenty",  20}, {"thirty",  30},   {"forty",    40}, {"fifty",    50}, 
    {"sixty",   60}, {"seventy", 70},   {"eighty",   80}, {"ninety", 90}
    
  };
  
  long result = 0;
  auto add = [&] (auto& w) {
    if (w.empty()) return;
    auto i = mapping[w];
    if      (i > 0 && i < 100) result += i;
    else if (i == 1000 || i == 1000000) result *= i;
    else if (i == 100) result += 99 * (result % 100);
    w = "";
  };
  
  std::string word;
  for (auto c : number) {
    if (word.size() > 0 && (c == ' ' || c == '-')) add(word);
    else word.push_back(c);
  }
  add(word);
  
  return result;
}
```

**Second:**
```cpp
#include <string>
#include <sstream>

long parse_int(std::string number) {
  std::map<std::string, int> convMap {
  { "one", 1 },{"two", 2},{"three",3},{"four",4},{"five",5},
  { "six",6}, {"seven",7},{"eight",8},{"nine",9},{"ten",10},
  { "eleven",11},{"twelve",12},{"thirteen",13},{"fourteen",14},
  { "fifteen",15},{"sixteen",16},{"seventeen",17},{"eighteen",18},
  { "nineteen",19},{"twenty",20},{"thirty",30},{"forty",40},{"fifty",50},
  { "sixty", 60}, {"seventy", 70},{"eighty",80},{"ninety",90},{"hundred",100},
  { "thousand",1000}, {"million", 1000000}};
  
  for( auto& c : number ) {
    if( c == '-' ) c = ' ';
  }
  
  std::stringstream ss(number); 
  std::string word; 
  
  int num = 0, totalNum = 0;
  while(ss>>word) 
  {
    auto it = convMap.find(word); 
    if( it != convMap.end() ) 
    {
      if( it->second == 100 ) {
        num *= 100; 
      } else if( it->second == 1000 ) {
        totalNum += num * 1000; 
        num = 0; 
      } else if ( it->second == 1000000 ) {
        totalNum += num * 1000000; 
        num = 0; 
      } else {
        num += it->second; 
      }
    }
  }
  totalNum += num; 
  return totalNum; 
}
```

## My Solutions
```cpp
#include <iostream>
#include <string>

long parse_int(std::string number)
{
  int n = number.size(), start = 0;
  std::string cardinalDigit;
  cardinalDigit.reserve(10);
  long tempResult = 0;
  long result = 0;
  int wordCounter = 0;
  bool flag = false;
  for (int index = 0; index <= n; index++)
  {
    if (number[index] == ' ' || number[index] == '-' || index == n)
    {
      wordCounter++;
      cardinalDigit = number.substr(start, index - start);
      std::cout << cardinalDigit << std::endl;
      if (cardinalDigit == "one")
        tempResult += 1;
      else if (cardinalDigit == "two")
        tempResult += 2;
      else if (cardinalDigit == "three")
        tempResult += 3;
      else if (cardinalDigit == "four")
        tempResult += 4;
      else if (cardinalDigit == "five")
        tempResult += 5;
      else if (cardinalDigit == "six")
        tempResult += 6;
      else if (cardinalDigit == "seven")
        tempResult += 7;
      else if (cardinalDigit == "eight")
        tempResult += 8;
      else if (cardinalDigit == "nine")
        tempResult += 9;
      else if (cardinalDigit == "ten")
        tempResult += 10;
      else if (cardinalDigit == "eleven")
        tempResult += 11;
      else if (cardinalDigit == "twelve")
        tempResult += 12;
      else if (cardinalDigit == "thirteen")
        tempResult += 13;
      else if (cardinalDigit == "fourteen")
        tempResult += 14;
      else if (cardinalDigit == "fifteen")
        tempResult += 15;
      else if (cardinalDigit == "sixteen")
        tempResult += 16;
      else if (cardinalDigit == "seventeen")
        tempResult += 17;
      else if (cardinalDigit == "eighteen")
        tempResult += 18;
      else if (cardinalDigit == "nineteen")
        tempResult += 19;
      else if (cardinalDigit == "twenty")
        tempResult += 20;
      else if (cardinalDigit == "thirty")
        tempResult += 30;
      else if (cardinalDigit == "forty")
        tempResult += 40;
      else if (cardinalDigit == "fifty")
        tempResult += 50;
      else if (cardinalDigit == "sixty")
        tempResult += 60;
      else if (cardinalDigit == "seventy")
        tempResult += 70;
      else if (cardinalDigit == "eighty")
        tempResult += 80;
      else if (cardinalDigit == "ninety")
        tempResult += 90;

      if (cardinalDigit == "million")
      {
        tempResult *= 1000000;
        result += tempResult;
        tempResult = 0;
      }
      else if (cardinalDigit == "thousand")
      {
        if (flag)
        {
          result += tempResult;
          result *= 1000;
          tempResult = 0;
        }
        else
        {
          tempResult *= 1000;
          result += tempResult;
          tempResult = 0;
        }
      }
      else if (cardinalDigit == "hundred")
      {
        flag = true;
        tempResult *= 100;
        result += tempResult;
        tempResult = 0;
      } 

      start = index + 1;
    }
    if(index == n)
      result += tempResult;
  }
  return result;
}
```
