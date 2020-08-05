//	88 CS3334.
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>

#define NMAX 5000001
#define QMAX 1000000000

using namespace std;

long long unsigned *fatNums = new long long unsigned[NMAX];

long long unsigned findMax(long long unsigned* arr, long long unsigned end){
	long long unsigned max = arr[0];
	for(long long unsigned i=1; i<end; i++)
		if(arr[i]>max) max = arr[i];
	return max;
}

void radixSort(long long unsigned* arr, long long unsigned end){
	long long unsigned fattestKing = findMax(arr,end);

	int radix = 2048;
	for(unsigned r=1; fattestKing/r>0 ;r*=radix){
		// Bucket Sort
		queue<unsigned>* c = new queue<unsigned>[radix]();
		unsigned i;
		for(i=0;i<end;i++) c[ (arr[i]/r)%radix ].push(arr[i]);
		int j;
		for(j=0, i=0; j<radix; j++)
			while( !c[j].empty() ){
				arr[i] = c[j].front();
				c[j].pop();
				i++;
			}
		delete[] c;
	}
}

void genModdedFatSeq(long long unsigned n, long long unsigned m){
	fatNums[0] = 0;
	fatNums[1] = 1;
	fatNums[2] = 1;

	long long unsigned i;
	for(i=3;i<=n;i++)
		fatNums[i] = (fatNums[i-1]+fatNums[i-2])%m;
}

long long unsigned genAns(long long unsigned n, long long unsigned m){
	long long unsigned i;
	long long unsigned ans = 0;
	for(i=1; i<=n; i++){
		if(i<100) cout<<fatNums[i]<<" ";
		ans+=fatNums[i]*i;
		ans%=m;
	}
	cout<<endl;
	return ans;
}

int main(){

	return 0;
}
