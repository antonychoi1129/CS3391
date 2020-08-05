/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
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

#define MAXPRIME 100001

bool isPrime[MAXPRIME];

void sieve(){
	memset(isPrime,true,sizeof isPrime);
	
	isPrime[0] = isPrime[1] = false;
	
	for(int i=2; i<MAXPRIME; i++){
		if(isPrime[i])
			for(int j=i*2; j<MAXPRIME; j+=i)
				isPrime[j] = false;
	}
}

void m(){
	sieve();
	char line[256];
	char subStr[8];
	while(~sfs(line)){
		if(line[0]=='0'&&line[1]=='\0') break;
		int ans = -1;
		
		int len = strlen(line);
		
		int i,j;
		
		for(i=5; i>0; i--){
			for(j=0;j<len-i+1;j++){
				strncpy(subStr,line+j,i);
				subStr[i]='\0';
				
				int subStrNum;
				sscanf(subStr,"%d",&subStrNum);
				
				if(isPrime[subStrNum] && subStrNum>ans)
					ans = subStrNum;
			}
			if(ans!=-1) break;
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
