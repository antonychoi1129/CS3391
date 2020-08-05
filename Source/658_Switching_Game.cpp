/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
int levels;
char game [53][53];

int steps (char* a, char* b){
	bool p2n, n2p;
	p2n = n2p = false;
	for(int i=0; a[i]!='\0'; i++){
		if(b[i]=='+'){
			if(a[i]=='-') p2n = true;
			if(p2n&&n2p) return 3;
		}
		else if(b[i]=='-'){
			if(a[i]=='+') n2p = true;
			if(p2n&&n2p) return 3;
		}
	}
	
	//identical
	if(!p2n&&!n2p){
		for(int i=0; a[i]!='\0'; i++)
			if(a[i]=='?' && b[i]!='?')
				a[i]=b[i];
		return 1;
	}
	
	//+ve to -ve
	if(p2n){
		for(int i=0; b[i]!='\0'; i++)
			if(a[i]=='?' && b[i] == '-' ) a[i]='-';
	}
	else{	//vice versa
		for(int i=0; b[i]!='\0'; i++)
			if(a[i]=='?' && b[i] == '+') a[i]='+';
	}
	return 2;
}

int ans(){
	char init[53];

	int i;
	memset(init,'-',strlen(game[0]));

	int sec = steps(game[0],init);
	for(int i=1; i<levels; i++)
		sec+=steps(game[i],game[i-1]);
	return sec;
}

int main(){
	while(~scanf("%i",&levels)){
		if(levels==0) break;
		for(int i=0; i<levels; i++)
			scanf("%s",game[i]);
		printf("%i\n",ans());
	}

	return 0;
}
