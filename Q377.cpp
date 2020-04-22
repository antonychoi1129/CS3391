#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

struct FlowEdge {
    int v, u;
    long long cap, flow;
    FlowEdge(int from, int to, long long c){
        v = from;
        u = to;
        cap = c;
        // flow = 0;
    } 
};

const long long flow_inf = 1e18;
int n, m = 0;
struct Dinic {
    vector<FlowEdge> edges;
    vector<vector<int> > adj;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int x, int start, int end){
        s = start;
        t = end;
        n = x;
        adj.resize(n+1);
        level.resize(n+1);
        ptr.resize(n+1);
    }

    void add_edge(int v, int u, long long cap) {
        edges.push_back(FlowEdge(v, u, cap));
        edges.push_back(FlowEdge(u, v, 0));
        m = edges.size();
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
       
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < adj[v].size(); i++) {
                int id = adj[v][i];
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
int main(){
    int x,y;
	while(cin >> x >> y){
		int cnt = 0;
		int i, j, a, b, c;
		
		int sum = 0;
		int maxProfit = 0;
		
		int start = 0, end = x + 1;
		Dinic d(end+1, start, end);
		for (i = 1; i <= x; i++)
		{
			cin >> c;
			if (c > 0) {
				d.add_edge(start, i, c);
				sum += c;
			}
			else if(c<0){
				d.add_edge(i, end, -c);
			}
			
		}
		for (i = 1; i <= y; i++)
		{
			cin >> a >> b;
			d.add_edge(a, b , flow_inf);
		}
		long long flow = d.flow();
        cout << sum << endl;
        cout << flow << endl;
		maxProfit = sum - flow;
		// cout << d.cnt()-1 << " " << maxProfit << endl;
        cout << maxProfit << endl;
	}
}