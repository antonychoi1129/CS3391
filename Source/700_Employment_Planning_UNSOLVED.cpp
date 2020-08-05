/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
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
	#include<iostream>	//Memory Monster
	#define $(v) cout<<#v<<"\t=\t"<<v<<endl
	#define $printf(fs, ...) printf(fs, ##__VA_ARGS__)
#else
	#define $(v) 
	#define $printf(fs, ...)
#endif
//--------------------------------------------------------------------------

void m(){
	int workersNeed[12];
	int dp[12][12];
	
	int n;
	while(~sfd(n)){
		if(n==0)break;
		
		int i,j,k;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				dp[j][i]=oo;
		
		int hireCost, salary, fireCost;
		scanf("%d %d %d",&hireCost, &salary, &fireCost );
		
		int maxWorkers = 0;
		for(i=1;i<n;i++){
			sfd(workersNeed[i]);
			maxWorkers = max(workersNeed[i],maxWorkers);
		}
		
		int ans = oo;
		for(i=0;i<=maxWorkers;)
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
