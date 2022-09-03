Description:

Given an array of integers, return a new array with each value doubled.

For example :

[1, 2, 3] -- > [2, 4, 6]

std::vector<int> maps(const std::vector<int> &values) {
    std::vector<int> output;
    for (unsigned long i = 0; i < values.capacity(); i++)
        output.push_back(values.at(i) * 2);
    return output;
}