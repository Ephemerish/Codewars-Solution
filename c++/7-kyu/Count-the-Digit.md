## Description:

take an integer `n(n >= 0)` and a digit `d(0 <= d <= 9)` as an integer.

square all numbers `k(0 <= k <= n)` between 0 and n.

count the numbers of digits `d` used in the writing of all the `k * *2`.

call `nb_dig`(or nbdig or ...) the function taking `n` and `d` as parameters and returning this count.

### examples:

    n = 10, d = 1
    the k * k are 0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100
    we are using the digit 1 in : 1, 16, 81, 100. the total count is then 4.
    
    nb_dig(25, 1) returns 11 since
    the k * k that contain the digit 1 are :
	1, 16, 81, 100, 121, 144, 169, 196, 361, 441.
	so there are 11 digits 1 for the squares of numbers between 0 and 25.

note that 121 has twice the digit 1.

**Kata's link:** [Count the Digit](https://www.codewars.com/kata/566fc12495810954b1000030/cpp)

## Best Practices

**First:**
```cpp
class CountDig
{
public:
    static int nbDig(int n, int d);
};

int CountDig::nbDig(int n, int d) { 
  int count = 0;
  for (int k = 0; k <= n; ++k) {
    int m = k*k;
    do {
      if ((m % 10) == d) count += 1;
      m /= 10;
    } while(m);
  }
  return count;
}
```

**Second:**
```cpp
namespace CountDig
{
  int nbDig(int n, int d)
  {
    std::string digits;
    for (int k = 0; k <= n; ++k)
      digits += std::to_string(k * k);
  
    return std::count(digits.begin(), digits.end(), std::to_string(d)[0]);
  }
}
```

## My Solutions
```cpp
class CountDig
{
public:
    static int nbDig(int n, int d)
    {
        int instance = 0, sqr, temp;

        for (int k = 0; k <= n; k++)
        {
            sqr = k * k;

            while (sqr > 0)
            {
                temp = sqr % 10;
                if (temp == d)
                    instance++;
                sqr /= 10;
            }
        }

        if (d == 0) instance++;

        return instance;
    }
};
```