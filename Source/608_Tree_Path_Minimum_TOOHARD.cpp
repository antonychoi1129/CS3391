/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<iostream>	//Memory Monster
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define oo 1e15
#define r0 1e-9


#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sfd_sn(n) scanf("%d\n",&n)
#define sfs(n) scanf("%s\n",n)
#define sfc(n) scanf("%c",&n)
#define sfl(n) scanf("%lld",&n)

#define pd(n) printf("%d\n",n)

#define DEBUG true
#ifdef DEBUG
	#define $(v) cout<<#v<<"\t=\t"<<v<<endl
	#define $printf(fs, ...) printf(fs, ##__VA_ARGS__)
#else
	#define $(v) 
	#define $printf(fs, ...)
#endif
//--------------------------------------------------------------------------

struct Node{
	int to;
	ull w;
	
	bool operator < (const Node &n) const{
		return w > n.w;
	}
};

const int MAXN = 50001;
ull weight[MAXN];

void m(){
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		if(n==0 && m==0) break;
		
		vector< vector<Node> > tree;
		tree.assign(n+1, vector<Node>());
		
		bool ved[n+1];
		memset(ved,false,sizeof ved);
		
		int i,j;
		for(i=1;i<=n;i++)
			weight[i] = oo;
		weight[1] = 0;
		
		for(i=0;i<n-1;i++){
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			tree[u].push_back({v,w});
			tree[v].push_back({u,w});
		}
		
		priority_queue<Node> bfs;
		bfs.push({1,0});
		while(!bfs.empty()){
			Node top = bfs.top();
			bfs.pop();
			
			if(ved[top.to]) continue;
			ved[top.to] = true;
			
			for(i=0; i<tree[top.to].size();i++){
				Node nodeto = tree[top.to][i];
				int ito = nodeto.to;
				if(ved[ito]) continue;
				if(weight[ito]>top.w+nodeto.w){
					weight[ito] = top.w + nodeto.w;
					bfs.push({ito,weight[ito]});
				}
			}
		}
		
		for(i=0;i<m;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			printf("%d\n",weight[u]+weight[v]-LCA(u,v));	//insane...
		}
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
