#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, i, score, j;
    string s;
    cin >> t;
    while(t--){
        vector<int> team;
        cin >> n;
        for(i =0; i < 3*n; i++){
            cin >> score;
            team.push_back(score);
        }

       
        for (i = 0; i < team.size()-1; i++)      
            for (j = 0; j < team.size()-i-1; j++)  
                if (team[j] > team[j+1])  
                    swap(team[j], team[j+1]); 

        
        int sum = 0;

        for(i =0; i <team.size();i++){
            
            team.pop_back();
           
            sum += team[team.size()-1];
            team.pop_back();
            
        }
        cout << sum << endl;
    }
    return 0;
}