## Description

Take the following IPv4 address: `128.32.10.1`

This address has 4 octets where each octet is a single byte (or 8 bits).

* 1st octet `128` has the binary representation: `10000000`
* 2nd octet `32` has the binary representation: `00100000`
* 3rd octet `10` has the binary representation: `00001010`
* 4th octet `1`has the binary representation: `00000001`

So `128.32.10.1` == `10000000.00100000.00001010.00000001`

Because the above IP address has 32 bits, we can represent it as the unsigned 32 bit number: `2149583361`

Complete the function that takes an unsigned 32 bit number and returns a string representation of its IPv4 address.

### Examples

    2149583361 ==> "128.32.10.1"
    32         ==> "0.0.0.32"
    0          ==> "0.0.0.0"

**Kata's link:** [int32 to IPv4](https://www.codewars.com/kata/52e88b39ffb6ac53a400022e/cpp)

## Best Practices

**First:**
```cpp
std::string uint32_to_ip(uint32_t ip) {
  std::string result;
  
  uint32_t mask4 = (0xff);        // 00000000 00000000 00000000 11111111
  uint32_t mask3 = (0xff00);      // 00000000 00000000 11111111 00000000
  uint32_t mask2 = (0xff0000);    // 00000000 11111111 00000000 00000000
  uint32_t mask1 = (0xff000000);  // 11111111 00000000 00000000 00000000
    
  result += std::to_string((ip & mask1) >> 24);
  result += '.';
  result += std::to_string((ip & mask2) >> 16);
  result += '.';
  result += std::to_string((ip & mask3) >> 8);
  result += '.';
  result += std::to_string(ip & mask4);
  
  return result;
}
```

**Second:**
```cpp
#include <arpa/inet.h>

std::string uint32_to_ip(uint32_t ip)
{
    in_addr addr;
    addr.s_addr = htonl(ip);
    return {inet_ntoa(addr)};  
}
```

## My Solutions
```cpp
std::string uIntToStingBinary(int num)
{
  std::string str = "";
  // Size of an integer is assumed to be 32 bits
  for (int i = 31; i >= 0; i--) {
    int k = num >> i;
    if (k & 1)
      str += "1";
    else
      str += "0";
  }
  return str;
}

int binaryStringToInt(std::string str)
{
  int temp = 0;
  int power = 1;
  int octetBitSize = 8;
  for (int x = 0; x < octetBitSize; x++)
  {
    temp += (str[(8 - 1) - x] - 48) * power;
    power *= 2;
  }
  return temp;
}

std::string uint32_to_ip(uint32_t ip)
{
  //covert the unsigned int to string binary
  std::string binary = uIntToStingBinary(ip);
  std::string result = "";

  int bitSize = 32;
  int octet = 0;
  for (int i = 0; i < bitSize; i += 8)
  {
    //count the current octet's number
    octet++;
    //get the octets 8 bits
    std::string currentOctet = "";
    currentOctet = binary.substr(i, 8);

    //covert the string-binary to an integer
    //then add it to the result
    result += std::to_string(binaryStringToInt(currentOctet));
    if (octet < 4)
      result += ".";
  }
  return result;
}
```
