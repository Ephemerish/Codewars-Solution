//Description:
//
//Timmy& Sarah think they are in love, but around where they live, they will only know once they pick a flower each.If one of the flowers has an even number of petalsand the other has an odd number of petals it means they are in love.
//
//Write a function that will take the number of petals of each flowerand return true if they are in love and false if they aren't.

bool lovefunc(int f1, int f2) {
    if (f1 % 2 == 0 && f2 % 2 == 0)
        return false;
    else if (f1 % 2 == 1 && f2 % 2 == 1)
        return false;
    else
        return f1 != f2;
}