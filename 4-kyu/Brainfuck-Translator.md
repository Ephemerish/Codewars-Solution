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
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string brainfuck_to_c(string s) {
  vector<char> stack;
  int brackets = 0;
  for (int i = 0; i < s.length(); i++) {
    switch (s[i]) {
      case '[':
        brackets++;
      case ',':
      case '.':
        stack.push_back(s[i]);
        break;
      case ']':
        brackets--;
        if (brackets < 0) return "Error!";
        if (stack.back() == '[') stack.pop_back();
        else stack.push_back(s[i]);
        break;
      case '+':
        if (stack.size() == 0 || stack.back() != '-') stack.push_back(s[i]);
        else stack.pop_back();
        break;
      case '-':
        if (stack.size() == 0 || stack.back() != '+') stack.push_back(s[i]);
        else stack.pop_back();
        break;
      case '>':
        if (stack.size() == 0 || stack.back() != '<') stack.push_back(s[i]);
        else stack.pop_back();
        break;
      case '<':
        if (stack.size() == 0 || stack.back() != '>') stack.push_back(s[i]);
        else stack.pop_back();
        break;
    }
  }
  if (brackets != 0) return "Error!";
  string result = "";
  int indent = 0, count;
  for (int i = 0; i < stack.size(); i++) {
    switch (stack[i]) {
      case '[':
        result += string(indent, ' ') + "if (*p) do {\n";
        indent += 2;
        break;
      case ']':
        indent -= 2;
        result += string(indent, ' ') + "} while (*p);\n";
        break;
      case ',':
        result += string(indent, ' ') + "*p = getchar();\n";
        break;
      case '.':
        result += string(indent, ' ') + "putchar(*p);\n";
        break;
      case '+':
        count = 0;
        while (i < stack.size() && stack[i] == '+') {
          count++;
          i++;
        }
        i--;
        result += string(indent, ' ') + "*p += " + to_string(count) + ";\n";
        break;
      case '-':
        count = 0;
        while (i < stack.size() && stack[i] == '-') {
          count++;
          i++;
        }
        i--;
        result += string(indent, ' ') + "*p -= " + to_string(count) + ";\n";
        break;
      case '>':
        count = 0;
        while (i < stack.size() && stack[i] == '>') {
          count++;
          i++;
        }
        i--;
        result += string(indent, ' ') + "p += " + to_string(count) + ";\n";
        break;
      case '<':
        count = 0;
        while (i < stack.size() && stack[i] == '<') {
          count++;
          i++;
        }
        i--;
        result += string(indent, ' ') + "p -= " + to_string(count) + ";\n";
        break;
    }
  }
  return result;
}
```

**Second:**
```cpp
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

bool is_valid_opcode(unsigned char opcode)
{
  switch(opcode)
  {
  case '+': case '-':
  case '<': case '>':
  case ',': case '.':
  case '[': case ']':
    return true;
  default:
    return false;
  }
}

std::string optimize(const std::string & source_code)
{
  std::string optimized;
  
  // remove invalid opcodes
  std::copy_if(std::begin(source_code), std::end(source_code), std::back_inserter(optimized), is_valid_opcode);
  
  // keep removing useless sequences while we can
  while(true)
  {
    bool found_sequence = false;
    
    std::string current_pass;
    
    // this is the maximum string size we'll need
    current_pass.reserve(optimized.length());
    
    for (int i = 0; i < optimized.length(); i++)
    {
      // handle the last opcode
      if (i == optimized.length() - 1)
      {
        current_pass.push_back(optimized[i]);
      }
      else
      {
        auto current = optimized[i], next = optimized[i + 1];
      
        // for useless pairs, just skip over them
        if (current == '+' && next == '-') {
          found_sequence = true;
          i++;
        } else if (current == '-' && next == '+') {
          found_sequence = true;
          i++;
        } else if (current == '<' && next == '>') {
          found_sequence = true;
          i++;
        } else if (current == '>' && next == '<') {
          found_sequence = true;
          i++;
        } else if (current == '[' && next == ']') {
          found_sequence = true;
          i++;
        } else {
          current_pass.push_back(current);
        }
      }
    }
    
    // the current pass becomes the now optimized version
    std::swap(current_pass, optimized);
    
    // if we found no more sequences then stop performing any more passes
    if (!found_sequence)
      break;
  }
  
  return optimized;
}

bool braces_valid(const std::string & source_code)
{
  int open_braces = 0;
  
  for (auto c : source_code)
  {
    if (c == '[')
    {
      open_braces++;
    }
    else if (c == ']')
    {
      // check if we encountered a closing brace without any
      // corresponding opening brace
      if (open_braces == 0)
      {
        return false;
      }
      
      open_braces--;
    }
  }
  
  // ensure that all open braces were closed
  return open_braces == 0;
}

