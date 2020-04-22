#include<iostream>
#include<string>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    string input;
    string result = "";
    int max = 0;
    while(cin >> input){
        for(int i=0; i<input.length(); i++){
            if(input[i] != '-'){
                if(isalpha(input[i]))
                    input[i] = tolower(input[i]);
                else
                    input[i] = ' ';
            }
        }
        stringstream ss(input);
        while(ss >> input){
            if(input.length() > max){
                max = input.length();
                result = input;
            }
        }
    }
    cout << result << endl;
}