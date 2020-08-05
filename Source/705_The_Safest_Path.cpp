/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

#define oo (int)2e9
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define abs(n) ((n<0)?(-n):(n))

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


struct Node{
	int to;
	double w;
	bool operator < (const Node &n) const{
		return w < n.w;
	}
};

double safety[201][201];
double factor[201];
bool ved[201];
void m(){
	int n,s,t;
	while(~scanf("%d %d %d",&n, &s, &t)){
		vector< vector<Node> > city;
		city.assign(n+1,vector<Node>());
		
		int i,j;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%lf",&safety[i][j]);
		
		for(i=1;i<=n;i++){
			factor[i] = -1;
			for(j=1;j<=n;j++){
				if(i==j) continue;
				city[i].push_back({j,safety[i][j]});
			}
		}
		
		memset(ved,false,sizeof ved);
		priority_queue<Node> dijk;
		dijk.push({s,safety[s][s]});
		while(!dijk.empty()){
			Node top = dijk.top();
			dijk.pop();
			
			if(ved[top.to]) continue;
			ved[top.to] = true;
			
			for(i=0; i<city[top.to].size();i++){
				Node nodeto = city[top.to][i];
				int ito = nodeto.to;
				//printf("currNode(top):%d\tnext:%d\n",top.to,ito);
				if(factor[ito]<top.w*nodeto.w){
					factor[ito] = top.w*nodeto.w;
					if(ito==t) break;
					dijk.push({ito,factor[ito]});
				}
			}
		}
		
		if(factor[t]<0.0005)puts("DANGER!");
		else cout << setprecision(3) << fixed << factor[t] <<endl;
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
/*

3 1 2
1 	0 	0.01
0 	1 	0.01
0.01 	0.01 	1

4 1 4
1 	0 	0 	0
0 	1 	0 	0
0 	0 	1 	0
0 	0 	0 	1

4 1 4
1 	0.999 	0 	1
0.999 	1 	0.998 	0
0 	0.998 	1 	0.997
1 	0 	0.997 	1

4 1 4
1 	1 	0 	0
1 	1 	0.999 	0
0 	0.999 	1 	0.999
0 	0 	0.999 	1

4 1 4
1 	0 	0 	0.5005
0 	1 	0 	0
0 	0 	1 	0
0.5005 	0 	0 	1

4 1 4
1 	0 	0 	0.0005
0 	1 	0 	0
0 	0 	1 	0
0.0005 	0 	0 	1

4 1 4
1 	0 	0 	0.0005
0 	1 	0 	0
0 	0 	1 	0
0.0005 	0 	0 	1

*/
