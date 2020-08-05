/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
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

void d2onoff(int d){
	if(d==0)
		printf("()()()()");
	else if(d==1)
		printf("()(*)");
	else if(d==2)
		printf("(*)()");
	else if(d==3)
		printf("()(*)(*)");
	else if(d==4)
		printf("(*)()()");
	else if(d==5)
		printf("()(*)()(*)");
	else if(d==6)
		printf("()(*)(*)()");
	else if(d==7)
		printf("()(*)(*)(*)");
	else if(d==8)
		printf("(*)()()()");
	else if(d==9)
		printf("(*)()()(*)");
}

void m(){
	char input[1005];
	while(~sfs(input)){
		if(input[2]==':'){
			int hh,mm,ss;
			sscanf(input,"%d:%d:%d",&hh,&mm,&ss);
			if(hh/10>0) d2onoff(hh/10);
			d2onoff(hh%10);
			if(mm/10>0) d2onoff(mm/10);
			d2onoff(mm%10);
			if(ss/10>0) d2onoff(ss/10);
			d2onoff(ss%10);
			puts("");
		}
		else{
			char bits[20];
			int b=0;
			for(int i=1;input[i]!='\0';){
				if(input[i]==')'){
					i+=2;
					bits[b++] = '0';
				}
				else{
					i+=3;
					bits[b++] = '1';
				}
			}
			for(int i=0;i<b;i++){
				if(b[i]==0){
					if(b[i+1])
				}
				if(b[i]==1){
					
				}
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
