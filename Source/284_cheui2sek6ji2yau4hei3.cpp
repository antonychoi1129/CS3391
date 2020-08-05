/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

//取石子遊戲 NIM Game

#include<stdio.h>
#include<algorithm>
#include<math.h>
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

//Waaaa.....
const double WYTHOFF = (sqrt(5)+1)/2;

bool win(int a, int b){
	if(a==b) return true;
	if(a==0||b==0) return true;
	if(a<b) swap(a,b);
	if(b == (int)(WYTHOFF*(a-b))) return false;
	return true;
}

void m(){
	int a,b;
	while(~scanf("%d %d",&a,&b)){
		if(win(a,b))puts("1");
		else puts("0");
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
