#include<bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, i;
    while(cin >> n){
        int sum = 0;
        vector<vector<int>> p(n, vector<int>(2));
        priority_queue<pair<int, int>> pq; 
        for(i = 0; i < n; i++){
            cin >> p[i][0] >> p[i][1];
            pq.push(make_pair(p[i][0] - p[i][1], i));
            sum += p[i][0];
        }
        if(sum < 100){
            cout << sum << endl;
        }
        else{
            vector<bool> visited(n,0);
            sum = 0;
       
            for(i = 0; i < n/2; i++){
                int get;
                get = pq.top().second;
                sum += p[get][1];
                visited[get] = 1;
               
                pq.pop();
            }
            for(i = 0; i < n; i++){
                if(!visited[i]){
                    sum += p[i][0];
                }
            }
            cout << sum << endl;


        }
    }
    return 0;
}