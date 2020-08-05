#include<stdio.h>

int main(){
	long long int a, b;
	char oprt;
	
	while(~scanf("%lli %c %lli",&a,&oprt,&b)){
		if(oprt=='+')
			printf("%lli\n",a+b);
		else printf("%lli\n",a-b);
	}
	
	return 0;
}
