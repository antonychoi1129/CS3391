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
#else
	#define $(v) 
#endif
//--------------------------------------------------------------------------

void m(){
	int n;
	while(~sfd(n)){
		if(n==0) break;
		int i;
		
		int num;
		sfd(num);
		ull maxP = num;
		int minNum = num;
		for(i=1;i<n;i++){
			sfd(num);
			if(num<minNum) minNum = num;
			maxP*=num;
		}
		maxP/=minNum;
		maxP*=(minNum+1);
		printf("%llu\n",maxP);
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
