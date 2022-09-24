## Description

The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal representation being returned. Valid decimal values for RGB are 0 - 255. Any values that fall out of that range must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.

The following are examples of expected output values:

```c
char output[7] = {0};

rgb(255, 255, 255, output); 
output == "FFFFFF";

rgb(255, 255, 300, output); 
output == "FFFFFF";

rgb(0, 0, 0, output); 
output == "000000";

rgb(148, 0, 211, output);
output == "9400D3";
```

**Kata's link:** [RGB To Hex Conversion](https://www.codewars.com/kata/513e08acc600c94f01000001/cpp)

## Best Practices

**First:**
```c
unsigned char wrap(int a)
{
   if(a>255) return 255;
   else if(a<0) return 0;
   else return a;
}
int rgb(int r, int g, int b, char *output)
{
   sprintf(output,"%02X%02X%02X\0",wrap(r),wrap(g),wrap(b));
   return 0; 
}
```

**Second:**
```c
char GetHexDigit( int x )
{
  if( x <= 9)
  {
    return '0' + x;
  }
  else
  {
    return 'A' + ( x - 10 );
  }
}

void GetHex( int x, char* output)
{
  if( x < 0 ) x = 0;
  if( x > 255 ) x = 255; 
  int a = x/16;
  int b = x%16;
  output[0] = GetHexDigit( a );
  output[1] = GetHexDigit( b );
}

int rgb(int r, int g, int b, char *output)
{
   GetHex(r, output );
   GetHex(g, output + 2 );
   GetHex(b, output + 4 );
   return 0; 
}
```

## My Solutions
```c
#include <stdio.h>

int rgb(int r, int g, int b, char *output)
{
  *output = 0;
  int values[3] = {r,g,b};
    char temp[3] = "";
   
    for (int i = 0; i < 3; i++)
    {
      
       if(values[i] > 255)
       {
           values[i] = 255;
       }
       else if(values[i] < 0)
       {
           values[i] = 0;
       }
      
       sprintf(temp,"%02X",values[i]);
       strcat(output,temp);
    }
   return 0; 
}
```
