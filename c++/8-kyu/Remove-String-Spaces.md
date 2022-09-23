Description:

Simple, remove the spaces from the string, then return the resultant string.

**Kata's link:** [Remove String Spaces](https://www.codewars.com/kata/57eae20f5500ad98e50002c5/cpp)

## Best Practices

**First:**
```cpp
std::string no_space(std::string x)
{
    x.erase(std::remove(x.begin(), x.end(), ' '), x.end());
    return x;
}
```

**Second:**
```cpp
std::string no_space(std::string x)
{    
    std::string temp="";
    for(int i = 0;i<x.size();i++){
      if(x[i]!=' ')
        temp+=x[i];
    }
    return temp;
}
```

## My Solutions
```cpp
#include <string>

std::string no_space(const std::string& x)
{
	std::string y = x;
	y.erase(remove(y.begin(), y.end(), ' '), y.end());
	return y;
}
```