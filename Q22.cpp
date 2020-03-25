#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define P 10000

vector<int> isPrime(P, 1);

int BFS(int from, int to){
    int i,j,k;
    int step = 0;
    bool visited[10][10][10][10] = {0};
    vector<int> f(4); f[0] = from/1000; f[1] = (from%1000)/100; f[2] = (from%100)/10; f[3] = from%10;
    vector<int> t(4); t[0] = to/1000; t[1] = (to%1000)/100; t[2] = (to%100)/10; t[3] = to%10;
    visited[f[0]][f[1]][f[2]][f[3]] = true;
    queue<vector<int>> q;
    q.push(f);
    while(!q.empty()){
        i = q.size();
        while(i--){
            vector<int> front = q.front(); q.pop();
            if(front[0]*1000 + front[1]*100 + front[2]*10 + front[3] == to){
                return step;
            }

            for(j = 0; j < 4; j++){
                for(k = 0; k < 10; k++){
                    if(k != front[j] && (k != 0 || j != 0)){
                        int temp = front[j];
                        front[j] = k;
                        if(!visited[front[0]][front[1]][front[2]][front[3]] && isPrime[front[0]*1000 + front[1]*100 + front[2]*10 + front[3]]){
                            q.push(front);
                            visited[front[0]][front[1]][front[2]][front[3]] = true;
                        }
                        front[j] = temp;
                    }
                }
            }
        }
        step++;
    }
    return -1;
}

int main(){
    int i,j,t,from,to, ans;
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(i = 2; i < P; i++){
        if(!(i&1)){
            isPrime[i] = 0;
        }
        else{
            for(j = 3; i*j < P; j+=2){
                isPrime[i*j] = 0;
            }
        }   
    }
    cin >> t;
    while(t--){
        cin >> from >> to;
        if(!isPrime[to])
            cout << "Impossible" << endl;
        else
            cout << BFS(from, to) << endl; 
        
    }
    return 0;
}