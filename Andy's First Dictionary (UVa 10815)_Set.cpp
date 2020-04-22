#include<iostream>
#include<string>
#include<set>
#include <algorithm>
#include <sstream>

using namespace std;
 
int main(){
    string input;
    set<string> dict;
    while(cin >> input){
        for(int i=0; i<input.length(); i++){
            if(isalpha(input[i]))
                input[i] = tolower(input[i]);
            else
                input[i] = ' ';
        }
        stringstream ss(input);
        while(ss >> input){
            dict.insert(input);           
        }
    }
    for (set<string>::const_iterator it=dict.begin(); it!=dict.end(); ++it)
        cout << *it << endl;
}