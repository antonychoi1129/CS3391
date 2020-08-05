//	88 CS3334.
//Period - no use
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>

#define NMAX 5000001
#define QMAX 1000000000

using namespace std;

long long unsigned *fat = new long long unsigned[NMAX];

unsigned genAns(unsigned n, unsigned m){
	unsigned i;
	unsigned ans = 0;

	unsigned posibV;

	long long unsigned *buckets = new long long unsigned[n]{0};


	buckets[0]++;
	buckets[1]++;

	for(i=2;i<n;i++){
		fat[i] = (fat[i-1]+fat[i-2])%m;
		buckets[ fat[i]%n ]++;
	}

	for(i=1; i<n; i++) buckets[i] += buckets[i-1];
	for(i=n-1; i>0; i--){
		//cout<<"fat[i]:"<<fat[i]<<endl;
		//cout<<"buckets["<<(fat[i])%n<<"]:"<< buckets[ (fat[i]/n)%n ]<<endl;
		ans+= (buckets[ (fat[i])%n ] -1)*fat[i]%m;
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
		cout<<genAns(n+1,q)<<endl;
	}
	return 0;
}
