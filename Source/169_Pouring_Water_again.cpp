/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
// #include<iostream>	//Memory Monster
#include<string.h>
#include<queue>
using namespace std;

#define oo (int)1e9
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sfd_sn(n) scanf("%d\n",&n)
#define sfs(n) scanf("%s\n",n)
#define sfc(n) scanf("%c",&n)
#define sfl(n) scanf("%lld",&n)

#define pd(n) printf("%d\n",n)

// #define DEBUG true
#ifdef DEBUG

	#define $(v) cout<<#v<<"\t=\t"<<v<<endl
	#define $printf(fs, ...) printf(fs, ##__VA_ARGS__)
#else
	#define $(v) 
	#define $printf(fs, ...)
#endif
//--------------------------------------------------------------------------

struct Node{
	int a,b,steps,waterLeft;
};

bool ved[151][151][1001];
void m(){
	//x is aCap and y is bCap
	int x,y,target,water;
	while(~scanf("%d %d %d %d",&x,&y,&target,&water)){
		if(x<target && y<target){
			puts("-1");
			continue;
		}
		memset(ved,false,sizeof ved);
		
		int ans=-1;
		
		queue<Node> bfs;
		bfs.push({ 0,0,0,water });
		while(!bfs.empty()){
			Node n = bfs.front();
			bfs.pop();
			
			if(ved[n.a][n.b][n.waterLeft]) continue;
			ved[n.a][n.b][n.waterLeft]=true;
			
			if(n.a==target||n.b==target){
				ans = n.steps;
				break;
			}
			//Empty container A / A to B
			if(n.a>0){
				//A to B
				if(n.b!=y){	//B not Full
					if( n.a+n.b<=y){
						if(!ved[0][n.a+n.b][n.waterLeft])
							bfs.push({0,n.a+n.b,n.steps+1,n.waterLeft});
					}
					else{
						int bFullifAdd = y - n.b;
						bfs.push({ n.a-bFullifAdd, y, n.steps+1, n.waterLeft });
					}
				}
				
				//Empty A
				if(!ved[0][n.b][n.waterLeft] &&!ved[0][n.b][n.waterLeft])
					bfs.push({0,n.b,n.steps+1,n.waterLeft});
			}
			
			//Empty container B	/ B to A
			if(n.b>0){
				//B to A
				if(n.a!=x){	//A not Full
					if( n.b+n.a<=x){
						if(!ved[n.a+n.b][0][n.waterLeft])
							bfs.push({n.a+n.b,0,n.steps+1,n.waterLeft});
					}
					else{
						int aFullifAdd = x - n.a;
						bfs.push({ x, n.b-aFullifAdd, n.steps+1, n.waterLeft });
					}
				}
				
				//Empty B
				if(!ved[n.a][0][n.waterLeft] &&!ved[n.a][0][n.waterLeft])
					bfs.push({n.a,0,n.steps+1,n.waterLeft});
			}
			
			//WaterUse only increase when filling water
			
			//Fill A
			if(n.a<x && n.waterLeft>0){
				if(x-n.a <= n.waterLeft){
					if(!ved[x][n.b][n.waterLeft-(x-n.a)])
						bfs.push({ x, n.b, n.steps+1,n.waterLeft-(x-n.a) });
				}
				else
					bfs.push({ n.a+n.waterLeft, n.b, n.steps+1, 0});
			}
			
			//Fill B
			if(n.b<y && n.waterLeft>0){
				if(y-n.b <= n.waterLeft){
					if(!ved[n.a][y][n.waterLeft-(y-n.b)])
						bfs.push({ n.a, y , n.steps+1,n.waterLeft-(y-n.b) });
				}
				else
					bfs.push({ n.a, n.b+n.waterLeft, n.steps+1, 0});
			}
		}
		printf("%d\n",ans);
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
