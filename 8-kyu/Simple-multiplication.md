## Description:

This kata is about multiplying a given number by eight if it is an even numberand by nine otherwise.

**Kata's link:** [Simple multiplication](https://www.codewars.com/kata/583710ccaa6717322c000105/cpp)

## Best Practices

**First:**
```cpp
int simpleMultiplication(int a){
    return a % 2 ? 9*a : 8*a;
}
```

**Second:**
```cpp
#define 😂 a % 2
#define 🍆 a * 9
#define 💦 a * 8

int simpleMultiplication(int a) {
  return 😂 ? 🍆 : 💦;
}
```

## My Solutions
```cpp
int simpleMultiplication(int a) {
    return a % 2 ? a * 9 : a * 8;
}
```