## Description:

Complete the solution so that it returns true if the first argument(string) passed in ends with the 2nd argument(also a string).

### Examples :
```cpp	
	solution('abc', 'bc') // returns true
	solution('abc', 'd') // returns false
```

**Kata's link:** [String ends with?](/cpp)

## Best Practices

**First:**
```cpp
#include <string>

bool solution(const std::string& str, const std::string& ending) {
  return str.size() >= ending.size() && str.compare(str.size() - ending.size(), std::string::npos, ending) == 0;
}
```

**Second:**
```cpp
bool solution(std::string const &str, std::string const &ending) {
    const int slen = str.length();
    const int eLen = ending.length();
    
    if (slen < eLen) {
        return false;
    }
    
    for (int i = 1; i <= eLen; i++) {
        if (str[slen - i] != ending[eLen - i]) {
            return false;
        }
    }
    return true;
}
```

## My Solutions
```cpp
#include <string>
bool solution(std::string const& str, std::string const& ending)
{
	return std::equal(ending.begin(), ending.end(), str.end() - ending.size());
}