//	[0, 1], 1, 2, 3, 5, 8, 13, ...
//	88 CS3334.

//Can find the period faster by performing fast exponentiation of matrix(?) No time to find out :(

#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

  unsigned genAns(  unsigned n,   unsigned m){
	  unsigned *fatNums = new   unsigned[n+1];

	  unsigned i, f1, f2, f3;

	  unsigned fattestKing = 0;
	queue<  unsigned>* c = new queue<  unsigned>[10]();
	fatNums[0] = 0;
	f1 = 0; c[0].push(0);
	f2 = 1; c[1].push(1);
	f3 = 1; c[1].push(1);

	for(i=3;i<=n;i++){
		f1 = (f2+f3)%m;
		f2 = f3; f3 = f1;
		c[ f1%10 ].push(f1);
		if(f1> fattestKing) fattestKing = f1;
	}

	int j;
	for(j=0, i=0; j<10; j++)
		while( !c[j].empty() ){
			fatNums[i] = c[j].front();
			c[j].pop();
			i++;
		}
	delete[] c;

	//ten = 1, done in generating fatNums
	for(  unsigned ten=10; fattestKing/ten>0 ;ten*=10){
		//Bucket Sort
		queue<  unsigned>* c = new queue<  unsigned>[10]();
		for(i=0;i<=n;i++) c[ (fatNums[i]/ten)%10 ].push(fatNums[i]);
		int j;
		for(j=0, i=0; j<10; j++)
			while( !c[j].empty() ){
				fatNums[i] = c[j].front();
				c[j].pop();
				i++;
			}
		delete[] c;
	}

	//sort(fatNums,fatNums+period); <-too slow!

	  unsigned ans = 0;
	for(i=1; i<=n; i++){
		ans+=fatNums[i]*i;
		ans%=m;
	}

	delete[] fatNums;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);

	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++){
		  unsigned n,q;
		cin>>n>>q;
		cout<<genAns(n,q)<<endl;
	}
	return 0;
}
