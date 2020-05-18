#include <iostream>  
#include <string>
using namespace std;

int main(){
    int t;
    string name;
    int day;
    int month;
    long year;

    string youngest;
    string oldest;

    long y_date;
    long o_date;

    long y_year;
    long o_year;
    cin >> t;

    cin >> name >> day >> month >> year;
    cin.ignore(1000,'\n');
    youngest = name;
    oldest = name;
    y_date = month*1000 + day;
    o_date = month*1000 + day ;
    y_year = year;
    o_year = year;
    t--;

    while (t--){
        cin >> name >> day >> month >> year;
        cin.ignore(1000,'\n');

        if (year > y_year){
            youngest = name;
            y_date = month*1000 + day;
            y_year = year;
        } else if (year == y_year){
            if ((month*1000 + day) > y_date){
                youngest = name;
                y_date = month*1000 + day;
                y_year = year;
            }
        }
        if (year < o_year){
            oldest = name;
            o_date = month*1000 + day;
            o_year = year;
        } else if (year == o_year){
            if ((month*1000 + day) < o_date){
                oldest = name;
                o_date = month*1000 + day;
                o_year = year;
            }
        }
    }

    cout << youngest << endl;
    cout << oldest << endl;

    return 0;
}