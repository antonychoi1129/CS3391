/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<math.h>
using namespace std;

#define oo (int)1e9
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

void m(){
	int n,k;
	while(~scanf("%d %d",&n, &k)){
		int pagePerMM, consecutiveReadingMM, minRestMM;
		while(k--){
			scanf("%d %d %d",&pagePerMM, &consecutiveReadingMM, &minRestMM);
			int ans = 0;
			int page=0;
			int read = pagePerMM*consecutiveReadingMM;
			while(page+read<n){
				page+=read;
				ans+=consecutiveReadingMM+minRestMM;
			}
			ans+=(n-page)/pagePerMM;
			if( (n-page) %pagePerMM)ans+=1;
			
			printf("%d\n",ans);
		}
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
