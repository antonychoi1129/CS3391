/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

int main(){
	int cases;
	scanf("%i",&cases);
	
	while(cases--){
		int k;
		scanf("%i\n",&k);
		
		char s[21];
		bool first=true;
		while(k--){
			gets(s);
			if(first){
				printf("%s",s);
				first = false;
			}
			else
				printf(" %s",s);
		}
		printf("\n\n");
	}
	
	return 0;
}
