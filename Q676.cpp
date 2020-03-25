#include<iostream>
#include<vector>
using namespace std;

#define MAX 1000001


int main(){
    int n,m,u,v,w,i,j,k, capital, sum, smallest;
    
    while(cin >> n >> m){
        vector<vector<int>> city(n + 1, vector<int>(n + 1, MAX)); 
        
        for(i = 0; i < m; i++){
            cin >> u >> v >> w;
            city[u][v] = w; 
            city[v][u] = w;
        }

        for(k = 1; k <= n; k++){
            for(i = 1; i <= n; i++){
                if(city[i][k] < MAX)
                    for(j = i+1; j <= n; j++){
                        if(city[i][j] > city[i][k]+city[k][j]){
                            city[i][j] = city[i][k]+city[k][j];
                            city[j][i] = city[i][j];
                        }
                    }
            }
        }

        sum = 0;
        for(i = 2; i<= n; i++){
            sum += city[1][i];
        }

        smallest = sum;
        capital = 1;
        for(i = 1; i <= n; i++){
            sum = 0;
            for(j = 1; j <= n; j++){
                if(i!=j)
                    sum += city[i][j];
            }
            if(sum < smallest){
                smallest = sum;
                capital = i;
            } 
        }

        cout << capital << endl;
    }
}