#include<string>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s, temp;
    int n,i;
    cin >> n;
    while(n--){
        cin >> s;
        temp = s;
        for(i = s.length()-2; i >=0 ; i--)
            if(temp[i] < temp[i+1])
                temp[i] = temp[i+1];

        for(i = 0; i < s.length(); i++)
            if(temp[i] == s[i])
                cout << temp[i];
        cout << endl;
    }
    return 0;
}