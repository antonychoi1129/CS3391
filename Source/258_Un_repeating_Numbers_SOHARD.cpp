/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<iostream>	//Memory Monster
#include<stdio.h>
#include<string.h>
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

#define DEBUG true
#ifdef DEBUG
	#define $(v) cout<<#v<<"\t=\t"<<v<<endl
	#define $printf(fs, ...) printf(fs, ##__VA_ARGS__)
#else
	#define $(v) 
	#define $printf(fs, ...)
#endif
//--------------------------------------------------------------------------

void m(){
	ll input;
	while(~sfd(input)){
		char op[30];
		input+=1;
		sprintf(op,"%d",input);
		
		int i,j;
		for(i=strlen(op)-2; i>=0; i--){
			if(op[i]!=op[i+1]) continue;
			sprintf(op,"%d",input+=pow(10,strlen(op)-1-i));
			$(pow(10,strlen(op)-2-i));
			i=strlen(op)-1;
		}
		
		puts(op);
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
