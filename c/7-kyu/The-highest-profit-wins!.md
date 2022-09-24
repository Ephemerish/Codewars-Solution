## Description

### Story

Ben has a very simple idea to make some profit: he buys something and sells it again. Of course, this wouldn't give him any profit at all if he was simply to buy and sell it at the same price. Instead, he's going to buy it for the lowest possible price and sell it at the highest.

### Task

Write a function that returns both the minimum and maximum number of the given list/array.
Examples (Input --> Output)

```c
[1,2,3,4,5] --> [1,5]
[2334454,5] --> [5,2334454]
[1]         --> [1,1]
```

### Remarks

All arrays or lists will always have at least one element, so you don't need to check the length. Also, your function will always get an array or a list, you don't have to check for `null`, `undefined` or similar.


**Kata's link:** [The highest profit wins!](https://www.codewars.com/kata/559590633066759614000063/cpp)

## Best Practices

**First:**
```c
void min_max (const int arr[], int count, int *min, int *max)
{
    *min = *max = arr[0];
  while(count!=0)
  {
    count--;
    *min = (*min>arr[count]) ? arr[count] : *min;
    *max = (*max<arr[count]) ? arr[count] : *max;
  }
}
```

**Second:**
```c
#include <stdlib.h>

void min_max (const int arr[], int count, int *min, int *max)
{
  *min = *max = arr[0];
  for (int i = 0; i < count; i++) {
    if (arr[i] > *max) {
      *max = arr[i];
    } else if (arr[i] < *min) {
      *min = arr[i];
    }
  }
}
```

## My Solutions
```c
void min_max (const int arr[], int count, int *min, int *max)
{
  *min = *max = arr[0];
  for(int i = 0; i < count; i++)
  {
    if(arr[i] < *min)
    {
      *min = arr[i];
    }
    else if(arr[i] > *max)
    {
      *max = arr[i];
    }
  }
}
```
