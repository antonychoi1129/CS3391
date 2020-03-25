#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define N 8

vector<vector<char>> board(N, vector<char>(N));

int target;

bool canVisit(int i, int j){
    return (0 <= i && i < N && 0 <= j && j < N && board[i][j] != '*')? true : false;
}

int BFS(int source){
    int i,j, v;
    queue<int> q;
    vector<int> distances(N*N);
    q.push(source);
    while(!q.empty()){
        v = q.front();
        q.pop();
        i = v / N;
        j = v - i*N;
        if(board[i][j] == '@') return distances[v];
        board[i][j] = '*';
        if(canVisit(i+2, j+1)){q.push((i+2)*N+(j+1)); distances[(i+2)*N+(j+1)] = distances[v]+1;}
        if(canVisit(i-2, j-1)){q.push((i-2)*N+(j-1)); distances[(i-2)*N+(j-1)] = distances[v]+1;}
        if(canVisit(i-2, j+1)){q.push((i-2)*N+(j+1)); distances[(i-2)*N+(j+1)] = distances[v]+1;}
        if(canVisit(i-1, j-2)){q.push((i-1)*N+(j-2)); distances[(i-1)*N+(j-2)] = distances[v]+1;}
        if(canVisit(i-1, j+2)){q.push((i-1)*N+(j+2)); distances[(i-1)*N+(j+2)] = distances[v]+1;}
        if(canVisit(i+1, j-2)){q.push((i+1)*N+(j-2)); distances[(i+1)*N+(j-2)] = distances[v]+1;}
        if(canVisit(i+1, j+2)){q.push((i+1)*N+(j+2)); distances[(i+1)*N+(j+2)] = distances[v]+1;}
        if(canVisit(i+2, j-1)){q.push((i+2)*N+(j-1)); distances[(i+2)*N+(j-1)] = distances[v]+1;}
        
    }
    return 0;
}
int main(){
    int t,i,j, source, cnt, ans;
    char in;
    cin >> t;
    cnt = 0;
    while(t--){
        cnt++;
        for(i=0; i < N; i++){
            for (j = 0; j < N; j++){
                cin >> in;
                board[i][j] = in;
                if(in == '#') source = i*N + j;
                if(in == '@') target = i*N + j;
            }
        }
        
        ans = BFS(source);
        if(ans > 0)
            cout << "Case " << cnt << ": " << ans;
        else
            cout << "Case " << cnt << ": IMPOSSIBLE";

        cout << endl;
    }   
    return 0;
}