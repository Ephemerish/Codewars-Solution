## Description:

Write a function, persistence, that takes in a positive parameter numand returns its multiplicative persistence, which is the number of times you must multiply the digits in num until you reach a single digit.

### For example(Input-- > Output) :

    39 -- > 3 (because 3 * 9 = 27, 2 * 7 = 14, 1 * 4 = 4 and 4 has only one digit)
    999 -- > 4 (because 9 * 9 * 9 = 729, 7 * 2 * 9 = 126, 1 * 2 * 6 = 12, and finally 1 * 2 = 2)
    4 -- > 0 (because 4 is already a one - digit number)


**Kata's link:** [Persistent Bugger](https://www.codewars.com/kata/55bf01e5a717a0d57e0000ec/cpp)

## Best Practices

**First:**
```cpp
int persistence(long long n) {
  long long p = 1;
  if (n < 10) { return 0; } 
  while (n > 0) { p = (n % 10) * p; n = n/10; }
  return persistence(p) + 1;
}
```

**Second:**
```cpp
int persistence(long long n){
    int count=0,mul=1;
    std::string one=std::to_string(n);

    while(one.length()>1){
        mul=1;
        for(int i=0;i<one.length();i++)
            mul*=(one[i]-'0');
      
        one=std::to_string(mul);
        count++;
    }

    return count;
}
```

## My Solutions
```cpp
int persistence(long long n)
{
    int counter, instance = n, temp = 1;
    for (counter = 0; instance > 9; counter++)
    {
        temp = 1;
        while (instance > 0)
        {
            temp *= instance % 10;
            instance /= 10;
        }
        instance = temp;
    }
    return counter;
}
```