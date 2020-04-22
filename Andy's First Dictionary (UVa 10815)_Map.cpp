#include<iostream>
#include<string>
#include<map>
#include <algorithm>
#include <sstream>

using namespace std;
 
int main(){
    string input;
    map<string,int> m;;
    map<string,int>::iterator it;
    
    while(cin >> input){

        for(int i=0; i<input.length(); i++){
            if(isalpha(input[i]))
                input[i] = tolower(input[i]);
            else
                input[i] = ' ';
        }
        stringstream ss(input);
        while(ss >> input){
            it = m.find(input);
            if(it == m.end()){
                m.insert ( pair<string,int>(input,0) );
            }
        }
        
        
    }
    for (it=m.begin(); it!=m.end(); ++it)
        cout << it->first << endl;
}