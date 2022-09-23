## Description:

Implement a function that adds two numbers togetherand returns their sum in binary.The conversion can be done before, or after the addition.

The binary number returned should be a string.

### Examples : (Input1, Input2-- > Output(explanation)))

    1, 1 -- > "10" (1 + 1 = 2 in decimal or 10 in binary)
    5, 9 -- > "1110" (5 + 9 = 14 in decimal or 1110 in binary)

**Kata's link:** [Binary Addition](https://www.codewars.com/kata/551f37452ff852b7bd000139/cpp)

## Best Practices

**First:**
```cpp
#include <cstdint>
#include <string>
#include <fmt/core.h>

std::string add_binary(std::uint64_t a, std::uint64_t b) {
  return fmt::format("{:b}", a + b);
}
```

**Second:**
```cpp
#include <cstdint>
#include <string>

using namespace std;

string add_binary(uint64_t a, uint64_t b) {
    a += b;
    string output;

    do {
        output = to_string(a % 2) + output;
        a /= 2;
    } while(a > 0);

    return output;
}
```

## My Solutions
```cpp
#include <cstdint>
#include <bits/stdc++.h>
#include <string>

std::string add_binary(uint64_t a, uint64_t b) {
	if (a + b == 0) return "0";
	long int n = (long int)(log2(a + b));
	return std::bitset<64>(a + b).to_string().substr(64 - n - 1);
}
```