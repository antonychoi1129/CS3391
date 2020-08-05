/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/
#include<stdio.h>

int main(){
	int a, b, c;

	while(~scanf("%i %i",&a, &b)){
		c = ((b-a)>>1) + (b&1|a&1);
		printf("%i\n", c);
	}
}
/*

0 1 2 3 4 5 6 7 8 9 10 11 12 13

*/
