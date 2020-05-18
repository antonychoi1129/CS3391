#include<iostream>
#include<vector>
#include<string>
#include <iomanip> 
using namespace std;

int min(int i, int j, int k){
    int m = i;
    if(j<m) m = j;
    if(k<m) m = k;
    return m;
}
void del(string s, int from){
    cout << "D" << s[from-1] << setfill('0') << setw(2) << from;
   
}

void insert(string s, int from, int to){
    cout << "I" << s[to-1] << setfill('0') << setw(2) << from+1;
  

}

void change(string s, int from, int to){
    cout << "C" <<  s[to-1] << setfill('0') << setw(2) << from;
}

int main(){
    string input;
    string output;
    int i,j;
    bool flag = false;
    while(1){
        getline(cin,input, ' ');
        if(input[0] == '#'){
            cout << 'E';
            break;
        } 

        if(flag) cout << endl;
        else flag = true;

        getline(cin, output);
        vector<vector<int>> dp(input.length()+1, vector<int>(output.length()+1));

        //initialize
        for(i=0; i < input.length()+1; i++){
            dp[i][0] = i;
        }

         for(i=0; i < output.length()+1; i++){
            dp[0][i] = i;
        }
        
        for(i = 1; i < input.length()+1; i++){
            for(j = 1; j < output.length()+1; j++){
                if(input[i-1] == output[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1])+1;
                }
                
            }
        }
       
        i = input.length();
        j = output.length();
        while(1){
            if(i==0 && j == 0) break;

            if(i-1 >= 0 && j-1 >=0 && input[i-1] == output[j-1]){
                i--; j--;
            } 
            else if(i-1 >= 0 && j-1 >=0 && dp[i][j] == dp[i-1][j-1]+1){
                change(output, i, j);
                i--; j--;
             
            }
            else if(i-1 >=0 && dp[i][j] == dp[i-1][j]+1){
                del(input, i);
                i--;
            }
            else if(j-1 >=0 && dp[i][j] == dp[i][j-1]+1){
                insert(output, i, j);
                j--;
            }
        }

    }
    return 0;
}