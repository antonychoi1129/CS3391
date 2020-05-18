#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector <char>> k(50, vector<char>(50));
    string s;
    int cnt;
    int r;
    int c;
    vector <int> ans;
    while(!cin.eof()){
        r = c = 0;
        for(r = 0; getline(cin, s) && !s.empty(); r++)
            for(c = 0; c < s.length(); c++)
                k[r][c] = s[c];
            
        cnt = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if (k[i][j] == '.'){
                    if(j + 1 < c && k[i][j+1] == '#') cnt++;
                    if(j - 1 >= 0 && k[i][j-1] == '#') cnt++;
                    if (i - 1 >= 0){
                        if(k[i-1][j] == '#') cnt++;
                        if((i+1) & 1){
                            if(j-1 >= 0 && k[i-1][j-1] == '#') cnt++;
                        }
                        else {
                            if(j+1 < c && k[i-1][j+1] == '#') cnt++;
                        }
                    }
                    if(i+1 < r){
                        if(k[i+1][j] == '#') cnt++;

                        if((i+1) & 1){
                            if(j-1 >= 0 && k[i+1][j-1] == '#') cnt++;
                        }
                        else {
                            if(j + 1 < c && k[i+1][j+1] == '#') cnt++;
                        }
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    for(int i = 0; i < ans.size()-1; i++)
        cout << ans[i] << endl;
    return 0;
}