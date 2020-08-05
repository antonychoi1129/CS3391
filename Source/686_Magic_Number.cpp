/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

bool yes(char* s){
	for(int i=0; s[i]!='\0'; i++){
		if(s[i]!='1') return false;
		
		if(s[i+1]=='4' && s[i+2]=='4') i+=2;
		else if(s[i+1]=='4') i+=1;
	}
	return true;
}

int main(){
	char input[20];
	
	while(~scanf("%s",input)){
		if(yes(input)) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
