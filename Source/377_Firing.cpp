/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

#define oo 0x3f3f3f3f	//https://www.kawabangga.com/posts/1153
#define ll long long
const int MAXN = 5050;

struct Edge{
	int fm, to;
	ll cap, flw;
	Edge(int f, int t, ll c,ll o){
		fm = f;
		to = t;
		cap = c;
		flw = o;
	}
};

struct Dinic{
	
	int s,t;
	vector<Edge> edges;
	vector<int> G[MAXN];
	bool ved[MAXN];
	int af[MAXN];	//avaliable flow
	int path[MAXN];	//Edge reach last node
	
	Dinic(int src, int tar){
		s = src;
		t = tar;
	}
	
	Dinic(){}
	
	void addE(int from, int to, ll cap){
		edges.push_back( Edge(from, to, cap, 0) );
		edges.push_back( Edge(to, from, 0, 0) );
		int eSize = edges.size();
		G[from].push_back(eSize-2);
		G[to].push_back(eSize-1);
	}
	
	bool bfs(){
		memset(ved,false,sizeof(ved));
		queue<int> que;
		que.push(s);
		af[s] = 0;
		ved[s] = true;
		while(!que.empty()){
			int front = que.front();
			que.pop();
			
			for(int i=0; i<G[front].size(); i++){
				Edge &e = edges[ G[front][i] ];
				if( !ved[e.to] && e.cap>e.flw ){
					ved[e.to] = true;
					af[e.to] = af[front] + 1;
					que.push(e.to);
				}
			}
		}
		return ved[t];
	}
	
	ll dfs(int tn, ll a){
		if(tn == t || a == 0)
			return a;
			
		ll flow = 0;
		for(int &c = path[tn]; c<G[tn].size(); c++){
			ll fff;
			Edge &e = edges[ G[tn][c] ];
			if(  af[tn] + 1 == af[e.to] &&
			 	0<( fff = dfs(e.to, min(a, e.cap-e.flw) ) )  ){
					//update flow along the path
					e.flw += fff;
					flow += fff;
					a -= fff;
					edges[ (G[tn][c])^1 ].flw -= fff;
					if(a==0) break;
				}
		}
		
		return flow;
	}
	
	ll mf(){
		ll ans = 0;
		while( bfs() ){
			memset(path, 0, sizeof(path));
			ans += dfs( s, oo );
		}
		return ans;
	}
};


void rsd_dfs(int node, bool vd[], Dinic &dn){
	for(int i=0; i<dn.G[node].size(); i++){
		Edge &e = dn.edges[ dn.G[node][i] ];
		if( !vd[ e.to ] && e.cap > e.flw ){
			vd[e.to] = true;
			rsd_dfs( e.to,vd,dn );
		}
	}
}

int main(){
	int i, j;
	
	int n,m;
	while(~scanf("%i %i",&n, &m)){
		Dinic dn(0,n+1);
		
		ll profit=0;
		ll p;
		for(i=1;i<=n;i++){
			scanf("%lli",&p);
			if(p>0){
				profit+=p;
				dn.addE(0,i,p);
			}
			else if(p<0)
				dn.addE(i,n+1,-p);
		}
				
		for(i=1; i<=m; i++){
			int a, b;
			scanf("%i %i",&a,&b);
			dn.addE(a,b,oo);
		}
		
		ll mf = dn.mf();
		
		bool vd[MAXN];
		memset(vd,false,sizeof(dn.ved));
		rsd_dfs(0, vd, dn);	//residual
		
		int fired = 0;
		for(i=1;i<=n;i++) fired+=vd[i];
		
		printf("%i %lli\n",fired, profit-mf);
	}

	return 0;
}
