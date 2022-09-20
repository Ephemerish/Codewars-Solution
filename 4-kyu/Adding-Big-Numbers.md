## Description

We need to sum big numbers and we require your help.

Write a function that returns the sum of two numbers. The input numbers are strings and the function must return a string.

Example
```cpp
add("123", "321"); -> "444"
add("11", "99");   -> "110"
```
Notes

* The input numbers are big.
* The input is a string of only digits
* The numbers are positives



**Kata's link:** [Adding Big Numbers](https://www.codewars.com/kata/525f4206b73515bffb000b21/cpp)

## Best Practices

**First:**
```cpp
using namespace std;

string add(string a, string b)
{
    a = string(max(a.size(), b.size()) + 1 - a.size(), '0') + a;
    b = string(a.size() - b.size(), '0') + b;
    for (int i = a.size()-1, carry = 0; i >= 0; i--)
    {
        int sum = a[i] + b[i] - 96 + carry;
        carry   = sum / 10;
        a[i]    = sum % 10 + '0';
    }
    int i = a.find_first_not_of('0');
    return 0 <= i ? a.substr(i) : a.substr(0, 1);
}
```

**Second:**
```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm> // std::min
#include <cstdint>   // uint64_t

class BigNumber
{
 public:
  using big_digit_t = uint64_t;

 private:
  static constexpr int number_of_digits_per_big_digit = 18;
  static constexpr big_digit_t big_digit_size = 1000000000000000000ULL;    // 10^number_of_digits_per_big_digit

  std::vector<big_digit_t> m_big_digits;

  int number_of_big_digits() const
  {
    return m_big_digits.size();
  }

  big_digit_t operator[](int big_digit_index) const
  {
    return big_digit_index < m_big_digits.size() ? m_big_digits[big_digit_index] : 0;
  }

  big_digit_t& operator[](int big_digit_index)
  {
    while (big_digit_index >= m_big_digits.size())
      m_big_digits.push_back(0);
    return m_big_digits[big_digit_index];
  }

 public:
  // Construct a BigNumber from a string.
  BigNumber(std::string const& s)
  {
    int number_of_digits;
    for (int left = s.size(); left > 0; left -= number_of_digits)
    {
      number_of_digits = std::min(number_of_digits_per_big_digit, left);
      m_big_digits.push_back(std::stoll(s.substr(left - number_of_digits, number_of_digits)));
    }
  }

  BigNumber& operator+=(BigNumber const& rhs)
  {
    int big_digits = std::max(number_of_big_digits(), rhs.number_of_big_digits());
    if (big_digits > number_of_big_digits())
      m_big_digits.resize(big_digits);
    big_digit_t rest = 0;
    for (int big_digit_index = 0; big_digit_index < big_digits; ++big_digit_index)
    {
      m_big_digits[big_digit_index] += rhs[big_digit_index] + rest;
      rest = m_big_digits[big_digit_index] / big_digit_size;
      m_big_digits[big_digit_index] -= rest * big_digit_size;
    }
    if (rest)
      m_big_digits.push_back(rest);
    return *this;
  }

  void print_on(std::ostream& os) const
  {
    auto it = m_big_digits.rbegin();
    os << *it;
    for (++it; it != m_big_digits.rend(); ++it)
      os << std::setfill('0') << std::setw(number_of_digits_per_big_digit) << *it;
  }

  std::string to_string() const
  {
    std::ostringstream oss;
    print_on(oss);
    return oss.str();
  }

  friend std::ostream& operator<<(std::ostream& os, BigNumber const& big_number)
  {
    big_number.print_on(os);
    return os;
  }
};

constexpr int BigNumber::number_of_digits_per_big_digit;
constexpr BigNumber::big_digit_t BigNumber::big_digit_size;

std::string add(const std::string& a, const std::string& b) {
  BigNumber an(a), bn(b);
  an += bn;
  return an.to_string();
}
```

## My Solutions
```cpp
#include <string>
#include <vector>

std::string add(const std::string& a, const std::string& b)
{
    int carry = 0;
    int lengthA = a.size() - 1;
    int lengthB = b.size() - 1;
    std::string ans = "";
    while ((lengthA >= 0) || (lengthB >= 0) || (carry > 0)) {
        int temp = carry;
        if (lengthA >= 0) temp += a[lengthA--] - '0';
        if (lengthB >= 0) temp += b[lengthB--] - '0';
        ans = ((char)(48 + temp % 10)) + ans;
        carry = temp / 10;
    }
    return ans;
}
```
