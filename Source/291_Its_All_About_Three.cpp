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
bool yes(int n){
	if(n<=2) return false;
	if(n%2==0) return false;
	for(int i=3; i<=sqrt(n); i+=2){
		if(n%i==0){
			if(i%10!=3) return false;
			while(n%i==0) n/=i;
		}
	}
	return true;
}

void m(){
	int n;
	while(~sfd(n)){
		if(n==-1) break;
		printf("%d ",n);
		if(yes(n))puts("YES");
		else puts("NO");
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
