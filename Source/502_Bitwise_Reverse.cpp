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

int ans[1000000]={0};
void m(){
	for(int num=1; num<=1000000; num++){
		ans[num] = 0;
		for(int i=0;i<31;i++)
			if ( num & ( 1<<i ) ) ans[num] = ans[num] | ( 1<<(30-i) );
			while(ans[num]&&!(ans[num]&1)) ans[num]/=2;
	}
	
	int n;
	while(~sfd(n)){
		if(n==0) break;
		pd(ans[n]);
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
