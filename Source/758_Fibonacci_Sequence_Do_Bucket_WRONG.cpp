//	[0, 1], 1, 2, 3, 5, 8, 13, ...
//	88 CS3334.

//Can find the period faster by performing fast exponentiation of matrix(?) No time to find out :(

#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

#define NMAX 5000001
#define QMAX 1000000000

long long unsigned *modCount = new long long unsigned[NMAX]{0};

void genCount(long long unsigned n, long long unsigned m){
	long long unsigned i;
	
	
}

long long unsigned genAns(long long unsigned n, long long unsigned m){
	long long unsigned i, j, f1, f2, f3;
					
	long long unsigned* c = new long long unsigned [n]{0};
	f1 = 0; c[0]++;
	f2 = 1; c[1]++;
	f3 = 1; c[1]++;
	for(i=3;i<=n;i++){
		f1 = (f2+f3)%m;
		f2 = f3; f3 = f1;
		c[ f1 ]++;
	}
	
	long long unsigned ans = 0;
	for(i=0, j=0; i<n; i++){
		ans+= (c[i]*(2*j+c[i])/2)%m ;
		ans%=m;
		j+=c[i];
	}
	
	
	delete[] c;
	return ans;
}

int main(){
	genCount(NMAX,QMAX);
	ios::sync_with_stdio(false);
	
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++){
		long long unsigned n,q;
		cin>>n>>q;
		cout<<genAns(n,q)<<endl;
	}
	return 0;
}
