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

char name[70];

bool yes(){
	int len = strlen(name);
	if(len!=8) return false;
	
	char vowel;
	int count = 0;
	bool sawVowel = false;
	for(int i=0;i<len;i++){
		char c = name[i];
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
			count++;
			if(count>2) return false;
			if(!sawVowel){
				vowel = c;
				sawVowel = true;
			}else if(c!=vowel) return false;
		}
		else if(c<'a'||c>'z') return false;
	}
	if(count!=2) return false;
	return true;
}

void m(){
	while(gets(name)!=NULL){
		if(yes())puts("YES");
		else puts("NO");
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
