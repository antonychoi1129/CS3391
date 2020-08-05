/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

/*Bad problem*/

#include<stdio.h>
#include<string.h>

int main(){
	char c;
	int cNum=0;
	char word[81];

	while(~scanf("%s",word)){
		if(word[0]=='<'){
			if(word[1]=='b'){
				printf("\n");
				cNum = 0;
			}
			else {
				if(cNum!=0) printf("\n");
				cNum = 0;
				printf("--------------------------------------------------------------------------------\n");
			}
			continue;
		}

		cNum += strlen(word) + 1;

		if(cNum>80){
			printf("\n");
			cNum = strlen(word);
		}
		printf("%s ",word);
	}
	printf("\n");

	return 0;
}
