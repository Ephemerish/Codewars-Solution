## Description:
Task:

Your task is to write a function which returns the sum of following series upto nth term(parameter).

    Series : 1 + 1 / 4 + 1 / 7 + 1 / 10 + 1 / 13 + 1 / 16 + ...

### Rules :

* You need to round the answer to 2 decimal places and return it as String.
* If the given value is 0 then it should return 0.00
* You will only be given Natural Numbers as arguments.

### Examples:(Input-- > Output)

    1 -- > 1 -- > "1.00"
    2 -- > 1 + 1 / 4 -- > "1.25"
    5 -- > 1 + 1 / 4 + 1 / 7 + 1 / 10 + 1 / 13 -- > "1.57"

**Kata's link:** [Sum of the first nth term of Series](https://www.codewars.com/kata/555eded1ad94b00403000071/cpp)

## Best Practices

**First:**
```cpp
#include <iomanip>

using namespace std;

string seriesSum(int n)
{
    double ret = 0.0;
    double base = 1.0;
    while (n--) {
      ret += 1 / base;
      base += 3;
    }
    stringstream retss;
    retss << setprecision(2) << fixed << ret;
    return retss.str();
}
```

**Second:**
```cpp
std::string seriesSum(int n)
{
    float sum = 0;
    char str[3];
    for(auto i = 0; i < n; i++) sum += 1./(3*i+1);
    sprintf(str, "%.2f", sum);
    return str;
}
```

## My Solutions
```cpp
#include <cmath>

std::string seriesSum(int n)
{
    if (n == 0)
        return "0.00";
    else
    {
        float fraction, twoDecimal, sum = 0;
        for (int iteration = 0; iteration < n; iteration++)
        {
            fraction = (float)1 / (1 + iteration * 3);
            sum += fraction;
            std::cout << sum << std::endl;
        }
        twoDecimal = round(sum * 100) / 100;
        std::string out = std::to_string(twoDecimal);
        return  out.erase(4);
    }
}