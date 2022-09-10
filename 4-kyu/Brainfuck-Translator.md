## Description

### Introduction

Brainfuck is one of the most well-known esoteric programming languages. But it can be hard to understand any code longer that 5 characters. In this kata you have to solve that problem.

### Description

In this kata you have to write a function which will do 3 tasks:

1. Optimize the given Brainfuck code.
2. Check it for mistakes.
3. Translate the given Brainfuck programming code into C programming code.

More formally about each of the tasks:

1. Your function has to remove from the source code all useless command sequences such as: '+-', '<>', '[]'. Also it must erase all characters except +-<>,.[].

        Example:
         "++--+." -> "+."
        "[][+++]" -> "[+++]"
         "<>><" -> ""

2. If the source code contains unpaired braces, your function should return `"Error!"` string.
3. Your function must generate a string of the C programming code as follows:

    1. Sequences of the X commands + or - must be replaced by \*p += X;\n or \*p -= X;\n.

             Example:
            "++++++++++" -> "\*p += 10;\n"
             "------" -> "\*p -= 6;\n"

    2. Sequences of the Y commands > or < must be replaced by p += Y;\n or p -= Y;\n.

            Example:
            ">>>>>>>>>>" -> "p += 10;\n"
             "<<<<<<" -> "p -= 6;\n"

    3. . command must be replaced by putchar(\*p);\n.

            Example:
            ".." -> "putchar(\*p);\nputchar(\*p);\n"

    4. , command must be replaced by \*p = getchar();\n.

            Example:
             "," -> "\*p = getchar();\n"

    5. [ command must be replaced by if (\*p) do {\n. ] command must be replaced by } while (\*p);\n.

            Example:
            "[>>]" ->
             if (\*p) do {\n
              p += 2;\n
            } while (\*p);\n

    6. Each command in the code block must be shifted 2 spaces to the right accordingly to the previous code block.

            Example:
            "[>>[<<]]" ->
            if (\*p) do {\n
              p += 2;\n
              if (\*p) do {\n
                p -= 2;\n
              } while (\*p);\n
            } while (\*p);\n

## Examples

    Input:
    +++++[>++++.<-]
    Output:
    *p += 5;
    if (*p) do {
      p += 1;
      *p += 4;
      putchar(*p);
      p -= 1;
      *p -= 1;
    } while (*p);


**Kata's link:** [Brainfuck Translator](https://www.codewars.com/kata/58924f2ca8c628f21a0001a1/cpp)

## Best Practices

**First:**
```cpp

```

**Second:**
```cpp

```

## My Solutions
```cpp
#include <string> // std::string

void optimizeBrainfuck(std::string& str);

std::string brainfuck_to_c(std::string source_code)
{
	//std::cout << "\n" << source_code << std::endl;
	std::string result;

	optimizeBrainfuck(source_code);

	if (source_code != "Error!")
	{
		int temp = 0;
		int tabs = 0;
		//fix the Tab system TY
		std::cout << "optimize = " << source_code << "\n\n";
		for (unsigned long i = 0; i < source_code.size(); i++)
		{
			switch (source_code[i])
			{
			case '+':
				temp = 0;
				for (int tabCounter = 0; tabCounter < tabs; tabCounter++)
					result += "  ";
				while (source_code[i] == '+')
				{
					temp++;
					i++;
				}
				i--;
				result += "\*p += " + std::to_string(temp) + ";\n";
				break;

			case '-':
				temp = 0;
				for (int tabCounter = 0; tabCounter < tabs; tabCounter++)
					result += "  ";
				while (source_code[i] == '-')
				{
					temp++;
					i++;
				}
				i--;
				result += "\*p -= " + std::to_string(temp) + ";\n";
				break;

			case '>':
				temp = 0;
				for (int tabCounter = 0; tabCounter < tabs; tabCounter++)
					result += "  ";
				while (source_code[i] == '>')
				{
					temp++;
					i++;
				}
				i--;
				result += "p += " + std::to_string(temp) + ";\n";
				break;

			case '<':
				temp = 0;
				for (int tabCounter = 0; tabCounter < tabs; tabCounter++)
					result += "  ";
				while (source_code[i] == '<')
				{
					temp++;
					i++;
				}
				i--;
				result += "p -= " + std::to_string(temp) + ";\n";
				break;

			case '.':
				for (int tabCounter = 0; tabCounter < tabs; tabCounter++)
					result += "  ";
				result += "putchar(\*p);\n";
				break;

			case ',':
				for (int tabCounter = 0; tabCounter < tabs; tabCounter++)
					result += "  ";
				result += "\*p = getchar();\n";
				break;

			case '[':
				for (int tabCounter = 0; tabCounter < tabs; tabCounter++)
					result += "  ";
				tabs++;
				result += "if (\*p) do {\n";
				break;

			case ']':
				tabs--;
				for (int tabCounter = 0; tabCounter < tabs; tabCounter++)
					result += "  ";
				result += "} while (\*p);\n";
				break;
			}
		}
		return result;
	}
	else
	{
		//std::cout << optimize << std::endl;
		return source_code;
	}
}

void optimizeBrainfuck(std::string& source_code)
{
	int braceCounter = 0;
	int braceCounter2 = 0;

	std::string temp;
	unsigned long long loopSize = source_code.size();
	for (unsigned long long i = 0; i < loopSize; i++)
	{
		if (!(source_code[i] == '+' ||
			source_code[i] == '-' ||
			source_code[i] == '<' ||
			source_code[i] == '>' ||
			source_code[i] == '.' ||
			source_code[i] == ',' ||
			source_code[i] == '[' ||
			source_code[i] == ']'))
		{
			source_code.erase(source_code.begin() + i);
			i -= 2;
			loopSize--;
			continue;
		}

		temp += source_code[i];
		temp += source_code[i + 1];
		if (temp == "+-" || temp == "-+" || temp == "<>" || temp == "><" || temp == "[]")
		{
			source_code.erase(source_code.begin() + i, source_code.begin() + i + 2);
			braceCounter = 0;
			braceCounter2 = 0;
			i = -1;
			temp.clear();
			loopSize -= 2;
			continue;
		}
		temp.clear();

		if (source_code[i] == '[')
			braceCounter++;
		if (source_code[i] == ']')
			braceCounter2++;
		if (braceCounter < braceCounter2)
			source_code = "Error!";
	}

	if ((braceCounter + braceCounter2) % 2 != 0)
		source_code = "Error!";
}
```
