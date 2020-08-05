/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include <set>
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

int snowflakes[1000000];
void m(){
	int tcs;
	sfd(tcs);
	while(tcs--){
		int n;
		sfd(n);
		for(int i=0; i<n; i++)
			sfd(snowflakes[i]);
		
		set<int> package;
		int left = 0, right = 0, ans=0;
		while(right<n){
			while(right<n && !package.count(snowflakes[right]) )
				package.insert( snowflakes[right++] );
				
			ans = max(ans, right - left);
			package.erase( snowflakes[left++] );
		}
		pd(ans);	//O(nlogn), can be faster...
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
