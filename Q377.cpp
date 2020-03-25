#include<iostream>
#include<vector>

using namespace std;

int i, n, m, pl, from, to;

long sumProfit(int e, int adj_num[], int net[], long sum[], bool visited[], vector<vector<bool>> adj){
    if(visited[e]){
        cout << "return " << 0 << endl;
        return 0;
    }
        
    else{
        cout << "hit " << e << endl;
        bool found = false;
        visited[e] = true;
        for(int i=1; i < n+1; i++){
            if(adj[e][i]){
                found = true;
                adj_num[e]++;
                sum[e] += sumProfit(i, adj_num, net, sum, visited, adj);
                cout << "sum " << e << " " << sum[e] << endl;
            }
        }
        
        
        cout << "base " << sum[e] << endl;
        return sum[e];
        
            
    }
}

int main(){
    
    while(cin >> n >> m){
        int net[n+1];
        for(i = 1; i < n+1; i++){
            cin >> pl;
            net[i] = pl;
        }
        vector<vector<bool>> adj(n+1, vector<bool>(n+1, 0));
        for(i=0; i<m; i++){
            cin >> from >> to;
            adj[from][to] = true;
        }
        for(i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
        int adj_num[n+1];
        long sum[n+1];
        bool visited[n+1];

        for(i=1; i < n+1; i++){
            adj_num[i] = 0;
            sum[i] = net[i];
            visited[i] = false;
        }

        for(i=1; i < n+1; i++){
            visited[i] = false;
            sum[i] = sumProfit(i, adj_num, net, sum, visited, adj);
        }
        for(i=1; i < n+1; i++){
            cout << sum[i] << " ";
        }
       
    }
}