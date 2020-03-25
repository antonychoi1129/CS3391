#include<iostream>
#include<string>
using namespace std;

string reverse(string s){
    string rev;
    int len = s.length();
    for(int i = len-1; i>=0; i--){
        rev.append(s, i, 1);
    }
    return rev;
}

int findPalindromes(string s){
    int len = s.length();
    int x = len - 1;
    for(int i=len-2; i >=0 ; i--){
        string sub = s.substr(i, len - i);
        if(sub.compare(reverse(sub)) == 0){
            x = i;
        }
    }
    return x;
}
int main(){
    string input;
    int x;
    while(cin >> input){
        x = findPalindromes(input);
        cout << input;
        x--;
        for(int i = x; i >= 0; i--){
                cout << input[i];
        }
        
        
        cout << endl;
    }
      
}