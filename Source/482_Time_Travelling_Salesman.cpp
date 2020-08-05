/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
using namespace std;

#define oo (int)2e9
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sfd_sn(n) scanf("%d\n",&n)
#define sfc(n) scanf("%c",&n)
#define sfl(n) scanf("%lld",&n)

#define pd(n) printf("%d\n",n)

// #define DEBUG true
#ifdef DEBUG
	#include<iostream>	//Memory Monster
	#define $(v) cout<<#v<<"\t=\t"<<v<<endl
#else
	#define $(v) 
#endif
//--------------------------------------------------------------------------

int costs[1000][1000];
int prim(int vNum){
	int temp;
	int low[vNum];
	bool ved[vNum];
	memset(ved,false,sizeof(ved));
	int i,j;
	for(i=0;i<vNum;i++)
		low[i] = oo;
	
	//Use vertex 0 as the starting point
	ved[0] = true;
	
	for(i=0;i<vNum;i++)
		low[i] = costs[0][i];
		
	for(i=0; i<vNum; i++){
		//find max edge connecting 2vs
		temp = oo;
		int udV;	//to be updated vertex
		for(j=0;j<vNum;j++)
			if(!ved[j] && temp>low[j])
				temp = low[udV = j];	//will update udV
		if(temp==oo) break;
		
		//Update
		ved[udV] = true;
		for(j=0;j<vNum;j++)
			if(!ved[j] && low[j] > costs[udV][j])
				low[j] = costs[udV][j];
	}
	int minCost = 0;
	for(i=1;i<vNum;i++){
		if(low[i]==oo) return -1;
		minCost+=low[i];
	}
	return minCost;
}

void m(){
	int n;
	int cases = 1;
	while(~sfd(n)){
		getchar();
		int i,j;
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				costs[i][j] = oo;
		
		char line[3005];
		gets(line);
		
		int lp=0;
		bool end = false;
		int a,b,cost;
		while(~sscanf(line+lp,"%d,%d,%d",&a,&b,&cost)){
			costs[a][b] = costs[b][a] = cost;
			while(line[lp]!=' '){
				lp++;
				if(line[lp]=='\0'){
					end = true;
					break;
				}
			}
			if(end) break;
			lp++;	//eat whitespace
		}
		
		int mincost = prim(n);
		
		if(mincost>=oo)mincost=-1;
		
		printf("Case #%d: ",cases++);
		printf("%d\n",mincost);
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
