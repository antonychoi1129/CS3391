/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

#define oo 0x3f3f3f3f	//https://www.kawabangga.com/posts/1153
#define MAXN 1001

struct Edge{
	int fm, to, cap, flw;
	Edge(int f, int t, int c,int o){
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
	
	void addE(int from, int to, int cap){
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
	
	int dfs(int tn, int a){
		if(tn == t || a == 0)
			return a;
			
		int flow = 0;
		for(int &c = path[tn]; c<G[tn].size(); c++){
			int fff;
			Edge &e = edges[ G[tn][c] ];
			if(  af[tn] + 1 == af[e.to] &&
			 	0<( fff = dfs(e.to, min(a, e.cap-e.flw) ) )  ){
					//update flow along the path
					e.flw += fff;
					flow += fff;
					a -= fff;
					edges[ (G[tn][c])^1 ].flw -= fff;
					if(a<=0) break;
				}
		}
		
		return flow;
	}
	
	int mf(){
		
		int ans = 0;
		while( bfs() ){
			memset(path, 0, sizeof(path));
			ans += dfs( s, oo );
		}
		
		return ans;
	}
};

int main(){
	int nk,np;
	int i,j;
	while(~scanf("%i %i",&nk, &np)){
		if(nk==0&&np==0) break;
		int skp = nk+np+1;
		Dinic dn(0,skp);
		int pb=0;
		
		int included;
		for(i=1; i<=nk; i++){
			scanf("%i", &included);
			dn.addE(np+i,skp,included);
			pb += included;
		}
		
		for(i=1; i<=np; i++){
			int cnum;
			scanf("%i", &cnum);
			while(cnum--){
				scanf("%i", &included);
				dn.addE(i, included+np, 1);
			}
			dn.addE(0,i,1);
		}
		
		printf("%d\n",dn.mf()==pb);
	}

	return 0;
}
