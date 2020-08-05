/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<algorithm>
using namespace std;

#define oo (int)1e9
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

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

int lm[50001];

bool myCmp(int a, int b) {
    return abs(a) < abs(b);
}

void m(){
	int time, lmNum;
	while(~scanf("%d %d",&time, &lmNum)){
		int i,j;
		lm[0] = 0;
		for(i=1; i<=lmNum; i++)
			sfd(lm[i]);

		sort(lm,lm+lmNum+1,myCmp);
		
		int ans = 0;
		
		for(i=1; i<=lmNum; i++){
			int dist = abs(lm[i] - lm[i-1]);
			if(dist<=time){
				time-=dist;
				ans++;
			}
			else break;
		}
		
		pd(ans);
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
