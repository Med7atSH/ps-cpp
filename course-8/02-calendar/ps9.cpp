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
bool IsLeapYear(int n)
{
    bool leap = false;
    (n % 400 == 0) ? leap = true : ((n % 100 == 0) ? leap = false : ((n % 4 == 0) ? leap = true : leap = false));
    return leap;
}
int NumberOfDaysBerMonth(int month, int year)
{
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return month == 2 ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}
int DayOfWeak(int month, int year, int day = 1)
{
    int a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc.
    int FirstDay = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    FirstDay == 0 ? FirstDay = 6 : FirstDay--;
    return FirstDay;
}
void Calender(int month, int year)
{
    int FirstDay = DayOfWeak(month, year);
    int MonthsDays = NumberOfDaysBerMonth(month, year);
    cout << "Sun Mon Tue Wed Thu Fri Sat\n";
    if (FirstDay < 6)
    {
        for (int i = 0; i < FirstDay; i++)
        {
            cout << "0   ";
        }
    }
    int count = FirstDay + 1;
    int i = 0;
    if(FirstDay==6){
        count=1;
        i=1;
    }
    for (; i <= MonthsDays; i++)
    {
        
        cout << left << setw(4) << i;
        if (count == 7)
        {
            cout << endl;
            count = 0;
        }
        count++;
    }
}
void YearCalender(int month, int year)
{
    string Months[12] =
        {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    cout << "\n_______________ " << Months[month - 1] << " _______________\n";
    Calender(month, year);
}
int main()
{
    int year = ReadYear();
    for (int i = 1; i < 13; i++)
    {
        YearCalender(i, year);
    }
}
