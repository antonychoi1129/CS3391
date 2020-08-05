/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<stdlib.h>

int reverse(char* s){
	char rs[7];
	int len,i,j;
	
	for(len=0; s[len]!='\0'; len++){}
	
	for(i = len-1, j=0; i>=0; i--,j++)
		rs[j] = s[i];
	rs[j] = '\0';
	
	return atoi(rs);
}

int main(){
	char a[7], b[7], c[7];
	do{
		scanf("%[0-9]s",a);
		scanf("%*c");	//eat +
		scanf("%[0-9]s",b);
		scanf("%*c");	//eat =
		scanf("%[0-9]s",c);
		scanf("%*c");	//eat \n
		
		if( reverse(a)+reverse(b) ==reverse(c) ) printf("True\n");
		else printf("False\n");
		
		if(atoi(a)==0&&atoi(b)==0&&atoi(c)==0)
			break;
	}while(true);
	return 0;
}
