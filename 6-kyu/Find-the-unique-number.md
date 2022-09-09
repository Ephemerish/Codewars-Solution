## Description

There is an array with some numbers. All numbers are equal except for one. Try to find it!

```cpp
finduniq((const float[]){1, 1, 1, 2, 1, 1}, 5); /* --> 2 */
finduniq((const float[]){0, 0, 0.55, 0, 0}, 5); /* --> 0.55 */
```

It’s guaranteed that array contains at least 3 numbers.

The tests contain some very huge arrays, so think about performance.

**Kata's link:** [Find the unique number](https://www.codewars.com/kata/585d7d5adb20cf33cb000235/cpp)

## Best Practices

**First:**
```cpp
#include <iostream>
#include <map>

float find_uniq(const std::vector<float> &v)
{
  std::map<float, int> A;
  
  float a = 0;
  
  for(auto x: v){
    A[x]+=1;
  }
  
  for(auto [key, val]: A){
    if(val == 1)
      a = key;
  }
  
  return a;
}
```

**Second:**
```cpp
float find_uniq(const std::vector<float> &v)
{
   int size = v.size();
   if ((v[0]!=v[1])&&(v[0]!=v[2]))  
   {
    return v[0];
   };
  if ((v[0]==v[1])&&(v[0]!=v[2]))  
   {
    return v[2];
   }
  
  
    else 
    {
      
     for (int i = 0; i<size; i++) 
     {
      if (v[i]!=v[0]) 
      {
        return v[i];
      }
     }
    }
}
```

## My Solutions
```cpp
float find_uniq(const std::vector<float> &v)
{
  float common = 0;
  if(v[0] == v[1])
    common = v[0];
  else if (v[1] == v[2])
    common = v[1];
  else
    common = v[2];

  for(unsigned int i = 0; i < v.size(); i++)
  {
    if(v[i] != common)
      return v[i];
  }
    return -1;
}
```
