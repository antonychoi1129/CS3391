/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<assert.h>
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

//Some targets < 0; n>65555;
int n;
int list[65555];
bool okPOS[65555];
bool okNEG[65555];

void recursion(int pos, int value){
	if(pos==n){
		ok[value] = true;
		return;
	}
	
	recursion(pos+1,value+list[pos]);
	recursion(pos+1,value-list[pos]);
}

void m(){
	int i,j;
	while(~sfd(n)){
		memset(ok,false,sizeof ok);
		int whatever;
		for(i=0;i<n;i++){
			sfd(whatever);
		}
		//recursion(0,0);
		
		int t, target;
		sfd(t);
		while(t--){
			sfd(target);
		}
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
