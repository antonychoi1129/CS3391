#include<iostream>
#include<queue>
#include<vector>
#include<utility> // std pair
#include <iomanip>
using namespace std;

typedef pair <int, vector<int> > edges;
int n,m;

struct node{
    int v, speed, back;
    double time;
};

struct comp{
    bool operator()(const node& a, const node& b){
        return a.time > b.time;
    }
};

node createNode(int v, int speed, double time, int back){
    node new_node;
    new_node.v = v;
    new_node.speed = speed;
    new_node.time = time;
    new_node.back = back;
    return new_node;
}

void addEdges(vector<edges> adj[], int from, int to, int distance, int limit){
    vector<int> constraints;
    constraints.push_back(distance);
    constraints.push_back(limit);
    adj[from].push_back(make_pair(to, constraints)); 
    adj[to].push_back(make_pair(from, constraints)); 
}

node dijkstra(vector<edges> adj[], int from, int to){
    vector<vector<vector<bool> > > visited(n+1, vector<vector<bool> >(n+1, vector<bool>(31)));
   
    priority_queue<node, vector<node>, comp> pq;
    node init = createNode(from, 0, 0, from);
    pq.push(init);

    node res = init;
    node u;
    int speed;
    int d_speed[3] = {-1,0,1};
    while(!pq.empty()){
        u = pq.top();
        if(u.v == to && u.speed == 1)
            return u;

        pq.pop();
        //relexation
        for(int i = 0; i < adj[u.v].size(); i++){  //u.v = node u with vertex index v
            if(adj[u.v][i].first != u.back){   // no u-turn 
                for(int j = 0; j < 3; j++){ // acceleration
                    int change = u.speed + d_speed[j];
                    if(change > 0 && change <= adj[u.v][i].second[1] && !visited[u.v][adj[u.v][i].first][change]){ //after change of speed must not exceed limit and > 0
                        double d_time = adj[u.v][i].second[0] / (double)change + u.time;
                        node add = createNode(adj[u.v][i].first, change, d_time, u.v);
                        visited[u.v][adj[u.v][i].first][change] = 1;
                        pq.push(add);
                    }
                }
            }
        }
    }
    return init;
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

        node res = dijkstra(adj, s, g);
        if(res.v == g){
            cout << fixed << setprecision(5) << res.time <<endl;
        }
        else{
            cout<< "unreachable" << endl;
        }
    }
}