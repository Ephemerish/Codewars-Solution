//Description:
//
//If you can't sleep, just count sheep!!
//Task :
//
//	Given a non - negative integer, 3 for example, return a string with a murmur : "1 sheep...2 sheep...3 sheep...".Input will always be valid, i.e.no negative integers.

#include <string>

std::string countSheep(int number) {
    std::string murmur;
    for (int sheep = 1; sheep <= number; sheep++)
    {
        murmur += std::to_string(sheep) + " sheep...";
    }
    return murmur;
}