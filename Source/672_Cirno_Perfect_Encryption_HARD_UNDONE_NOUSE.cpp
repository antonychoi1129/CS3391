/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
using namespace std;

#define oo (int)1e9;
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sfc(n) scanf("%c",&n)
#define sfl(n) scanf("%lld",&n)

#define pd(n) printf("%d\n",n)

// #define DEBUG true
#ifdef DEBUG
	#include<iostream>	//Memory Monster
	#define $(v) cout<<#v<<"\t=\t"<<v<<endl
#else
	#define $(v) 
#endif
//--------------------------------------------------------------------------

void m(){
	char word[21];
	char dced[21];
	while(gets(word)){
		if(word[0]=='#') break;
		
		int i;
		int len = strlen(word);
		
		bool invalid = false;
		for(i=0;i<len;i++)
			if(word[i]=='z'){
				puts("invalid encoded text");
				invalid = true;
			}
		if(invalid) continue;
		
		bool saw[26];
		memset(saw,false,sizeof saw);
		for(i=0;i<len;i++){
			if(word[i]=='a')
				dced[i]='?';
			else if(!saw[word[i]-'a']){
				dced[i]=word[i]+1;
				saw[dced[i]] = true;
			}
		}
		dced[len]='\0';
		puts(dced);
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
