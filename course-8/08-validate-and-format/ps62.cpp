#include <iostream>
using namespace  std;
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
int MonthDays(stDate date)
{
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    date.leap ? NumberOfDays[1] = 29 : NumberOfDays[1] = 28;
    return NumberOfDays[date.month - 1];
}
bool IsValidate(stDate date){
    return (date.month>12||date.month<1)?false:(date.day<1||date.day>MonthDays(date))?false:true;
}
int main()
{
    stDate date1=ReadFullDate();
    if (IsValidate(date1))
        cout<<"Yes ,Date is a validate date :) ";
    else
        cout<<"No ,Date is NOT a validate date :( ";
    

    
} // namespace  std;
