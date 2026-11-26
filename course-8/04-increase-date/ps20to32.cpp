#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int GetNumber()
{
    int n;
    cin >> n;
    return n;
}
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
stDate MinusingDays(stDate &date, int days = 1)
{
    while (days--)
    {
        MinusOneDay(date);
    }
}
stDate MinusingWeeks(stDate &date, int weeks = 1)
{
    for (int j = 0; j < weeks; j++)
    {
        for (int i = 0; i < 7; i++)
        {
            MinusOneDay(date);
        }
    }
}
stDate MinusingMonths(stDate &date, int month = 1)
{
    for (int i = 0; i < month; i++)
    {
        if (date.month == 12)
        {
            date.month = 0;
            date.year++;
        }
        date.month++;
    }
}
stDate MinusingYears(stDate &date, int years = 1)
{
    date.year += years;
}
int main()
{
    int n;
    stDate date = ReadFullDate();


    cout << "date after adding one day: ";
    MinusingDays(date);
    cout << "date " << date.day << '/' << date.month << '/' << date.year << endl;


    n=10;
    cout << "date after adding " << n << " days : ";
    MinusingDays(date, n);
    cout << "date " << date.day << '/' << date.month << '/' << date.year << endl;



    cout << "date after adding one week: ";
    MinusingWeeks(date);
    cout << "date " << date.day << '/' << date.month << '/' << date.year << endl;


    n=10;
    cout << "date after adding " << n << " weeks : ";
    MinusingWeeks(date, n);
    cout << "date " << date.day << '/' << date.month << '/' << date.year << endl;



    cout << "date after adding one month: ";
    MinusingMonths(date);
    cout << "date " << date.day << '/' << date.month << '/' << date.year << endl;
    n=10;
    cout << "date after adding " << n << " months : ";
    MinusingMonths(date, n);
    cout << "date " << date.day << '/' << date.month << '/' << date.year << endl;


    cout << "date after adding one year: ";
    MinusingYears(date);
    cout << "date " << date.day << '/' << date.month << '/' << date.year << endl;
    n=10;
    cout << "date after adding " << n << " years : ";
    MinusingYears(date, n);
    cout << "date " << date.day << '/' << date.month << '/' << date.year << endl;
    n=10;
    cout << "date after adding 10 Decade : ";
    MinusingYears(date, 100);
    cout << "date " << date.day << '/' << date.month << '/' << date.year << endl;
    cout << "date after adding one century is : ";
    MinusingYears(date, 100);
    cout << "date " << date.day << '/' << date.month << '/' << date.year << endl;
    cout << "date after adding one millennium is : ";
    MinusingYears(date, 1000);
    cout << "date " << date.day << '/' << date.month << '/' << date.year << endl;
}