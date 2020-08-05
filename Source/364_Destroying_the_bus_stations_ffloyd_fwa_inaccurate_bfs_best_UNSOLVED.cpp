/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

#define oo (int)1e9
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sfd_sn(n) scanf("%d\n",&n)
#define sfs(n) scanf("%s",n)
#define sfc(n) scanf("%c",&n)
#define sfl(n) scanf("%lld",&n)

#define pd(n) printf("%d\n",n)

// #define DEBUG true
#ifdef DEBUG
	#include<iostream>	//Memory Monster
	#define $(v) cout<<#v<<"\t=\t"<<v<<endl
	#define $printf(fs, ...) printf(fs, ##__VA_ARGS__)
#else
	#define $(v) 
	#define $printf(fs, ...)
#endif
//--------------------------------------------------------------------------

#define MAXN 51	// 2 <= n <= 100
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

int city[MAXN][MAXN];

//https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm
void fwa(int n){
	int i,j,k;	//i = start; j = target; k = middle
	for(k=1; k<=n; k++)
		for(i=1; i<=n; i++)
			for(j=1;j<=n;j++){
				if(city[i][j]>city[i][k]+city[k][j])
					city[i][j] = city[i][k]+city[k][j];
			}
}

void m(){
	int n,m,k;
	while(~scanf("%d %d %d",&n, &m, &k)){
		if(n+m+k==0) break;
		
		int i,j;
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				city[i][j] = oo;
		
		for(i=0; i<m; i++){
			int s,f;
			scanf("%d %d",&s, &f);
			city[s][f] = 1;	//one way street
		}
		
		fwa(n);
		Dinic dn(1,n*2);
		for(i=2; i<n; i++)
				if(city[1][i] + city[i][n] <= k){
					dn.addE( i,n+i,1);
				}
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				if(city[i][j]==1) dn.addE(n+i, j, oo);
		printf("%d\n",dn.mf());
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
