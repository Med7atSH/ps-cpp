#include <iostream>
using namespace std;
struct stDate
{
    int day,month, year;
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
stDate ReadFullDate()
{
    stDate Date;
    Date.day = ReadDay();
    Date.month = ReadMonth();
    Date.year = ReadYear();
    Date.leap = IsLeapYear(Date.year);

    return Date;
}
bool isDate1beforeDate2(stDate date1,stDate date2){
    return (date1.year < date2.year) ? true : 
    ((date1.year == date2.year) ? 
    (date1.month < date2.month ? true : 
        (date1.month == date2.month ? date1.day < date2.day : false))
         : false); 
}
bool IsLeapYear(int n)
{
    bool leap = false;
    (n % 400 == 0) ? leap = true : ((n % 100 == 0) ? leap = false : ((n % 4 == 0) ? leap = true : leap = false));
    return leap;
}
int MonthDays(stDate date)
{
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    date.leap ? NumberOfDays[1] = 29 : NumberOfDays[1] = 28;
    return NumberOfDays[date.month];
}

int diffdays(stDate date1, stDate date2)
{
    int days1=0;
    for (int i = 0; i < date1.month; i++)
    {
        days1+=MonthDays(date1);
    }
    int days2=0;
    for (int i =date1.year; i < date2.year; i++)
    {
        days2+=365;
        if (IsLeapYear(i))days2++;

    }
    for (int i = 0; i < date2.month; i++)
    {
        days2+=MonthDays(date2);
    }
    return days2-days1+1;

}
int main()
{
    cout << "NOTE DATE ! SHOULD BE LESS THAN DATE 2 \n";
    stDate date1 = ReadFullDate(), date2 = ReadFullDate();
    if(isDate1beforeDate2(date1,date2)){
        cout<< "NOTE DATE 1 IS MORE THAN DATE 2";
        return 0;
    }
    int diff = diffdays(date1, date2);
    cout << "difference is " << diff << endl;
    return 0;
} // namespace std;