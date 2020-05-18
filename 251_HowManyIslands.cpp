#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> mapv;
vector<bool> r;
int n,m,data, res;

void bfs(int i, int j){
    mapv[i][j] = 0;
    if(i-1 >= 0){
        if(mapv[i-1][j] == 1 ) bfs(i-1, j);
        if(j-1>=0 && mapv[i-1][j-1] == 1) bfs(i-1, j-1);
        if(j+1<m && mapv[i-1][j+1] == 1) bfs(i-1, j+1);
    } 
    
    if (i + 1 < n){
        if(mapv[i+1][j] == 1 ) bfs(i+1, j);
        if(j-1>=0 && mapv[i+1][j-1] == 1) bfs(i+1, j-1);
        if(j+1<m && mapv[i+1][j+1] == 1) bfs(i+1, j+1);
    }

    if(j-1 >= 0 && mapv[i][j-1]) bfs(i,j-1);
    if(j+1 < m && mapv[i][j+1]) bfs(i,j+1);

}

int main(){
    
    while(1){
        cin >> m >> n;
        mapv.resize(0);
        if(n != 0 || m != 0){
            for(int i = 0; i <n; i++){
                r.resize(0);
                for(int j = 0; j < m; j++){
                    cin >> data;
                    r.push_back(data);
                }
                mapv.push_back(r);
            }
           

            res = 0;
        
            for(int i = 0; i <n; i++){
                for(int j = 0; j < m; j++){
                    if(mapv[i][j] == 1){
                        bfs(i,j);
                        res++;  
                    }
                }
            }
            cout << res << endl;
            }
        else{
            break;
        }
    }
    return 0;
}