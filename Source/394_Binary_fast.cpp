/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
int main(){
	int input;
	while(~scanf("%i",&input)){
		if(input==0){
			puts("0");
			continue;
		}
		bool see1=false;
		for(int i = 15 ; i>=0; i--){
			int bit = input>>i;
			if(bit&1){
				printf("1");
				see1=true;
			}
			else if(see1) printf("0");
		}

		printf("\n");
	}
	return 0;
}
