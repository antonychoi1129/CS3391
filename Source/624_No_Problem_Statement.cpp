/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#define oo 0x3f3f3f3f	//https://www.kawabangga.com/posts/1153

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

int main(){
	int a;
	char b[10];
	while(~scanf("%i ",&a)){
		gets(b);
		int n10=1;
		for(int i=0;b[i]!='\0';i++){
			a+=(b[i]-'0')*n10;
			n10*=10;
		}
		printf("%i\n",a);
	}

	return 0;
}
