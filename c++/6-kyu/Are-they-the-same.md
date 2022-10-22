## Description

Given two arrays `a` and `b` write a function comp `(a, b)` (`orcompSame(a, b)`) that checks whether the two arrays have the "same" elements, with the same multiplicities (the multiplicity of a member is the number of times it appears). "Same" means, here, that the elements in `b` are the elements in `a squared, regardless of the order.

### Examples
Valid arrays

```cpp
a = [121, 144, 19, 161, 19, 144, 19, 11]  
b = [121, 14641, 20736, 361, 25921, 361, 20736, 361]
```

`comp(a, b)` returns true because in `b` 121 is the square of 11, 14641 is the square of 121, 20736 the square of 144, 361 the square of 19, 25921 the square of 161, and so on. It gets obvious if we write `b`'s elements in terms of squares:

```cpp
a = [121, 144, 19, 161, 19, 144, 19, 11] 
b = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]
```

### Invalid arrays

If, for example, we change the first number to something else, comp is not returning true anymore:

```cpp
a = [121, 144, 19, 161, 19, 144, 19, 11]  
b = [132, 14641, 20736, 361, 25921, 361, 20736, 361]
```

`comp(a,b)` returns false because in `b` 132 is not the square of any number of `a`.

```cpp
a = [121, 144, 19, 161, 19, 144, 19, 11]  
b = [121, 14641, 20736, 36100, 25921, 361, 20736, 361]
```

`comp(a,b)` returns false because in `b` 36100 is not the square of any number of `a`.

### Remarks

* `a` or `b` might be `[] or {}` (all languages except R, Shell).
* `a` or `b` might be `nil` or `null` or `None` or `nothing` (except in C++, COBOL, Crystal, D, Dart, Elixir, Fortran, F#, Haskell, Nim, OCaml, Pascal, Perl, PowerShell, Prolog, PureScript, R, Racket, Rust, Shell, Swift).

If `a` or `b` are `nil` (or `null` or `None`, depending on the language), the problem doesn't make sense so return false.

### Note for C

The two arrays have the same size `(> 0)` given as parameter in function `comp`.


**Kata's link:** [Are they the "same"?](https://www.codewars.com/kata/550498447451fbbd7600041c/cpp)

## Best Practices

**First:**
```cpp
#include <algorithm>

class Same {
public:
  static bool comp(std::vector<int>, std::vector<int>);
};

bool Same::comp(std::vector<int> a, std::vector<int> b) {
  for (auto& v : a) {
    v = v * v;
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  return a == b;
}
```

**Second:**
```cpp
#include <iostream>

class Same {
    public :static bool comp(std::vector<int>, std::vector<int>);
};

bool Same::comp(std::vector<int> a, std::vector<int> b)
{
  if (a.size() != b.size()) {
    return false;
  }
  if (a.empty()) {
    return true;
  }
  
  for (auto & elem : a) {
    elem *= elem;
  }
  
  return std::is_permutation(a.begin(), a.end(), b.begin());
}
```

## My Solutions
```cpp
#include <vector>
#include <cmath>

class Same {
public :
   static bool comp(std::vector<int>& a, std::vector<int>& b)
    {
      if ((a.size() && b.size() && a.size() == b.size()) || ((a.size() == 0) && (b.size() == 0)))
        {
            for (unsigned int ai = 0; ai < a.size(); ai++)
            {
                for (unsigned int bi = 0; bi < b.size(); bi++)
                {
                    if (b[bi] == (sqrt(b[bi]) * (sqrt(b[bi]))))
                    {
                        if ((a[ai] * a[ai]) == b[bi])
                        {
                            b.erase(b.begin() + bi);
                            break;
                        }
                        else if (bi + 1 == b.size())
                            return false;
                    }
                    else
                        return false;
                }
            }
            return true;
        }
        else
            return false;
     }
};
```
