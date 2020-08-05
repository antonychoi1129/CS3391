/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>

void printReversed(char* s){
	int len,i;
	for(len=0; s[len]!='\0'; len++){}
	for(i = len-1; i>=0; i--) printf("%c",s[i]);
}

bool isBad(char c){
	return (c =='\n' || c==' ');
}

int main(){
	char s[500], c;
	char word[500];
	while(gets(s)!=NULL){
		int point=0;
		for(int i=0; s[i]!='\0'; i++){
			if( !isBad(s[i]) )
				word[point++] = s[i];
			else{
				word[point] = '\0';
				printReversed(word);
				point = 0;
				printf("%c",s[i]);
			}
		}
		if(point){
			word[point] = '\0';
			printReversed(word);
		}
		printf("\n");
	}
	return 0;
}
