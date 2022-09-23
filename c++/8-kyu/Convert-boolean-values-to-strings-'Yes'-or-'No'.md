## Description:

Complete the method that takes a boolean valueand return a `"Yes"` string for `true`, or a `"No"` string for `false`.

**Kata's link:** [Convert boolean values to strings 'Yes' or 'No'.](https://www.codewars.com/kata/53369039d7ab3ac506000467/cpp)

## Best Practices

**First:**
```cpp
using namespace std;

string bool_to_word(bool value)
{
  return value ? "Yes" : "No";
}
```

**Second:**
```cppstd::string bool_to_word(bool value)
{
  return value ? "Yes" : "No";
}
```

## My Solutions
```cpp
#include <string>

std::string bool_to_word(bool value)
{
	return value ? "Yes" : "No";
}
```