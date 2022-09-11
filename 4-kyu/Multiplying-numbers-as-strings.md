## Description

This is the first part. You can solve the second part here when you are done with this. Multiply two numbers! Simple!

1. The arguments are passed as strings.
   
2. The numbers may be way very large
   
3. Answer should be returned as a string
   
4. The returned "number" should not start with zeros e.g. 0123 is invalid

Note: 100 randomly generated tests!


**Kata's link:** [Multiplying numbers as strings](https://www.codewars.com/kata/55911ef14065454c75000062/cpp)

## Best Practices

**First:**
```cpp
#include <iostream>
#include <string>

using namespace std;

string multiply(const string &t, const string &b)
{
    int tsize = static_cast<int>(t.size());
    int bsize = static_cast<int>(b.size());
  
    vector<size_t> pos(static_cast<size_t>(tsize + bsize), 0);
    for (int i = tsize - 1; i >= 0; i--){
        for (int j = bsize - 1; j >= 0; j--){
            int mul = (t[i] - '0') * (b[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + pos[p2];
            pos[p1] += sum / 10;
            pos[p2] = sum % 10;
        }
    }
    string res;
    for (const auto& p : pos) if (!(res.size() == 0 && p == 0)) res.push_back('0'+p);
    
    return (res.size() == 0)? "0" : res;
}
```

**Second:**
```cpp
include <string>

using namespace std;


string add(string v1, string v2)
{
   const auto v1size = v1.size();
   const auto v2size = v2.size();
   const auto size = max(v1size, v2size)+1;
   v1.insert(0,size-v1size,'0');
   v2.insert(0,size-v2size,'0');
   auto v1it = v1.rbegin();
   for(auto v2it = v2.rbegin(); v2it!= v2.rend(); ++v2it)
   {
     *v1it += *v2it -'0';
     if (*v1it - '0' >= 10)
     {
       *v1it -= 10;
       ++(*(++v1it));
     }
    else
     ++v1it;
   }
   while(v1.front() == '0') v1.erase(0,1);
   if (v1.empty()) v1="0";
   return v1;
}

string operator<<(string str, int s)
{
  for (auto i = s; i!=0; --i ) str.push_back('0');
  return str;
}

string multiply(string a, string b)
{
   string ret;
   auto shift = 0;
   for(auto itb = b.rbegin(); itb!=b.rend(); ++itb)
   {
     auto carry = 0;
     string ret_;
     for(auto ita = a.rbegin(); ita!=a.rend(); ++ita)
     {
        auto p = (*itb - '0') * (*ita - '0') + carry;
        ret_.insert(0, 1, (p % 10)+'0');
        carry = p / 10;
     }
     if (carry) ret_.insert(0, 1, carry+'0');
     ret = add(ret,  (ret_ << shift++ ));
   }
   return ret;
}
```

## My Solutions
```cpp
#include <iostream>
#include <string>
#include <vector>

std::string multiply(std::string a, std::string b) {
    std::vector<int> v(a.length() + b.length(), 0);
    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            v[i + j + 1] += (a[i] - '0') * (b[j] - '0');
        }
    }

    for (int i = a.length() + b.length() - 1; i > 0; i--) {
        v[i - 1] += v[i] / 10;
        v[i] %= 10;
    }

    int i = 0;
    while (i < v.size() && v[i] == 0) i++;

    std::string str = "";
    while (i < v.size()) str += std::to_string(v[i++]);
    if (str == "") return "0";
    else return str;
}
```
