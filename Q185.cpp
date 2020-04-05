#include<iostream>
#include<string>
#include<ctype.h>
#include<map>
#include <algorithm>

using namespace std;

int isNotAlpha(char c)
{
    return !isalpha(c);
}
 

int main(){
    string input;
    map<string,int> m;;
    map<string,int>::iterator it;
    
    while(cin >> input){
        // cout << "input " << input << endl;
        replace_if(input.begin(), input.end(), isNotAlpha, '\0');
        input.erase(remove(input.begin(), input.end(), '\0'), input.end());
        // cout << "replace " << input << endl;
        for(int i=0; i<input.length(); i++){
            // cout << "in " << input[i] << endl;
            input[i] = tolower(input[i]);
        }
        // cout << "lower " << input << endl;
        it = m.find(input);
        if(it == m.end()){
            m.insert ( pair<string,int>(input,0) );
        }
        
    }
    for (it=m.begin(); it!=m.end(); ++it)
        cout << it->first << endl;
}