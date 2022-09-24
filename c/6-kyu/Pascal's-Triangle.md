## Description

In mathematics, Pascal's triangle is a triangular array of the binomial coefficients expressed with formula

![Pascal's Triangle Formula](https://wikimedia.org/api/rest_v1/media/math/render/svg/203b128a098e18cbb8cf36d004bd7282b28461bf)

where `n` denotes a row of the triangle, and `k` is a position of a term in the row.

![Pascal's Triangle](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)


You can read [Wikipedia article](https://en.wikipedia.org/wiki/Pascal%27s_triangle) on Pascal's Triangle for more information.
Task

Write a function that, given a depth n, returns n top rows of Pascal's Triangle flattened into a one-dimensional list/array.
Example:

```
n = 1: [1]
n = 2: [1,  1, 1]
n = 4: [1,  1, 1,  1, 2, 1,  1, 3, 3, 1]
```

### Note

Beware of overflow. Requested terms of a triangle are guaranteed to fit into the returned type, but depending on seleced method of calculations, intermediate values can be larger.


**Kata's link:** [Pascal's Triangle](https://www.codewars.com/kata/5226eb40316b56c8d500030f/cpp)

## Best Practices

**First:**
```c
void pascals_triangle (unsigned n, unsigned triangle[n * (n + 1) / 2]) {
  int m = 0;
  for (unsigned int i = 0; i < n; i++) {
    unsigned long num = 1;
    for (unsigned int j = 0; j <= i; j++) {
      triangle[m++] = num;
      num = (num * (i-j)) / (j+1);
    }
  }
}
```

**Second:**
```c
void pascals_triangle (unsigned n, unsigned triangle[n * (n + 1) / 2])
{
    n++;
    triangle[0] = 1;

    int index = 0;
    int prevStart = 0, prevEnd = 0;
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < row; column++)
        {
            if (column == 0)
            {
                triangle[index] = 1;
                index++;
            }
            else if (column + 1 == row)
            {
                prevEnd = index;
                triangle[index] = 1;
                index++;
            }
            else
            {
                //index++;
                prevStart = prevEnd - row+2;
                while (prevStart < prevEnd)
                {
                    triangle[index] = triangle[prevStart] + triangle[prevStart + 1];
                    prevStart++;
                    index++;
                    column++;
                }
                column--;
            }      
        }
    }
}
```

## My Solutions
```c
void pascals_triangle (unsigned n, unsigned triangle[n * (n + 1) / 2])
{
    n++;
    triangle[0] = 1;

    int index = 0;
    int prevStart = 0, prevEnd = 0;
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < row; column++)
        {
            if (column == 0)
            {
                triangle[index] = 1;
                index++;
            }
            else if (column + 1 == row)
            {
                prevEnd = index;
                triangle[index] = 1;
                index++;
            }
            else
            {
                //index++;
                prevStart = prevEnd - row+2;
                while (prevStart < prevEnd)
                {
                    triangle[index] = triangle[prevStart] + triangle[prevStart + 1];
                    prevStart++;
                    index++;
                    column++;
                }
                column--;
            }      
        }
    }
}
```
