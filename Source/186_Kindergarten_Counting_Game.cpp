#include<stdio.h>

bool isLetter(char c){
	return (c>='A'&&c<='Z' || c>='a'&&c<='z');
}

int words(char*s){
	int words = 0;
	for(int i=0; s[i]!='\0'; i++)
		if(isLetter(s[i]) && !isLetter(s[i+1])) words++;
	return words;
}

int main(){
	char s[1000];
	while(gets(s)!=NULL)
		printf("%i\n",words(s));
}
