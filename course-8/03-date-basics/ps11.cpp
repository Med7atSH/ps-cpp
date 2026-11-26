#include <iostream>
#include <iomanip>
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
bool IsLeapYear(int n)
{
    bool leap = false;
    (n % 400 == 0) ? leap = true : ((n % 100 == 0) ? leap = false : ((n % 4 == 0) ? leap = true : leap = false));
    return leap;
}
int NumberOfDaysFromBeggingOfYear(int month, int day)
{
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count=0;
    for (int i = 0; i < month-1; i++)
    {
        count+=NumberOfDays[i];
    }
    return  count +day ;
}
int FindMonthWithDays(int&days,bool leap){
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int count=0;
    for (int i = 0; i < 12; i++)
    {
        if(leap&&i==1)
            count=31+29;
        else
            count+=NumberOfDays[i];
        if(days<=count){
            days=NumberOfDays[i]-(count-days);
            return i+1;
        }
    }
    return 0;
}
stDate getdatefromorderdate(int days , int year,bool leap){
    stDate date;
    date.year=year;
    date.month=FindMonthWithDays(days,leap);
    date.day=days;
    return date;
}
stDate daytodate(int days,int year,bool leap){
    stDate date;
    date.year=year;
    date.month=0;
    int count =0;
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    leap?NumberOfDays[1]=29:NumberOfDays[1]=28;
    for (auto &&i : NumberOfDays)
    {
        date.month++;
        date.day=0;
        for (int j = 0; j < i; j++)
        {  
            date.day++;
            count++;
            if (count==days)
            {
                return date;
            }
        }
    }
    
    
}
int main()
{
    int day = ReadDay(), month = ReadMonth(), year = ReadYear();
    int days;
    bool leap = IsLeapYear(year);
    !leap?days=NumberOfDaysFromBeggingOfYear(month,day):
        days=NumberOfDaysFromBeggingOfYear(month,day)+1;

    cout<<"number of days from beginning the year is : "<<days<<endl;
    stDate date=getdatefromorderdate(days,year,leap);
    cout<<"date "<<date.day<<'/'<<date.month<<'/'<<date.year<<endl;  
    date = daytodate(days,year,leap)  ;
    
    cout<<"date "<<date.day<<'/'<<date.month<<'/'<<date.year<<endl;  

} // namespace std;

