/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<algorithm>
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
#define pl(n) printf("%lld\n",n)

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

ll genGoldenCarrots(ll n){
	ll bag[5]={0};
	int i, j;
	
	//init---
	bag[0] = n;	//Put all the normal carrots into bag 0
	bag[1] = 1;
	
	//Endless running
	while (true){
		bag[1]++;
		bag[4] = 0;
		
		while(bag[0]>0){
			if(bag[1]>0 && bag[0]>0){
				if(bag[0]==bag[1]){
					bag[2]+=bag[0];
					bag[3]+=bag[0];
					bag[0] = bag[1] = 0;
					return bag[3] + bag[4]+1;
				}
				else if(bag[0] > bag[1]){
					bag[4] = bag[0]/bag[1];
					swap(bag[0],bag[2]);
					// bag[2]+=bag[1];
					// bag[3]+=bag[1];
					// bag[0]-=bag[1];
					// bag[1] = 0;
				}
				else if(bag[0] < bag[1]){
					bag[2]+=bag[0];
					bag[3]+=bag[0];
					bag[1]-=bag[0];
					bag[0] = 0;
				}
				bag[4]+=1;
			}
			
			bag[1]+=bag[3];
			bag[3] = 0;
			printf("%lld %lld %lld %lld %lld\n",bag[0],bag[1],bag[2],bag[3],bag[4]);
		}
		bag[0]+=bag[2];
		bag[2] = 0;
		if(bag[0]+bag[2]==0 || bag[0]<bag[1]) return -1;
	}
}

long long generationGoldenCarrots(long long N){
 long long bag[5];
 for(int i = 0; i < 5; ++i)
 bag[i] = 0;
 bag[0] = N;
 ++bag[1];
 while( true ){
 ++bag[1];
 bag[4] = 0;
 while( bag[0] > 0 ) {
// printf("%lld %lld %lld	 %lld %lld\n",bag[0],bag[1],bag[2],bag[3],bag[4]);
	 
 while( bag[0] > 0 && bag[1] > 0 ){
 --bag[0];
 --bag[1];
 ++bag[2];
 ++bag[3];
 }
 ++bag[4];
 if( bag[0] == 0 && bag[1] == 0 ) {
 bag[4] += bag[3];
 return bag[4]; // the method stops!!
 }
 bag[1] += bag[3];
 bag[3] = 0;
 }
 bag[0] += bag[2];
 bag[2] = 0;
 // printf("%lld %lld %lld %lld %lld\n",bag[0],bag[1],bag[2],bag[3],bag[4]);
 }
}


void m(){
	// printf("\n%lld\n",generationGoldenCarrots(4));
	ll n;
	while(~sfl(n)){
		ll ans = genGoldenCarrots(n);
		if(ans==-1)
			puts("Back to moon .x.");
		else{
			pl(ans);
			pl(generationGoldenCarrots(n));
		}
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
