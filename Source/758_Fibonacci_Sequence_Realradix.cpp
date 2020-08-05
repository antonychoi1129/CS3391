//	88 CS3334.
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>

#define NMAX 5000001
#define QMAX 1000000000

using namespace std;

long long unsigned *fatNums = new long long unsigned[NMAX];

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
	genModdedFatSeq(NMAX,QMAX);
	mutatedRadixSort(fatNums,NMAX);
	//ios::sync_with_stdio(false);
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++){
		long long unsigned n,q;
		cin>>n>>q;
		cout<<genAns(n,q)<<endl;
	}
	return 0;
}
