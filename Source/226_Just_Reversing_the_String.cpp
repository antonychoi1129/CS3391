/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

void output(char* s){
	int len,i;
	for(len=0; s[len]!='\0'; len++){}
	for(i = len-1; i>=0; i--){
		char c=s[i];
		if(c>='A'&&c<='Z') s[i]+='a'-'A';
		else if(c>='a'&&c<='z') s[i]+='A'-'a';
		printf("%c",s[i]);
	}
	printf("\n");
}

int main(){
	char s[1000];
	while(gets(s)!=NULL)
		output(s);
}
