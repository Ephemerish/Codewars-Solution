Description:

When provided with a number between 0 - 9, return it in words.

Input :: 1

Output :: "One".

If your language supports it, try using a switch statement.

#include <string>

std::string switch_it_up(int number) {
	std::string result[10] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
	return result[number];
}