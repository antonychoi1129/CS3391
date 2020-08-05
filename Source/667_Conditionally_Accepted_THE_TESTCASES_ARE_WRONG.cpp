/*
Nice problem. Made me laugh. Nice one.
*/

#include<stdio.h>

bool accept(char* raws, int a, int b){
	int score=0;
	for(int i=0; raws[i]!='\0'; i++){
		if(raws[i]=='o') score+=a;
		else score-=b;
		if(score<0) return false;
	}
	return true;
}

int main(){
	int tcases;
	scanf("%i",&tcases);
	
	char rawM [50];
	int a,b;
	while(tcases--){
		scanf("%s %i %i",&rawM,&a,&b);
		if(!accept(rawM,a,b))	//YOU ARE FAKE NEWS.
			printf("ACCEPT\n");
		else printf("REJECT\n");
	}
	return 0;
}
