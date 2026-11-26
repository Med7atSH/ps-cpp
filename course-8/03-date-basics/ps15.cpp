#include <iostream>

using namespace  std;

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
int MonthDays(int month,bool leap)
{
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    leap?NumberOfDays[1]=29:NumberOfDays[1]=28;
    return NumberOfDays[month-1];
}

int main()
{
    stDate date = ReadFullDate();
    bool leap = IsLeapYear(date.year);
    if(date.day==MonthDays(date.month,leap))
        cout<<"yes Day is the last day in Month \n";
    else 
        cout<<"No , Day is not the last day \n";
    date.month ==12?cout<<"Yes Month is the last Month in the Year \n":cout<<"No , Month is not the last month";




    
} // namespace  std;
