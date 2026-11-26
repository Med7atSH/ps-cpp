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

bool isDate1beforeDate2(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}

bool isDate1equalDate2(stDate date1, stDate date2)
{
    return date1.year == date2.year ? (date1.month == date2.month ? date1.day == date2.day : false) : false;
}
enum enDateCompare
{
    Before = -1,
    Equal = 0,
    After = 1
};
enDateCompare CompareDate(stDate date1, stDate date2)
{
    if (isDate1beforeDate2(date1, date2))
    {
        return enDateCompare::Before;
    }
    if (isDate1equalDate2(date1, date2))
    {
        return enDateCompare::Equal;
    }
    return enDateCompare::After;
}
bool isOverLapPeriods(stPeriod period1, stPeriod period2)
{
    if (
        (CompareDate(period2.EndDate, period1.StartDate) == enDateCompare::Before) ||
        (CompareDate(period2.StartDate, period1.EndDate) == enDateCompare::After))
    {
        return false;
    }
    return true;
}
stPeriod findoverlap(stPeriod period1, stPeriod period2)
{

    stPeriod lapping;
    (CompareDate(period2.StartDate, period1.StartDate) == enDateCompare::Before) ? lapping.StartDate = period1.StartDate : lapping.StartDate = period2.StartDate;
    (CompareDate(period2.EndDate, period1.EndDate) == enDateCompare::Before) ? lapping.EndDate = period2.EndDate : lapping.EndDate= period1.EndDate;
    return lapping;
}

int main()
{
    cout << "enter period one \n";
    stPeriod period1 = ReadFullPeriod();
    cout << "enter period tow \n";
    stPeriod period2 = ReadFullPeriod();
    stPeriod lapping;
    if (!isOverLapPeriods(period1, period2))
    {
        cout << "no periods are not overlap \n";
        return 0;
    }
    else
        lapping = findoverlap(period1,period2);
    
    int counter=0;
    cout<<"lapping period start form date : ";
    cout << "date " << lapping.StartDate.day << '/' << lapping.StartDate.month << '/' << lapping.StartDate.year << endl;
    while (isDate1beforeDate2(lapping.StartDate,lapping.EndDate))
    {
        counter++;
        AddOneDay(lapping.StartDate);
    }
    cout<<"lapping period end at date : ";
    cout << "date " << lapping.StartDate.day << '/' << lapping.StartDate.month << '/' << lapping.StartDate.year << endl;
    cout<<"period of lapping is : "<<counter<<"days\n";

} // namespace std;