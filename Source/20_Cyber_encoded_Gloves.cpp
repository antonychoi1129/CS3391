/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
int main(){
	int n;
	while(~scanf("%i\n",&n)){
		char ans[7];
		char glove[7];
		
		int num = 2*n-2;
		gets(ans);
		while(num--){
			gets(glove);
			ans[0]^=glove[0];
			ans[1]^=glove[1];
			ans[2]^=glove[2];
			ans[3]^=glove[3];
			ans[4]^=glove[4];
			ans[5]^=glove[5];
			ans[6]^=glove[6];
		}
		puts(ans);
	}
	return 0;
}
