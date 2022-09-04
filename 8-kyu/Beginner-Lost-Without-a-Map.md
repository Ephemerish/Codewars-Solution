## Description:

Given an array of integers, return a new array with each value doubled.

### For example :

    [1, 2, 3] --> [2, 4, 6]

**Kata's link:** [Beginner - Lost Without a Map](https://www.codewars.com/kata/57f781872e3d8ca2a000007e/cpp)

## Best Practices

**First:**
```cpp
std::vector<int> maps(const std::vector<int> & values) {
std::vector<int> result;
for(auto a:values)
{
  result.push_back(a*2);
}

return result;
}
```

**Second:**
```cpp
std::vector<int> maps(const std::vector<int> & values) {
  std::vector <int> v = values;
  std::transform(std::begin(v),std::end(v),std::begin(v),[](int x){return 2*x;});
  return v;
}
```

## My Solutions
```cpp
[1, 2, 3] -- > [2, 4, 6]

std::vector<int> maps(const std::vector<int> &values) 
{
    std::vector<int> output;
    for (unsigned long i = 0; i < values.capacity(); i++)
        output.push_back(values.at(i) * 2);
    return output;
}
```