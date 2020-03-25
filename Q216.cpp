#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    string s1;
    string s2;
    int i,j;
 
    while(getline(cin, s1)){
        getline(cin, s2);
        if(s1.length() == 0 || s2.length() == 0){
            cout << 0 << endl;
            continue;
        }
        vector<vector<int>> c(s1.length()+1, vector<int>(s2.length()+1));
        
        for(i=1; i <= s1.length(); i++)
            for(j = 1; j <= s2.length(); j++){
                if(s1[i-1] == s2[j-1]){
                    c[i][j] = c[i-1][j-1] + 1;
                }
                else if(c[i-1][j] >= c[i][j-1]){
                    c[i][j] = c[i-1][j];
                } 
                else {
                    c[i][j] = c[i][j-1];
                }
            }
            
        cout << c[i-1][j-1] << endl;
    }
}