## Description:

Your classmates asked you to copy some paperwork for them.You know that there are 'n' classmates and the paperwork has 'm' pages.

Your task is to calculate how many blank pages do you need.If `n < 0` or `m < 0` return `0`.

### Example :

	n = 5, m = 5 : 25
	n = -5, m = 5 : 0

**Kata's link:** [Beginner Series 1 School Paperwork](https://www.codewars.com/kata/55f9b48403f6b87a7c0000bd/cpp)

## Best Practices

**First:**
```cpp
int paperwork(int n, int m) {
  return n < 0 || m < 0 ? 0 : n * m;
}
```

**Second:**
```cpp
int paperwork(int n, int m){
  if(n<1||m<1)
    return 0;
  else return n*m;
}
```

## My Solutions
```cpp
int paperwork(int n, int m)
{
	if (n > 0 && m > 0)
		return m * n;
	else
		return 0;
}