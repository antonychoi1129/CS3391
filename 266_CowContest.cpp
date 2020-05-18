#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n,m, i, j, k, res;

    while(cin >> n >> m){
        vector<vector<int>> d(n, vector<int>(n));
        res = 0;
        for(i = 0; i < m; i++){
            cin >> j >> k;
            d[j-1][k-1] = 1;
        }

        for(k = 0; k < n; k++){
            for(i = 0; i < n; i++){
                if(d[i][k]){
                    for(j = 0; j < n; j++){
                            if(d[k][j])
                                d[i][j] = 1; 
                        }
                 }   
            }
        }
    
        bool flag;
        for(i = 0; i < n; i++){
            flag = true;
            for(j =0 ; j < n; j++){
                if(i != j){
                    if(d[i][j] == 0 && d[j][i] == 0){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                res++;
            }
        }
        cout << res << endl;
    }
    return 0 ;
}