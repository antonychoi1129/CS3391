/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	srand(time(NULL));
	char input[1000];
	while(gets(input)!=NULL){
		if(rand()%2) puts("YES");
		else puts("NO");
	}
	
	return 0;
}
