#include<cstdio>
#include<algorithm>
#include<cmath>

#define NMAX 5000001

#define POWERFUL 15
#define STUPIDRADIX (2<<POWERFUL)
#define MASK (STUPIDRADIX-1)

int *fat = new int[NMAX];

void radixSort(int n, int m){
	long long int fattestKing = m-1;
	for(int pass=0; pass<= ceil(log(fattestKing+1)/log(STUPIDRADIX)); pass++){
		int *c = new int[STUPIDRADIX]{0};
		int *cOut = new int[n];
		int i;
		
		for(i=0; i<n; i++)
			c [ (fat[i]>>(pass*POWERFUL))&MASK ]++;
		
		for(i=1; i<STUPIDRADIX; i++)
				c[i] += c[i-1];
				
		for(i=n-1;i>0;i--){
			cOut[ c[ (fat[i]>>(pass*POWERFUL))&MASK ] - 1 ] = fat[i];
			c[ (fat[i]>>(pass*POWERFUL))&MASK ]--;
		}
		for(i=1;i<n;i++)
			fat[i] = cOut[i];
	
		delete[] cOut;
		delete[] c;
	}
}



void genModdedFatSeq(int n, int m){
	fat[0] = 0;
	fat[1] = 1;

	int i;
	for(i=2;i<=n;i++){
		fat[i] = (fat[i-1]+fat[i-2])%m;
	}
}

int genAns(int n, int m){
	int i;
	long long int ans = 0;
	for(i=1; i<=n; i++){
		ans+=(long long int)fat[i]*i;
		ans%=m;
	}
	return ans;
}

int main(){
	int dumbT;
	scanf("%i",&dumbT);
	int n,q;
	while(dumbT>0){
		dumbT--;
		scanf("%i %i",&n,&q);
		genModdedFatSeq(n,q);
		radixSort(n+1,q);
		printf("%i\n",genAns(n,q));
	}
	return 0;
}
