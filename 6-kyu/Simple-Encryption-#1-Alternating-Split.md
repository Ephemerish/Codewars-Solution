## Description

Implement a pseudo-encryption algorithm which given a string S and an integer N concatenates all the odd-indexed characters of S with all the even-indexed characters of S, this process should be repeated N times.

### Examples:

    encrypt("012345", 1)  =>  "135024"
    encrypt("012345", 2)  =>  "135024"  ->  "304152"
    encrypt("012345", 3)  =>  "135024"  ->  "304152"  ->  "012345"

    encrypt("01234", 1)  =>  "13024"
    encrypt("01234", 2)  =>  "13024"  ->  "32104"
    encrypt("01234", 3)  =>  "13024"  ->  "32104"  ->  "20314"

Together with the encryption function, you should also implement a decryption function which reverses the process.

If the string `S` is an empty value or the integer `N` is not positive, return the first argument without changes.

**Kata's link:** [Simple Encryption #1 - Alternating Split](https://www.codewars.com/kata/57814d79a56c88e3e0000786/cpp)

## Best Practices

**First:**
```cpp
std::string encrypt(std::string text, int n)
{
    if (n <= 0) return text;

    const unsigned stringSize = text.size();
    
    for (unsigned i = 0; i < n; i++) 
    {
        std::string eText;
        
        for (unsigned j = 1; j < stringSize; j += 2)
            eText.push_back(text[j]); 
        for (unsigned j = 0; j < stringSize; j += 2)
            eText.push_back(text[j]);
            
        text = eText;
    }

    return text;
}

std::string decrypt(std::string text, int n)
{
    if (n <= 0) return text;

    const unsigned stringSize = text.size();
    const unsigned stringSizeHalf = stringSize / 2;
    
    for (unsigned i = 0; i < n; i++) 
    {
        std::string dText;
        
        for (unsigned j = 0; j < stringSizeHalf; j++) 
        {
            dText.push_back(text[j+stringSizeHalf]);
            dText.push_back(text[j]);
        }
        
        if (stringSize & 1)
            dText.push_back(text[stringSize - 1]);
            
        text = dText;
    }
 
    return text;
}
```

**Second:**
```cpp
std::string encryptOnce(std::string text)
{std::string tmpString = "";

  for(int i=1; i<text.size(); i+=2)
  {
    tmpString += text.at(i);
  }

  for(int i=0; i<text.size(); i+=2)
  {
    tmpString += text.at(i);
  }
  
  return tmpString;
}

std::string encrypt(std::string text, int n)
{
  if(text.empty() || n<=0)
  {
    return text;
  }

  for(int i=0; i<n; i++)
  {
    text = encryptOnce(text);
  }

  return text;
}

std::string decryptOnce(std::string encryptedText, int evenCharCount)
{
  std::string tmpString = encryptedText;
  int counter = 0;
  
  for(int i=0; i<encryptedText.size(); i++)
  {
    if(i<evenCharCount)
      tmpString.at(2*i+1) = encryptedText.at(i);
    else
    {
      tmpString.at(counter) = encryptedText.at(i);
      counter += 2;
    }
  }
  return tmpString;
}

std::string decrypt(std::string encryptedText, int n)
{
  if(encryptedText.empty() || n<=0)
  {
    return encryptedText;
  }

  std::cout << "encryptedText.size() = " << encryptedText.size() << std::endl;
  int evenCharCount = (encryptedText.size() - encryptedText.size()%2)/2;
  std::cout << "evenCharCount = " << evenCharCount << std::endl;
  
    for(int i=0; i<n; i++)
  {
    std::cout << "input text = " << encryptedText << std::endl;
    encryptedText = decryptOnce(encryptedText, evenCharCount);
  }

    return encryptedText;
}
```

## My Solutions
```cpp
std::string encrypt(std::string text, int n)
{
  for(int nTimes = 0; nTimes < n; nTimes++)
  {
    std::string tempOdd = "", tempEven = "";
    for(uint i = 0; i < text.length(); i++)
    {
      if(i%2)
        tempOdd += text[i];
      else
        tempEven += text[i];
    }
    text = tempOdd + tempEven;
  }
  return text;
}

std::string decrypt(std::string encryptedText, int n)
{
  int mid = encryptedText.length() / 2;
  int index = 0;
  std::string result = "";
  if (n <= 0 || mid == 0)
    return encryptedText;
  int trial = encryptedText.length() % 2 == 1 ? mid + 1 : mid;
  for (int i = 0; i < trial; i++)
  {
    result += encryptedText[mid + index];
    if (index < mid)
      result += encryptedText[index ];
    index++;
  }
  if (n == 1)
    return result;
  else
    return decrypt(result, n - 1);
}
```
