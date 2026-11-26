#include <iostream>
using namespace std;

struct stDate
{
    int day;
    int month;
    int year;
};

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
int ReadDay()
{
    int day;
    cout << "pls enter the day to check : ";
    cin >> day;
    return day;
}
stDate ReadFullDate()
{
    stDate Date;
    Date.day = ReadDay();
    Date.month = ReadMonth();
    Date.year = ReadYear();
    return Date;
}
bool IsLeapYear(int n)
{
    bool leap = false;
    (n % 400 == 0) ? leap = true : ((n % 100 == 0) ? leap = false : ((n % 4 == 0) ? leap = true : leap = false));
    return leap;
}
int MonthDays(int month, int year)
{
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = IsLeapYear(year);
    leap ? NumberOfDays[1] = 29 : NumberOfDays[1] = 28;
    return NumberOfDays[month - 1];
}
void MinusOneDay(stDate &date)
{

    if (date.day == MonthDays(date.month, date.year))
    {
        date.day = 1;
        if (date.month == 12)
        {
            date.year++;
            date.month = 1;
        }
        else
        {
            date.month++;
        }
        return;
    }
    date.day++;
}
int main()
{
    stDate date = ReadFullDate();
    MinusOneDay(date);
    cout << "date " << date.day << '/' << date.month << '/' << date.year << endl;
} // namespace std;
