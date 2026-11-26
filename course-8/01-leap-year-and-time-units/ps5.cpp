#include <iostream>
#include <iomanip>
using namespace std;
int ReadYear()
{
    int year;
    cout << "pls enter the year to check : ";
    cin >> year;
    return year;
}
int ReadMonth()
{
    int month;
    cout << "pls enter the month to check : ";
    cin >> month;
    return month;
}
bool IsLeapYear(int n)
{
    bool leap = false;
    (n % 400 == 0) ? leap = true : ((n % 100 == 0) ? leap = false : ((n % 4 == 0) ? leap = true : leap = false));
    return leap;
}
int DaysBerMonth(int month, int year)
{
    bool leap = IsLeapYear(year);
    if (month == 2)
        return leap ? 29 : 28;
    int arr[] = {1, 3, 5, 7, 8, 10, 12};
    for (auto &&i : arr)
    {
        if (i == month)
            return 31;
    }
    return 30;
}

int main()
{
    int year = ReadYear();
    int month = ReadMonth();
    int day = DaysBerMonth(month, year);

    cout << left << setw(20) << "month in days is" << setw(3) << ":" << setw(10) << day << endl;
    cout << left << setw(20) << "month in hours is" << setw(3) << ":" << setw(10) << day * 24 << endl;
    cout << left << setw(20) << "month in minits is" << setw(3) << ":" << setw(10) << day * 24 * 60 << endl;
    cout << left << setw(20) << "month in seconds is" << setw(3) << ":" << setw(10) << day * 24 * 60 * 60 << endl;

}