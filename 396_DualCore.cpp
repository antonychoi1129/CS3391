#include<iostream>
#include<vector>
#include<queue>
#include <cstring>
using namespace std;


#define maxn 50001
#define INF 0x3f3f3f3f

struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};

struct Dinic {
  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[maxn];
  int d[maxn], cur[maxn];
  bool vis[maxn];

  void init(int n) {
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }
  
  int cnt(){
	  int sum = 0;
	  for(int i=0; i < maxn; i++){
		  if(vis[i] == 1)
		  	sum++;
	  }
	return sum;
  }

  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if (!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }

  int DFS(int x, int a) {
    if (x == t || a == 0) return a;
    int flow = 0, f;
    for (int& i = cur[x]; i < G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i] ^ 1].flow -= f;
        flow += f;
        a -= f;
        if (a == 0) break;
      }
    }
    return flow;
  }

  int Maxflow(int s, int t) {
    this->s = s;
    this->t = t;
    int flow = 0;
    while (BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }
};

int main(){
  int n, m, a, b, c;
	while(cin >> n >> m){
		
    int start = 2*n, end = 2*n + 1;
    Dinic d;
    d.init(n);

		for (int i = 0; i<n; i++){
      cin >> a >> b;
			d.AddEdge(start, i, a);
      d.AddEdge(i, start, 0);
      d.AddEdge(i, end, b);
      d.AddEdge(end, i, 0);
		}

		
		for (int i = 0; i<m; i++){
			cin >> a >> b >> c;
			d.AddEdge(a - 1, b-1, c);
			d.AddEdge(b-1, a-1, c);

		}
		
		long long flow = d.Maxflow(start, end);
		cout << flow << endl;
	}
}