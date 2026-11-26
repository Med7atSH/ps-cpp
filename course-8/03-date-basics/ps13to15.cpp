#include <iostream>

using namespace std;
struct sDate
{
    int year;
    int month;
    int day;
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
int DateCompDate(sDate date1,sDate date2){
    return date1.year>date2.year?1:(date1.year<date2.year?2:date1.month>date2.month?1:(date1.month<date2.month?2:date1.day>date2.day?1:(date1.day<date2.day?2:0)));
}
int main()
{
    sDate date1, date2;
    date1.day = ReadDay();
    date1.month = ReadMonth();
    date1.year = ReadYear();
    date2.day = ReadDay();
    date2.month = ReadMonth();
    date2.year = ReadYear();
    int answer=DateCompDate(date1,date2);
    answer==1?cout<<"data tow is less than date one ":(answer==2?cout<<"data one is less than date tow ":cout<<"both are equals");

} // namespace std;
