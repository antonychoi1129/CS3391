#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

const int MAX = 20000;

int p[MAX];
bool v[MAX];

bool isPrime(int n){
	if(n<2) return false;
	if(n<=3) return true;
	if(!(n&1)) return false;
	
	int it = 1;
	while(p[it]*p[it] <=n){
		if(n%p[it]==0) return false;
		it++;
	}
	
	return true;
}

int main(){
    memset(v,false, sizeof(v));
	int pc = 0;
	int i,j;
	int r = 12111;
	for(i=2;i<r; ++i){
		if(!v[i]) p[pc++] = i;
		for(j=0; r>i*p[j] && pc>j;j++){
			v[p[j]*i] = true;
			if(i%p[j]==0) break;
		}
	}

	int n;
	bool flag;
	while(cin >> n){
		flag = false;
        if(n&1){
			if(n>2 && isPrime(n-2)){
				flag = true;
				cout <<  n << " is the sum of " << 2 << " and " << n-2 <<  "." << endl;
			}
		}
            
                
        else
            for(int i=n/2; i>1; i--)
                if(isPrime(i) && isPrime(n-i) && (n-i != i)){
					flag = true;
					cout << n << " is the sum of " << i << " and " << n-i <<  "." << endl;
				}
                     
        if(!flag)
        	cout << n << " is not the sum of two primes!" << endl;
	}

	return 0;
}
