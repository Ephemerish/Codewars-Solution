//Description:
//
//Given two integers aand b, which can be positive or negative, find the sum of all the integers betweenand including themand return it.If the two numbers are equal return a or b.
//
//Note : a and b are not ordered!
//Examples(a, b)-- > output(explanation)
//
//(1, 0)-- > 1 (1 + 0 = 1)
//(1, 2)-- > 3 (1 + 2 = 3)
//(0, 1)-- > 1 (0 + 1 = 1)
//(1, 1)-- > 1 (1 since both are same)
//(-1, 0)-- > -1 (-1 + 0 = -1)
//(-1, 2)-- > 2 (-1 + 0 + 1 + 2 = 2)

int get_sum(int a, int b)
{
    int start, end, sum;
    a < b ? (start = a, end = b) : (start = b, end = a);

    for (sum = 0; start <= end; start++)
        sum += start;

    return sum;
}