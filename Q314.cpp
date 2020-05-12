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

int KMP(string s){
    int len = s.length();
    int lps[len];
    int l = 0;
    lps[0] = 0;
    string p = reverse(s);
    int i,j;
    i = 1;
    while(i < len){
        if(p[i] == p[l]){
            l++;
            lps[i] = l;
            i++;
        }
        else{
            if(l != 0){
                l = lps[l-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }

    i = j = 0;
    int index = 0;
    while(i < len){
        if(p[j] == s[i]){
            if(i == len-1){
                index = i-j;
            }
            i++; j++;
        } 
        else if(i < len){
            if(j != 0) 
                j = lps[j-1];
            else
                i++;
        }
    }
    return index;
}

int main(){
    string input;
    int x;
    while(cin >> input){
        x = KMP(input);
        cout << input;
        x--;
        for(int i = x; i >= 0; i--){
                cout << input[i];
        }
        cout << endl;
    }
}