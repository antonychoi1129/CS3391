/*Can anyone read me?*/

/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
/*#include<string.h>

const int MAX = 1299709;
const int LASTPRIME = 1e5;
bool isPrime[MAX+1]={true};
int primeNum[LASTPRIME];
int spf[MAX+1];

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

int ans[MAX+1];

void genAns(){
	int lct=0;
	int diff;
	for(int i=2; i<=MAX; i++)
		if(isPrime[i]){
			ans[i] = 0;
			diff = primeNum[++lct]-i;
		}
		else ans[i] = diff;
}

int main(){
	soe();
	genAns();
	int i;
	
	printf("0");
	for(i=1; i<= MAX; i++){
		printf(",%i",ans[i]);
	}
	
	while(~scanf("%i",&i)){
		if(i==0) break;
		printf("%i\n",ans[i]);
	}
	
	return 0;
}*/


int ans[1299710]={};

int main(){
	int i;
	printf("0");
	for(i=1; i<= MAX; i++){
		printf(",%i",ans[i]);
	}
	
	while(~scanf("%i",&i)){
		if(i==0) break;
		printf("%i\n",ans[i]);
	}
}
