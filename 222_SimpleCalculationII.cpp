#include<iostream>
#include<string>
#include <sstream>
#include <iomanip>
#include <math.h> 

using namespace std;

int main(){
    string input;
    bool flag = true;
    while(getline(cin, input)){
        long double num;
        long double result = 0;
        stringstream ss(input);
        while(ss >> num){
            result += num;
        }
        
        // result = ceil(result*10000.0)/10000.0;
        if(flag){
            flag = !flag;
        }
        else {
            cout << endl;
        }
        cout  << fixed << setprecision(4) << result;
        cout << endl;
    }
}