#include <iostream>
using namespace std;

struct stDate
{
    int day, month, year;
    bool leap;
};
struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
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
};
stPeriod ReadFullPeriod()
{
    stPeriod period;
    cout << "enter period start date  : ";
    period.StartDate = ReadFullDate();
    cout << " enter period end date :  ";
    period.EndDate = ReadFullDate();
    return period;
}
bool isDate1beforeDate2(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}
bool isDate1equalDate2(stDate date1, stDate date2)
{
    return date1.year == date2.year ? (date1.month == date2.month ? date1.day == date2.day : false) : false;
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

int diffdays(stDate start,stDate end){
    int counter =0;
    while (isDate1beforeDate2(start,end))
    {
        AddOneDay(start);
        counter++;
    }
    return counter;
}

int main()
{
    stPeriod period1=ReadFullPeriod();
    cout<<"period length is :"<<diffdays(period1.StartDate,period1.EndDate)<<endl;
    
} // namespace std;

