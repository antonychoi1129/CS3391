/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

//This is Andreas! I don't want to get WA so I use Guest account!

#include<stdio.h>
#include<string.h>
#define oo 0x3f3f3f3f	//https://www.kawabangga.com/posts/1153

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

char pk[20];

int main(){
	int n;
	scanf("%i",&n);
	getchar();
	while(gets(pk)!=NULL){
		if(strlen(pk)==0)continue;
		int sum = ( (pk[0]-'A')%11 + 1) * (9-1);
		int i;
		for(i=2; i<=7; i++)
			sum += (pk[i-1]-'0') * (9-i);
		int cDg = (11 - (sum%11))%11;
		
		int sharp = pk[8];
		if(sharp == 'X') sharp = 10;
		else sharp = sharp-'0';
		
		if(sharp!=cDg){
			if(cDg==10) printf("%s X\n",pk);
			else printf("%s %i\n",pk,cDg);
		}
		else printf("%s Good\n",pk);
	}

	return 0;
}
