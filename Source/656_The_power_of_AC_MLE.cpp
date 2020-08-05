/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<queue>
#include<map>
using namespace std;

#define oo (int)2e9
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sfc(n) scanf("%c",&n)
#define sfl(n) scanf("%lld",&n)

#define pd(n) printf("%d\n",n)
//--------------------------------------------------------------------------

struct Node{
	int s1p,s2p,s3p;
	int movs;
	bool operator < (const Node &n) const{
		return movs < n.movs;
	}
	void info(){
		printf("s1: %i s2: %i s3: %i\n",s1p,s2p,s3p);
	}
};

multimap<Node, Node> paths;

void makePath(Node n){
	if(n.movs==0) return;
	Node parent = paths.find(n)->second;
	makePath(parent);
	
	if(n.s1p!=parent.s1p)
		printf("%d %d\n",parent.s1p,n.s1p);
	else if(n.s2p!=parent.s2p)
		printf("%d %d\n",parent.s2p,n.s2p);
	else if(n.s3p!=parent.s3p) printf("%d %d\n",parent.s3p,n.s3p);
}

void m(){
	int i,j;
	int n;
	
	bool ved[75][75][75];
	char colors[75][75];
	while(~sfd(n)){
		if(n==0) break;
		
		//init
		memset(ved,false,sizeof ved);
		paths.clear();
		
		int s1,s2,s3;
		int end1, end2, end3;
		scanf("%d %d %d\n",&s1,&s2,&s3);
		
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				colors[i][j] = getchar();
			getchar();	//eat \n
		}
		
		int minMov = oo;
		queue<Node> que;
		que.push({s1,s2,s3,0});
		while(!que.empty()){
			Node cur = que.front();
			que.pop();
			
			int p1 = cur.s1p;
			int p2 = cur.s2p;
			int p3 = cur.s3p;

			if(ved[p1][p2][p3]){
				continue;
			}
			
			//SUPER IMPORTANT
			ved[p1][p2][p3] = true;
			ved[p1][p3][p2] = true;
			
			ved[p2][p1][p3] = true;
			ved[p2][p3][p1] = true;
			
			ved[p3][p1][p2] = true;
			ved[p3][p2][p1] = true;
			
			if(p1+p2+p3==6){
				minMov = cur.movs;
				end1 = p1;
				end2 = p2;
				end3 = p3;
				break;
			}
			
			char cls12 = colors[p1][p2];
			char cls23 = colors[p2][p3];
			char cls13 = colors[p1][p3];
			
			for(i=1;i<=n;i++){
				if(i==p1 || i==p2 || i==p3) continue;
				//move s1
				if(colors[p1][i] == cls23 &&!ved[i][p2][p3]){
					Node nxt = {i,p2,p3,cur.movs+1};
					que.push(nxt);
					paths.insert( {nxt,cur} );
				}
				//move s2
				if(colors[p2][i] == cls13 &&!ved[p1][i][p3]){
					Node nxt = {p1,i,p3,cur.movs+1};
					que.push(nxt);
					paths.insert( {nxt,cur} );
					
				}
				//move s3
				if(colors[p3][i] == cls12 &&!ved[p1][p2][i]){
					Node nxt = {p1,p2,i,cur.movs+1};
					que.push(nxt);
					paths.insert( {nxt,cur} );
				}
			}
		}
		
		if(minMov==oo)puts("-1");
		else{
			printf("%d\n",minMov);
			makePath({end1,end2,end3,minMov});
		}
		
	}
}

int main(){
	m();
}
/*
6
1 4 6
*ooppo
o*ozpx
oo*poc
pzp*vb
ppov*p
oxcbp*

4
2 3 4
*aax
a*aa
aa*a
xaa*

5
3 4 5
*aaxa
a*axa
aa*aa
xxa*a
aaaa*

*/
