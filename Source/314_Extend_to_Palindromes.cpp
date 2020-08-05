/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

//~_~ KMP Algorithm

#include<stdio.h>
#include<string.h>

int main(){
	char s[100005];
	char r[100005];
	int  p[100005];
	while(gets(s)!=NULL){
		int slen = strlen(s);
		int i,j;
		
		for(i=0; i<slen; i++)
			r[slen-i-1] = s[i];
		r[slen]='\0';
		
		//gen p
		p[0] = -1;
		for(i=0, j = -1;r[i];){
			while(j>-1 && r[i]!=r[j+1])j=p[j];
			p[++i] = ++j;
		}
		
		for(i=0, j=0;s[i];){
			while(j>-1 && s[i]!=r[j+1])j=p[j];
			i++;j++;
			if(j==slen) break;
		}
		
		printf("%s%s\n",s,r+j+1);
	}
	
	return 0;
}
