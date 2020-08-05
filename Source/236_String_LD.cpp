/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
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

char words[101][101];

void m(){
	int n;
	while(~sfd(n)){
		getchar();
		if(n==0) break;
		int i, j, k;
		for(i=0; i<n; i++)
			gets(words[i]);
			
		int ans = 1;
		bool done = false;
		while(!done){
			for(i=0; i<n;i++){
				//Condition 1
				if(strlen(words[i]+ans)==0){
					done = true;
					break;
				}
				//Condition 2
				for(j=i+1; j<n; j++){
					if(strcmp(words[i]+ans,words[j]+ans)==0){
						done = true;
						break;
					}
				}
				if(done) break;
			}
			if(done) break;
			ans++;
		}
		pd(ans-1);
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
