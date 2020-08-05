/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
using namespace std;

#define oo (int)1e9;
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
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

int crLoc[21];
int sdLoc[21];

void m(){
	int i,j;
	int eventNum;
	while(~sfd(eventNum)){
		int event;
		
		//Correct order
		for(i=1;i<=eventNum;i++){
			sfd(event);
			crLoc[event] = i;
		}
			
		//Student Thoughts
		while(scanf("%i",&event)){
			if(event<=0) break;	//The '-'
			sdLoc[event] = 1;
			
			for(i=2;i<=eventNum;i++){
				sfd(event);
				sdLoc[event] = i;
			}
			
			int dp[eventNum+1][eventNum+1];
			
			for(i=0;i<=eventNum;i++)
				for(j=0;j<=eventNum;j++)
					dp[i][j] = 0;
			
			for(i=1;i<=eventNum;i++)
				for(j=1;j<=eventNum;j++){
					if(crLoc[i]==sdLoc[j])
						dp[i][j] = dp[i-1][j-1]+1;
					else
						dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			
			printf("%i\n",dp[eventNum][eventNum]);
		}
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING... REMOVE ME BEFORE SUBMIT.");
	#endif
	
	m();
}
