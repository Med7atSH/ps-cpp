#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

struct stDate
{
    int day, month, year;
    bool leap;
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
bool IsLeapYear(int n)
{
    bool leap = false;
    (n % 400 == 0) ? leap = true : ((n % 100 == 0) ? leap = false : ((n % 4 == 0) ? leap = true : leap = false));
    return leap;
}
stDate ReadFullDate()
{
    stDate Date;
    Date.day = ReadDay();
    Date.month = ReadMonth();
    Date.year = ReadYear();
    int year = Date.year;
    Date.leap = IsLeapYear(year);

    return Date;
}
bool isDate1beforeDate2(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}
int MonthDays(stDate date1)
{
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    date1.leap ? NumberOfDays[1] = 29 : NumberOfDays[1] = 28;
    return NumberOfDays[date1.month - 1];
}
void MinusOneDay(stDate &date)
{

    if (date.day == MonthDays(date))
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
int DiffInDays(stDate date1, stDate date2)
{
    int days = 0;
    if (!isDate1beforeDate2(date1, date2))
    {
        cout << "NOTE DATE 1 SHOULD BE LESS THAN DATE 2";
    }

    while (isDate1beforeDate2(date1, date2))
    {
        days++;
        MinusOneDay(date1);
    }
    return days++;
}
stDate GetSystemDate()
{
    stDate Date;
    time_t t = time(0);
    tm *now = localtime(&t);
    Date.year = now->tm_year + 1900;
    Date.month = now->tm_mon + 1;
    Date.day = now->tm_mday;
    Date.leap = IsLeapYear(Date.year);
    return Date;
}
int main()
{
    stDate date1 = ReadFullDate(), date2 = GetSystemDate();
    cout << "difference in days : ";
    cout << DiffInDays(date1, date2);
}