#include <stdio.h>
int main(){
	int in;
	while(~scanf("%i",&in) )printf("%i\n", in%3==0 && in>=3);
}
