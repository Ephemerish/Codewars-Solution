//Description:
//
//Check to see if a string has the same amount of 'x's and 'o's.The method must return a boolean and be case insensitive.The string can contain any char.
//
//Examples input / output:
//
//	XO("ooxx") = > true
//		XO("xooxx") = > false
//		XO("ooxXm") = > true
//		XO("zpzpzpp") = > true // when no 'x' and 'o' is present should return true
//		XO("zzoo") = > false

bool XO(const std::string& str)
{
    int xCounter = 0, oCounter = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'x' || str[i] == 'X')
            xCounter++;
        else if (str[i] == 'o' || str[i] == 'O')
            oCounter++;
    }
    if (xCounter == oCounter)
        return true;
    else
        return false;
}