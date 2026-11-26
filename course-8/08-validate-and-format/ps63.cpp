#include <iostream>
#include <string>
#include <vector>

using namespace std;
string GetStringDate(){
    cout<<"enter date as following dd/mm/yyyy/ \n";
    string s;cin>>s;
    return s;
}
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
vector<string> splitstring(string s){
    size_t pos=0;
    vector<string> date;
    while ((pos=s.find("/"))!=std::string::npos)
    {
        string temp;
        temp= s.substr(0,pos);
        date.push_back(temp);
        s.erase(0,pos+1);
    }
    date.push_back(s);
    return date;
}
int main()
{
    vector<string>date=splitstring(GetStringDate());
    cout<<"day :"<<date[0]<<endl;
    cout<<"month :"<<date[1]<<endl;
    cout<<"year :"<<date[2]<<endl;
    cout <<"you entered : ";
    for (int i = 0; i < date.size(); i++)
    {
        cout<<date[i];
        if (i!=date.size()-1)
        {
            cout<<"/";
        }
    }
    for (int i = 0; i < date.size(); i++)
    {
        cout<<date[i];
        if (i!=date.size()-1)
        {
            cout<<"-";
        }
    }
    cout<<endl;
    
    
    
} // namespace std;
