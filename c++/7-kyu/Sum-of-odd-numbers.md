## Description

Given the triangle of consecutive odd numbers:

               1
            3     5
          7    9    11
       13    15    17    19
    21    23    25    27    29
    ...

Calculate the sum of the numbers in the nth row of this triangle (starting at index 1) e.g.: (Input --> Output)

    1 -->  1
    2 --> 3 + 5 = 8

**Kata's link:** [Sum of odd numbers](https://www.codewars.com/kata/55fd2d567d94ac3bc9000064/cpp)

## Best Practices

**First:**
```cpp
long long rowSumOddNumbers(unsigned n){
  //n - элементов на уровне n
  //1+2+3+4+5+...+n= (n+1)n/2 - элементов в пирамиде из n уровней
  //0+1+2+3+4+...+(n-1) = (n-1)n/2 - столько раз прибавляется 2 к предыдущему числу
  //1+(n-1)n - с этого элемента начинается уровень n
  //[1+(n-1)n]+[1+(n-1)n+2]+[1+(n-1)n+4]+...+[1+(n-1)n+2(n-1)] - элементы последнего уровня
  //([1+(n-1)n] + [1+(n-1)n+2(n-1)])n/2 = n^3
    
  return (long long)n*n*n;
}
```

**Second:**
```cpp
long long rowSumOddNumbers(unsigned n){
//Well it's just n^3, 1^3 = 1,  2^3 = 8, 3^3 = 27 etc.
  return n*n*n;
}
```

## My Solutions
```cpp
long long rowSumOddNumbers(unsigned n) {
    long result = 0;
    long layerSum = 0;
    long currentOdd = -1;
    for (int x = 0; x < n; x++)
    {
        layerSum = 0;
        for (int y = 0; y <= x; y++)
        {
            currentOdd += 2;
            layerSum += currentOdd;
        }
    }
    result = layerSum;
    return result;
}
```
