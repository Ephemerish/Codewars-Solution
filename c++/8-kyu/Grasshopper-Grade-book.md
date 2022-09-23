## Description

Grade book

Complete the function so that it finds the average of the three scores passed to it and returns the letter value associated with that grade.

    Numerical Score 	    Letter Grade
    90 <= score <= 100 	    'A'
    80 <= score < 90 	    'B'
    70 <= score < 80 	    'C'
    60 <= score < 70 	    'D'
    0 <= score < 60 	    'F'

Tested values are all between 0 and 100. Theres is no need to check for negative values or values greater than 100.


**Kata's link:** [Grasshopper - Grade book](https://www.codewars.com/kata/55cbd4ba903825f7970000f5/cpp)

## Best Practices

**First:**
```cpp
char getGrade(int a, int b, int c) {
  int avg = (a + b + c) / 3;
  switch(avg){
  case 90 ... 100: return 'A';
  case 80 ... 89: return 'B';
  case 70 ... 79: return 'C';
  case 60 ... 69: return 'D';
  default: return 'F';
  }
}
```

**Second:**
```cpp
char getGrade(int a, int b, int c) {
  auto score = (a + b + c) / 3;
  if (score >= 90) return 'A';
  if (score >= 80) return 'B';
  if (score >= 70) return 'C';
  if (score >= 60) return 'D';
  return 'F';
}
```

## My Solutions
```cpp
char getGrade(int a, int b, int c)
{
  int average = (a + b + c)/3;
  
  if(average >= 90 && average <= 100)
    return 'A';
  else if (average >= 80 && average <= 90)
    return 'B';
  else if (average >= 70 && average <= 80)
    return 'C';
  else if (average >= 60 && average <= 70)
    return 'D';
  else if (average >=  0 && average <= 60)
    return 'F';
  else
    return -1;
}
```