int count_chars(std::string::const_iterator & pos, std::string::const_iterator end, unsigned char c)
{
  int counter = 0;
  
  while (pos != end && *pos == c) {
    counter++;
    pos++;
  }
  
  return counter;
}

struct translation_state
{
  translation_state(std::string::const_iterator _pos, std::string::const_iterator _end) :
    pos(_pos), end(_end), indent_level(0)
  {}
  
  bool complete() { return pos == end; }
  void advance() { pos++; }
  
  std::string::const_iterator pos;
  std::string::const_iterator end;
  int indent_level;
};

std::string translate_opcodes(translation_state & state)
{
  std::ostringstream output;
  
  // handle indentation first
  if (*state.pos == ']') {
    state.indent_level--;
  }
  
  output << std::string(state.indent_level * 2, ' ');
  
  if (*state.pos == '[') {
    state.indent_level++;
  }
  
  // then translate each opcode
  switch(*state.pos)
  {
    case '.':
      state.advance(); output << "putchar(*p);\n"; break;
    case ',':
      state.advance(); output << "*p = getchar();\n"; break;
    case '[':
      state.advance(); output << "if (*p) do {\n"; break;
    case ']':
      state.advance(); output << "} while (*p);\n"; break;
    case '+':
      output << "*p += " << count_chars(state.pos, state.end, '+') << ";\n"; break;
    case '-':
      output << "*p -= " << count_chars(state.pos, state.end, '-') << ";\n"; break;
    case '>':
      output << "p += " << count_chars(state.pos, state.end, '>') << ";\n"; break;
    case '<':
      output << "p -= " << count_chars(state.pos, state.end, '<') << ";\n"; break;
  }
  
  return output.str();
}

std::string brainfuck_to_c(const std::string & source_code)
{
  std::string result = optimize(source_code);
  
  if (!braces_valid(result)) {
    return "Error!";
  }
  
  std::ostringstream output;
  
  translation_state state{std::cbegin(result), std::cend(result)};
  
  while(!state.complete()) {
    output << translate_opcodes(state);
  }
  
  return output.str();
}
```

## My Solutions
```cpp
//Warning this code is not fully optimized
//but this do work until super_input
//soo...
#include <string> 
#include <vector>

void optimizeBrainfuck(std::string& str, std::string& result);

std::string brainfuck_to_c(std::string source_code)
{
	std::string optimized;
	std::string result;

	//remove unnecessary characters
	optimizeBrainfuck(source_code, optimized);

	if (optimized != "Error!")
	{
		//trasform the code from brainfuck to c 
		int temp = 0;
		int tabs = 0;
		for (unsigned long long i = 0; i < optimized.size(); i++)
		{
			switch (optimized[i])
			{
			case '+':
				temp = 0;
				for (int tabCounter = 0; tabCounter < tabs; tabCounter++)
					result += "  ";
				while (optimized[i] == '+')
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
				while (optimized[i] == '-')
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
				while (optimized[i] == '>')
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
				while (optimized[i] == '<')
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
		return optimized;
	}
}
void optimizeBrainfuck(std::string& source_code, std::string& optimized)
{
	int braceCounter = 0;
	int braceCounter2 = 0;
	std::string temp;
	unsigned long long loopSize = source_code.size();
	optimized.reserve(loopSize);
	for (unsigned long long i = 0; i < loopSize; i++)
	{
		//remove all irrelevant characters
		if (source_code[i] == '+' ||
			source_code[i] == '-' ||
			source_code[i] == '<' ||
			source_code[i] == '>' ||
			source_code[i] == '.' ||
			source_code[i] == ',' ||
			source_code[i] == '[' ||
			source_code[i] == ']')
		{
			// remove cancelling characters
			temp.clear();
			temp += source_code[i];
			temp += source_code[i + 1];
			if (!(temp == "+-" || temp == "-+" || temp == "<>" || temp == "><" || temp == "[]"))
			{
				optimized += source_code[i];

				if (source_code[i] == '[')
					braceCounter++;
				if (source_code[i] == ']')
					braceCounter2++;
				if (braceCounter < braceCounter2)
					source_code = "Error!";
			}
			else
				i++;
		}
	}

	source_code.clear();

	if ((braceCounter + braceCounter2) % 2 == 0)
	{
		//removal redundancy because I am an idiot
		for (unsigned long i = 0; i < optimized.size(); i++)
		{
			temp.clear();
			temp += optimized[i];
			temp += optimized[i + 1];
			if (temp == "+-" || temp == "-+" || temp == "<>" || temp == "><" || temp == "[]")
			{
				optimized.erase(optimized.begin() + i, optimized.begin() + i + 2);
				i = -1;

			}
		}
	}
	else
		optimized = "Error!";
}
```
