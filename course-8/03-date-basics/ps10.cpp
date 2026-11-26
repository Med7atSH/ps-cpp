#include<iostream>
#include<iomanip>
using namespace std;
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

int main()
{
    int day = ReadDay(), month = ReadMonth(), year = ReadYear();
    int days;
    bool leap = IsLeapYear(year);
    !leap?days=NumberOfDaysFromBeggingOfYear(month,day):
        days=NumberOfDaysFromBeggingOfYear(month,day)+1;

    cout<<"number of days from beginning the year is : "<<days;
    
} // namespace std;
