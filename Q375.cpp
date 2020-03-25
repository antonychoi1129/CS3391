#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define N 4

int BFS(vector<int> cup, int T){
    bool visited[25][25][25][25] = {0};
    int step = 0;
    int i,j,k;
    queue<vector<int>> q;
    q.push({0,0,0,0});
    visited[0][0][0][0] = true;
    while(!q.empty()){
        i = q.size();
        while(i--){
            vector<int> front = q.front(); q.pop();
            for(j = 0; j < N; j++){
                if(front[j] == T) return step;
            }         
            //fill cup
            for(j = 0; j < N; j++){
                int temp = front[j];
                front[j] = cup[j];
                if(!visited[front[0]][front[1]][front[2]][front[3]]){
                    q.push({front[0],front[1],front[2],front[3]});
                    visited[front[0]][front[1]][front[2]][front[3]] = true;
                }
                front[j] = temp;
            }
            //empty cup
            for(j = 0; j < N; j++){
                int temp = front[j];
                front[j] = 0;
                if(!visited[front[0]][front[1]][front[2]][front[3]]){
                    q.push({front[0],front[1],front[2],front[3]});
                    visited[front[0]][front[1]][front[2]][front[3]] = true;
                }
                front[j] = temp;
            }
            //Pour cup  
            for(j = 0; j < N; j++){
                for(k = 0; k < N; k++){
                    if(k != j){
                        int temp1 = front[j];
                        int temp2 = front[k];
                        if(front[j] + front[k] <= cup[k]){
                                front[k] += front[j];
                                front[j] = 0;
                        }
                        else{
                            int diff = cup[k] - front[k];
                            front[k] += diff;
                            front[j] -= diff;
                        }
                        if(!visited[front[0]][front[1]][front[2]][front[3]]){
                            q.push({front[0],front[1],front[2],front[3]});
                            visited[front[0]][front[1]][front[2]][front[3]] = true;
                        }   
                        front[j] = temp1;
                        front[k] = temp2;    
                    }
                }
            }
        }
        step++;
    }
    return -1;
}
int main(){
    vector<int> cup(4);
    int T;
    while(cin >> cup[0]){
        cin >> cup[1] >> cup[2] >> cup[3] >> T;

        if(cup[0]< T && cup[1] < T && cup[2] < T && cup[3] < T)
            cout << -1 << endl;
        else
            cout << BFS(cup, T) << endl;
    }
    return 0;
}