/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
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
#define MAXN 1000001
int p[MAXN];
void m(){
	int n;
	while(~sfd(n)){
		int dp[n];
		
		int i,j,k;
		for(i=0;i<n;i++)
			sfd(p[i]);
		
		dp[0] = 1;
		for(i=1;i<n;i++){
			dp[i] = 1;
			for(j=0; j<i;j++)
				if(p[i]>=p[j] && dp[i]<dp[j]+1)
					dp[i] = dp[j]+1;
		}
		
		printf("%d\n",dp[n-1]);	
		
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
