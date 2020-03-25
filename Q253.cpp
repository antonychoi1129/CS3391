#include<iostream>
#include<queue>
#include<vector>
#include<utility> // std pair
#include <iomanip>
using namespace std;

typedef pair <int, double> edges;
int n,m;

struct node{
    int to, distance, limit;
    double time;
    friend bool operator(node n1, node n2){
        return n1.time > n2.time;
    }
}

void addEdges(vector<node> adj[], int from, int to, int distance, int limit){
    double time = (double)distance/limit;
    adj[from].push_back(make_pair(to, time)); 
    adj[to].push_back(make_pair(from, time)); 
}

void dijkstra(vector<edges> adj[], int from, int to){
    const int INF = 101;
    vector<vector<double>> dist(n+1, vector<double>(n+1, INF));

    priority_queue<edges> pq;
    pq.push(make_pair(from,0));
    priority_queue<edges> backq;
    backq.push(make_pair(from,0));

    int u;
    int back;
    int speed;
    bool start = true;
    int d_speed[3] = {-1,0,1};
    while(!pq.empty()){
        u = pq.top().first;
        if(u != from) start = false;
        if(start) speed = 1; 
        pq.pop();
        back = backq.top().first;

        //relexation
        for(int v = 0; v < adj[u].size(); i++){
            if(adj[u][v].first != back){
                for(int i = 0; i > 3; i++){
                    if( adj[u][v].second
                }
                
            }
        
        }
           
        
    }
}

int main(){
    
    int s,g;
    int x,y,d,c;

    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        vector<edges> adj[n+1];
        cin >> s >> g;
        for(int i=0; i < m; i++){
            cin >> x >> y >> d >> c;
            addEdges(adj, x, y ,d , c);
        }

        dijkstra(adj, s, g);

    //     for(int i=1; i <= n; i++){
    //         for (auto x : adj[i])
    //         cout << "from " << i << " to " << x.first << " needs " << fixed << setprecision(5) << x.second << endl;
    //     }
    }
}