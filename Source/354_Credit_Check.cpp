#include <stdio.h>

int main(){
	int lines;
	scanf("%i",&lines);

	int dbHash[10]={0,2,4,6,8,1,3,5,7,9};
	while(lines){
		int theTotal = -'0'*8;

		char fd[4];	//Those 4 digits
		for(int i=0; i<4; i++){
			scanf("%s",&fd);
			theTotal+=dbHash[fd[0]-'0']+fd[1]+
							+ dbHash[fd[2]-'0']+fd[3];
		}
		if (theTotal%10 != 0) printf("Invalid\n");
		else printf("Valid\n");
		lines--;
	}
	return 0;
}
