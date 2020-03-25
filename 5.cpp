#include<bits/stdc++.h>
using namespace std;

typedef pair <int, vector<int>> same;

bool canVisit(){
    return (0 <= i && i < N && 0 <= j && j < N && board[i][j] != '*')? true : false;
}

void addEdges(vector<same> adj[], int s, int i, int j){
    adj[s].push_back(make_pair(i, j));
}

struct node{
    int x,y;
    int distance;
};

struct comp{
    bool operator()(const node& a, const node& b){
        return a.distance > b.distance;
    }
};

node createNode(int x, int y, int distance){
    node new_node;
    new_node.x = x;
    new_node.y = y;
    new_node.distance = distance;
    return new_node;
}

int bfs(vector<same> adj[],  vector<vector<int>> cb, int r1, int c1, int r2, int c2){
    int i,j,u;
    int n = cb.size();
    int s = r1 * n + c1;
    int v = r2 * n + c2;
    priority_queue<node, vector<node>, comp> pq;
    node init = createNode(r1, c1, 0);
    pq.push(init);
  
    vector<vector<bool>> visited(n+1, vector<bool>(n+1,0));
    vector<vector<int>> dist(n+1, vector<int>(n+1,0));

    q.push(init);
    node u;
    while(!q.empty()){
         u = pq.top();
         if(u.x == r2 && u.y == c2) return u.distance;
         pq.pop();
         for(int i = 0; i < adj[cb[r1][c1]].size(); i++){
             if(!visited[adj[cb[r1][c1]][i].first][adj[cb[r1][c1]][i].second] = 1){
                node a = createNode(adj[cb[r1][c1]][i].first, adj[cb[r1][c1]][i].second, dist[adj[cb[r1][c1]][i].first][adj[cb[r1][c1]][i].second]+1);
                dist[adj[cb[r1][c1]][i].first][adj[cb[r1][c1]][i].second] = dist[adj[cb[r1][c1]][i].first][adj[cb[r1][c1]][i].second]+1;
                pq.push(a);
                visited[adj[cb[r1][c1]][i].first][adj[cb[r1][c1]][i].second] = 1;
             }
         }
        if(u.x-1)

    }
    return 0;
}
int main(){
    int r, c, n, i, j, q, r1, c1, r2, c2;
    while(cin >> r, c, n){
        vector<vector<int>> cb(n, vector<int>(n));
        vector<same> adj[n+1];
        for(i=1; i <= n; i++){
            for(j=1; j<=n; j++){
                cin >> cb[i][j];
                addEdges(adj, cb[i][j], i, j);
            }
        }
        cin >> q;
        for(i = 0; i < q; i++){
            cin >> r1 >> c1 >> r2 >> c2;
         
            cout << bfs(adj, r1, c1, r2, c2) << endl;
        }

    }
      
    return 0;
}