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

int price[55][55];

int translate(char c){
	if(c>='A' && c<='Z') return c-'A';
	if(c>='a'&& c<='z') return c-'a'+26;
	if(c>='0'&& c<='9') return c-'0'+52;
	if(c=='+')return 62;
	if(c=='/')return 63;
	return -77;
}

void m(){
	char input[55];
	while(~sfs(input)){
		memset(price,0,sizeof price);
		
		int len = strlen(input);
		int i,j;
		//first line
		for(i=0; i<len; i++)
			price[0][i] += 64*translate(input[i]);
		
		for(i=1; i<len;i++){
			sfs(input);
			for(j=0;j<len;j++)
				price[i][j]+=64*translate(input[i]);
		}
		
		for(i=0; i<len;i++){
			sfs(input);
			for(j=0;j<len;j++)
				price[i][j]+=translate(input[j]);
		}
		
		for(i=0; i<len; i++){
			for(j=0; j<len;j++)
				printf("%d ",price[i][j]);
			puts("");
		}
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
