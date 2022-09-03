//Description:
//
//Implement a function that adds two numbers togetherand returns their sum in binary.The conversion can be done before, or after the addition.
//
//The binary number returned should be a string.
//
//Examples : (Input1, Input2-- > Output(explanation)))
//
//1, 1 -- > "10" (1 + 1 = 2 in decimal or 10 in binary)
//5, 9 -- > "1110" (5 + 9 = 14 in decimal or 1110 in binary)

#include <cstdint>
#include <bits/stdc++.h>
#include <string>

std::string add_binary(uint64_t a, uint64_t b) {
	if (a + b == 0) return "0";
	long int n = (long int)(log2(a + b));
	return std::bitset<64>(a + b).to_string().substr(64 - n - 1);