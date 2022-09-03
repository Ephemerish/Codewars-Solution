Description:

Given an array of integers your solution should find the smallest integer.

For example :

Given[34, 15, 88, 2] your solution will return 2
Given[34, -345, -1, 100] your solution will return -345

You can assume, for the purpose of this kata, that the supplied array will not be empty.

#include <vector>

int findSmallest(std::vector <int> list)
{
    int smallest = list[0];

    for (int counter = 0; counter < list.size(); counter++)
        if (list[counter] < smallest) smallest = list[counter];

    return smallest;
}