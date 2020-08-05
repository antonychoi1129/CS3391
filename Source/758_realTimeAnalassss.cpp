#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define NMAX 5000001
#define QMAX 1000000000

unsigned *fat = new unsigned[NMAX];

void radixSort(unsigned n, unsigned m){
	long long unsigned fattestKing = m-1;

	//unsigned radix = pow(2,floor(log(fattestKing)/log(2)+1)/2);
	//long long unsigned radix=n-1;
	for(long long unsigned radix=2;radix<pow(2,15);radix*=2){
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		printf("Radix: %lli\n",radix);
	for(long long unsigned r=1; fattestKing/r>0 ;r*=radix){
		//Bucket Sort
		unsigned *c = new unsigned[radix]{0};
		unsigned *cOut = new unsigned[n];
		unsigned i;

		for(i=0; i<n; i++)
			c [ (fat[i]/r)%radix ]++;

		for(i=1; i<radix; i++)
				c[i] += c[i-1];

		for(i=n-1;i>0;i--){
			cOut[ c[ (fat[i]/r)%radix ] - 1 ] = fat[i];
			c[ (fat[i]/r)%radix ]--;
		}
		for(i=1;i<n;i++)
			fat[i] = cOut[i];

		delete[] cOut;
		delete[] c;
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>( t2 - t1 ).count();
	printf("Time:%lli\n",duration);
	}
}



void genModdedFatSeq(unsigned n, unsigned m){
	fat[0] = 0;
	fat[1] = 1;

	unsigned i;
	for(i=2;i<=n;i++){
		fat[i] = (fat[i-1]+fat[i-2])%m;
	}
}

unsigned genAns(unsigned n, unsigned m){
	unsigned i;
	long long unsigned ans = 0;
	for(i=1; i<=n; i++){
		ans+=(long long unsigned)fat[i]*i;
		ans%=m;
	}
	return ans;
}

int main(){
	
	int dumbT;
	scanf("%i",&dumbT);
	unsigned n,q;
	while(dumbT>0){
		dumbT--;
		scanf("%i %i",&n,&q);
		genModdedFatSeq(n,q);
		//std::sort(fat,fat+n+1);
		radixSort(n+1,q);
		//printf("%i\n",genAns(n,q));
	}
	return 0;
}
