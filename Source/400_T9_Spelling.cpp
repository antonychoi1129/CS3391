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
#define sfs(n) scanf("%s\n",n)
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

char code[26][5];

void m(){
	char digit='2';
	int times=1;
	int i,j;
	
	//2 - 6 ABC to MNO
	for(i=0;i<='o'-'a';i++){
		for(j=0;j<times;j++)
			code[i][j]=digit;
		code[i][times] = '\0';
		times++;
		if(times>3){
			times=1;
			digit+=1;
		}
	}
		
	//PQRS
	digit = '7';
	times=1;
	for(i='p'-'a';i<='s'-'a';i++){
		for(j=0;j<times;j++)
			code[i][j] = digit;
		code[i][times] = '\0';
		times++;
	}

	//WXYZ
	digit = '9';
	times=1;
	for(i='w'-'a';i<='z'-'a';i++){
		for(j=0;j<times;j++)
			code[i][j] = digit;
		code[i][j] = '\0';
		times++;
	}
	
	//TUV
	digit = '8';
	times=1;
	for(i='t'-'a';i<='v'-'a';i++){
		for(j=0;j<times;j++)
			code[i][j] = digit;
		code[i][times] = '\0';
		times++;
	}
	
	int n;
	sfd_sn(n);
	char msg[1002];
	for(int ccc=1; ccc<=n;ccc++){
		gets(msg);
		printf("Case #%i: ",ccc);
		for(i=0;msg[i]!='\0';i++)
			if(msg[i]==' '){
				if(msg[i-1]==' ') printf(" ");
				printf("0");
			}
			else {
				if(msg[i-1]!=' ' && code[msg[i-1]-'a'][0] == code[msg[i]-'a'][0] )printf(" ");
				printf("%s",code[msg[i]-'a']);
			}
		puts("");
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
