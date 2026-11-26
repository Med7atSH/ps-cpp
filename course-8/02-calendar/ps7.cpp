#include <iostream>
#include <iomanip>
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
    cout << "pls enter the day to check";
    cin >> day;
    return day;
}
bool IsLeapYear(int n)
{
    bool leap = false;
    (n % 400 == 0) ? leap = true : ((n % 100 == 0) ? leap = false : ((n % 4 == 0) ? leap = true : leap = false));
    return leap;
}

int DayOfWeak(int month, int year, int day = 1)
{
    int a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    // Gregorian:
    // 0:sun, 1:Mon, 2:Tue...etc.
    int FirstDay= (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    FirstDay ==0?FirstDay=6:FirstDay--;
    return FirstDay;
}
int NumberOfDaysBerMonth(int month, int year)
{
    int NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return month == 2 ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}
void Calender(int month, int year)
{
    int FirstDay = DayOfWeak(month, year);
    int MonthsDays = NumberOfDaysBerMonth(month, year);
    cout<<"Sun Mon Tue Wed Thu Fri Sat\n";
    for (int i = 0; i < FirstDay; i++)
    {
        cout<<"0   ";
    }
    int count = FirstDay + 1;
    for (int i = 0; i <= MonthsDays; i++)
    {

        cout <<left<<setw(4)<< i;
        if (count == 7)
        {
            cout << endl;
            count = 0;
        }
        count++;
    }
}

int main()
{
    int day = ReadDay(), month = ReadMonth(), year = ReadYear();
    bool leap = IsLeapYear(year);
    int WeekDay = DayOfWeak(day, month, year);
    string arrDayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    cout << "\nData : " << day << "/" << month << '/' << year << endl;
    cout << "order day is " << WeekDay << " day name is " << arrDayNames[WeekDay];
    cout<<endl;
    Calender(month,year);
} // namespace std;
