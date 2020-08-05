//	88 CS3334.
//Period - no use
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>

#define NMAX 5000001
#define QMAX 1000000000

using namespace std;

long long unsigned *fatNums = new long long unsigned[NMAX];

void radixSort(long long unsigned* arr, unsigned n, unsigned m){
	unsigned fattestKing = m-1;
	unsigned i;

	unsigned radix = 2;
	 while(radix*2<n) {radix*=2;}
	cout<<"radix: 2^"<<(int)(log(radix)/log(2))<<" ="<<radix<<endl;
	for(unsigned r=1; fattestKing/r>0 ;r*=radix){
		cout<<"Yo!"<<endl;
		//Bucket Sort
		long long unsigned *c = new long long unsigned[radix]{0};
		long long unsigned *cOut = new long long unsigned[radix];
		for(i=0; i<n; i++)
			c [ (arr[i]/r)%n ]++;

		for(i=1; i<n; i++){
			c[i] += c[i-1];
		}

		for(i=n-1;i>0;i--){
			cOut[ c[ (arr[i]/r)%n ] - 1 ] = fatNums[i];
			c[ (arr[i]/r)%n ]--;
		}

		for(i=1;i<n;i++)
			fatNums[i] = cOut [i];

		delete[] c;
		delete[] cOut;
	}
}

void genModdedFatSeq(long long unsigned n, long long unsigned m){
	fatNums[0] = 0;
	fatNums[1] = 1;

	long long unsigned i;
	for(i=2;i<=n;i++){
		fatNums[i] = (fatNums[i-1]+fatNums[i-2])%m;
	}
	radixSort(fatNums,n+1,m);
}

long long unsigned genAns(unsigned n, unsigned m){
	unsigned i;
	unsigned ans = 0;
	for(i=1; i<=n; i++){
		ans+=fatNums[i]*i%m;
		ans%=m;
	}
	return ans;
}

int main(){
	//ios::sync_with_stdio(false);
	int dumbT;
	cin>>dumbT;
	unsigned n,q;
	while(dumbT>0){
		cin>>n>>q;
		genModdedFatSeq(n,q);
		cout<<genAns(n,q)<<endl;
		dumbT--;
	}
	return 0;
}
