/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>

const int MAX = 1e5;
const int LASTPRIME = 9592;
bool isPrime[MAX+1]={true};
int spf[MAX+1];
int primeNum[LASTPRIME];

void soe(){	////Sieve of Eratosthenes
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int i, lct=0;
	
	for(i=2; i<=MAX; i++){
		if(isPrime[i]){
			primeNum[lct++] = i;
			spf[i] = i;
		}
		
		for(int j=0; j<lct && i*primeNum[j]<=MAX && primeNum[j]<=spf[i]; j++){
			isPrime[i*primeNum[j]] = false;
			spf[i*primeNum[j]] = primeNum[j];
		}
	}
}

int main(){
	soe();
	char input[256];
	char sfy[6];
	
	while(~scanf("%s",input)){
		int i;
		if(strcmp(input,"0")==0) break;
		for(i=LASTPRIME-1; i>=0; i--){
			sprintf(sfy,"%d", primeNum[i]);
			if(strstr(input,sfy)!=NULL)break;
		}
		printf("%s\n",sfy);
	}
	
	return 0;
}
