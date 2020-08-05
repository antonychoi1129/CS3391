//	[0, 1], 1, 2, 3, 5, 8, 13, ...
//	88 CS3334.

//Can find the period faster by performing fast exponentiation of matrix(?) No time to find out :(

#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

long long unsigned genAns(long long unsigned n, long long unsigned m){
	long long unsigned fattestKing = 0;
	
	long long unsigned bound = min(m*m+1,n+1);
	long long unsigned *fatNums = new long long unsigned[bound];
	long long unsigned *dist = new long long unsigned[m]{0};
	
	long long unsigned period = n + 1;
	long long unsigned i;
					
	fatNums[0] = 0;
	fatNums[1] = 1;
	fatNums[2] = 1;
	
	dist[1] = 2;
	
	for(i=3;i<bound;i++){
		fatNums[i] = (fatNums[i-1]+fatNums[i-2])%m;
		//dist[fatNums[i]]++;
		if(fatNums[i]> fattestKing) fattestKing = fatNums[i];
		if(fatNums[i-1]==0 && fatNums[i]==1){
			period = i-1;
			cout<<"PERIOD:"<<period<<endl;
			break;
		}
	}
	
	long long unsigned ans = 0;
	
	//Radix Sort - too slow
	for(long long unsigned ten=1; fattestKing/ten>0 ;ten*=10){
		//Bucket Sort
		queue<long long unsigned>* c = new queue<long long unsigned>[10]();
		for(i=0;i<period;i++) c[ (fatNums[i]/ten)%10 ].push(fatNums[i]);
		int j;
		for(j=0, i=0; j<10&&i<period; j++)
			while( !c[j].empty() ){
				fatNums[i] = c[j].front();
				c[j].pop();
				i++;
			} 
		delete[] c;
	}
	
	//sort(fatNums,fatNums+period); <-too slow!
	
	for(i=1; i<=n; i++){
		ans+=fatNums[i%period]*i;
		ans%=m;
	}
	
	delete[] fatNums;
	return ans%m;
}

int main(){
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
