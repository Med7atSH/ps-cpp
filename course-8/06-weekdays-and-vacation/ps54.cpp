#include <iostream>
#include <string>
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
void AddOneDay(stDate &date)
{

    if (date.day == MonthDays(date))
    {
        date.day = MonthDays(date);
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
    return (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

bool isendweek(stDate date){
    short dayindex=DayOfWeak(date);
    return(dayindex==6||dayindex==5);
}
int main()
{
    string days[] = {"Sun", "Mon", "Tue", "Wed", "Thru", "Fri"};
    stDate date1 = ReadFullDate();
    stDate date2 = ReadFullDate();
    cout<<endl;
    cout << "vacation starts : " << days[DayOfWeak(date1)];

    cout << date1.day << '/' << date1.month << '/' << date1.year << endl;

    cout << "----------------------\n";

    cout << "vacation ends : " << days[DayOfWeak(date2)];

    cout << date2.day << '/' << date1.month << '/' << date1.year << endl;
    int counter =0;
    while (isDate1beforeDate2(date1,date2))
    {
        AddOneDay(date1);
        if (!isendweek(date1))
        {
            counter++;
        }
        
        
    }
    cout<<"Actual Vacations Days is : "<<counter+1<<endl;
    



} // namespace std;
