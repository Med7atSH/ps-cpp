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
    Date.leap = IsLeapYear(Date.year);
    return Date;
}
bool isDate1beforeDate2(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}

int MonthDays(stDate date)
{
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    date.leap ? NumberOfDays[1] = 29 : NumberOfDays[1] = 28;
    return NumberOfDays[date.month - 1];
}
int ESMonthDays(int month, bool leap)
{
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    leap ? NumberOfDays[1] = 29 : NumberOfDays[1] = 28;
    return NumberOfDays[month - 1];
}

int diffdays(stDate date1, stDate date2)
{
    int days1 = 0;
    for (int i = 0; i < date1.month; i++)
    {
        days1 += MonthDays(date1);
    }
    int days2 = 0;
    for (int i = date1.year; i < date2.year; i++)
    {
        days2 += 365;
        if (IsLeapYear(i))
            days2++;
    }
    for (int i = 0; i < date2.month; i++)
    {
        days2 += MonthDays(date2);
    }
    return days2 - days1 + 1;
}
int DayOfWeak(stDate date)
{
    int a, y, m;
    a = (14 - date.month) / 12;
    y = date.year - a;
    m = date.month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc.
    return(date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
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
    stDate date;
    date.day=20;
    date.month=8;
    date.year=2023;
    date.leap = false;

    cout << "Today date is : " << date.day << '/' << date.month << '/' << date.year << endl;
    int today = DayOfWeak(date);
    if (today == 5 || today == 6)
        cout << "today is a weekend \n";
    else
        cout << "today is a business day \n";
    today == 6 ? cout << "today is sat and it is the end of the week \n" : cout << "days until end of week : " << 6 - today<<endl;
    int mdays = MonthDays(date);
    date.day == mdays ? cout << "this is the end of the month \n" : cout << "days until end of month" << mdays-date.day<<endl;
    if (date.day == 31 && date.month == 12)
    {
        cout << "this is the end of the year "<<endl;
    }
    else
    {
        int Yday = mdays;
        for (int i = date.month + 1; i < 13; i++)
        {
            Yday += ESMonthDays(i, date.leap);
        }
        cout<<"days untile end of the year is : "<<Yday<<endl;
    }
}