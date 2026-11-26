#include <iostream>
#include <iomanip>
using namespace std;

bool IsLeapYear(int n)
{
    bool leap = false;
    (n % 400 == 0) ? leap = true : ((n % 100 == 0) ? leap = false : ((n % 4 == 0) ? leap = true : leap = false));
    return leap;
}
int main()
{
    int n;
    cout << "enter the year to check : ";
    cin >> n;

    int days;
    IsLeapYear(n) ? days = 366 : days = 365;
    cout << left << setw(20) << "year in days is"   << setw(3) << ":" << setw(10) << days << endl;
    cout << left << setw(20) << "year in hours is"  << setw(3) << ":" << setw(10) << days * 24 << endl;
    cout << left << setw(20) << "year in minits is" << setw(3) << ":" << setw(10) << days * 24 * 60 << endl;
    cout << left << setw(20) << "year in seconds is"<< setw(3) << ":" << setw(10) << days * 24 * 60 * 60 << endl;

} // namespace std;
