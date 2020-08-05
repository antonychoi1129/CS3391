#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>

#define NMAX 5000001
#define QMAX 1000000000

using namespace std;

long long unsigned *fatNums = new long long unsigned[NMAX];

void radixSort(long long unsigned* arr, long long unsigned n, long long unsigned m){
	long long unsigned fattestKing = m-1;

	long long unsigned radix = pow(2,(int)log(n));
	//cout<<"radix: 2^"<<(int) (log(n)/log(10))<<" ="<<radix<<endl;
	for(long long unsigned r=1; fattestKing/r>0 ;r*=radix){
		//cout<<"Yo!"<<endl;
		//Bucket Sort
		queue<long long unsigned>* c = new queue<long long unsigned>[radix]();
		long long unsigned i;
		for(i=0;i<n;i++) c[ (arr[i]/r)%radix ].push(arr[i]);
		unsigned j;
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

	long long unsigned i;
	for(i=2;i<=n;i++){
		fatNums[i] = (fatNums[i-1]+fatNums[i-2])%m;
	}
	radixSort(fatNums,n+1,m);
}

unsigned genAns(long long unsigned n, long long unsigned m){
	long long unsigned i;
	long long unsigned ans = 0;
	for(i=1; i<=n; i++){
		ans+=fatNums[i]*i%m;
		ans%=m;
	}
	return ans;
}

int main(){
	//radixSort(fatNums,NMAX);
	//ios::sync_with_stdio(false);
	int dumbT;
	scanf("%i",&dumbT);
	long long unsigned n,q;
	while(dumbT>0){
		scanf("%i %i",&n,&q);
		genModdedFatSeq(n,q);
		printf("%i\n",genAns(n,q));
		dumbT--;
	}
	return 0;
}
