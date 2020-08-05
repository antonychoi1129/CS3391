/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<map>	//vector included
#include<string>
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

void m(){
	int l,k;
	while(~scanf("%d %d",&l, &k)){
		map<string, string> wMap;
		char a[25], b[25];
		while(l--){
			scanf("%s %s",a,b);
			getchar();
			wMap[a]=b;
		}
		while(k--){
			gets(a);
			if(wMap.find(a)!=wMap.end()){
				puts(wMap.find(a)->second.c_str());
			}
			else{
				int len = strlen(a);
				char last = a[len-1];
				char last2 = a[len-2];
				if(last=='y' &&last2!='a' 
							 &&last2!='e'
							 &&last2!='i'
							 &&last2!='o'
							 &&last2!='u')
					strcpy(a+len-1,"ies");
				else if(last=='o'||last=='s'||last=='x'||
				((last=='h')&&(last2=='c'||last2=='s')) )
					strcat(a,"es");
				else strcat(a,"s");
				
				puts(a);
			}
		}
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
