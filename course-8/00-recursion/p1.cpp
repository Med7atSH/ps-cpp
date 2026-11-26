#include <iostream>
#include <string>

using namespace std;
string NumberToText(int Number)
{
    if (Number == 0)
        return "";
    else if (Number >= 1 && Number <= 9)
    {
        string arr[] = {
            "", "one ", "tow", "three", "four", "five",
            "six ", "seven", "eight", "nine"};
        return arr[Number];
    }
    else if (Number >= 10 && Number <= 19)
    {
        string arr[] = {
            "ten", "eleven ", "twelve", "thirteen", "fourteen", "fifteen",
            "sixteen ", "seventeen", "eighteen", "nineteen"};
        return arr[Number % 10];
    }
    else if (Number >= 20 && Number <= 99)
    {
        string arr[] = {
            "", "", "twenty", "thirty ", "forty", "fifty",
            "sixty", "seventy", "eighty ", "ninety"};
        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }
    else if (Number >= 100 && Number <= 999)
    {
        return NumberToText(Number / 100) + " hundreds " + NumberToText(Number % 100);
    }
    else if (Number >= 1000 && Number <= 999999)
    {
        return NumberToText(Number / 1000) + " Thousands " + NumberToText(Number % 1000);
    }
    else if (Number >= 1000000 && Number < 999999999)
    {
        return NumberToText(Number / 1000000) + " Millions " + NumberToText(Number % 1000000);
    }
    else
    {
        return NumberToText(Number / 1000000000) + " billions " + NumberToText(Number % 1000000000);
    }
}
int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;
    cout << NumberToText(n);

} // namespace std;
