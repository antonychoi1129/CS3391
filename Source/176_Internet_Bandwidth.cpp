/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

#define oo 0x3f3f3f3f	//https://www.kawabangga.com/posts/1153
#define MAXN 101	// 2 <= n <= 100

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
	int n;
	int i=1;
	while(~scanf("%i",&n)){
		if(n==0) break;
		printf("Network %i\n",i++);
		
		int src, tar, conNum;
		scanf("%i%i%i",&src,&tar,&conNum);
		Dinic dn(src,tar);
		
		while(conNum--){
			int a, b, bw;
			scanf("%i%i%i",&a,&b,&bw);
			dn.addE(a,b,bw);
			dn.addE(b,a,bw);
		}
		printf("The bandwidth is %i.\n\n",dn.mf());
	}

	return 0;
}
