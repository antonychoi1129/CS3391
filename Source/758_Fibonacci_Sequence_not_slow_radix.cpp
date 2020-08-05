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

void radixSort(long long unsigned* arr, unsigned end, unsigned m){
	unsigned fattestKing = m-1;
		
	unsigned radix = pow(2,16);
	//cout<<"radix:"<<(int)radix<<endl;
	//cout<<"radix:"<<radix<<endl;
	for(long long unsigned r=1; fattestKing/r>0 ;r*=radix){
		//cout<<"Yo!"<<endl;
		//Bucket Sort
		queue<long long unsigned>* c = new queue<long long unsigned>[radix]();
		unsigned i;
		for(i=0;i<end;i++) c[ (arr[i]/r)%radix ].push(arr[i]);
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

void genModdedFatSeq(unsigned n, unsigned m){
	fatNums[0] = 0;
	fatNums[1] = 1;
	
	unsigned i;
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
		dumbT--;
		cin>>n>>q;
		genModdedFatSeq(n,q);
		cout<<genAns(n,q)<<endl;
	}
	return 0;
}
