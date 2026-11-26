#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "pls enter the year to check : ";
    cin >> n;
    // (n%400==0)?cout<<"a perfect leap year ":((n%100==0)?cout<<"not a leap year : ":((n%4==0)?cout<<"yes it is a leap year :"):cout<<"not a leap year ");
    bool leap = false;
    (n % 400 == 0) ? leap = true : ((n % 100 == 0) ? leap = false : ((n % 4 == 0) ? leap = true : leap = false));
    if (leap)
    {
        cout<<"yes it is a leap year :) ";
    }
    else 
        cout<<"no it is NOT a leap year :( ";
    

} // namespace std;
