/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include <ctype.h>

int main(){
	int cases;
	scanf("%i\n",&cases);
	
	char s[100];
	while(cases--){
		gets(s);
		
		for(int i=0; s[i]!='\0'; i++)
			s[i] = toupper(s[i]);
		
		char* tok;
		tok = strtok(s," ");
		
		while(tok!=NULL){
			if(strlen(tok)>2)
				if(strcmp(tok,"AND")^0&&strcmp(tok,"FOR")^0&&strcmp(tok,"THE")^0)
					printf("%c",tok[0]);
			tok = strtok(NULL, " ");
		}printf("\n");
	}
	
	return 0;
}
