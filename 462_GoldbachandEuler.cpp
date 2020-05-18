#include<iostream>
using namespace std;

#define N 20000

int pr[N];

void seive(){
    bool min_pr_factor[N] = {0}; //assume all are prime and haven't found any smaller factors for it
    int cnt = 0;
    int n = 12111;
    for (int i=2; i < n; i++) {
        if (min_pr_factor[i] == 0) {
            // min_pr_factor[i] = i; //i is prime and its smallest prime factor is i
            pr[cnt++] = i;
        }
        for (int j=0; j < cnt && i*pr[j] < n; j++){
        // for (int j=0; j<pr.size() && pr[j]<=min_pr_factor[i] && i*pr[j]<=N; j++){
            // cout << "i " << i << " j " << j << " pr[j] " << pr[j] << " i*pr[j] " << i*pr[j] << endl;
            min_pr_factor[i * pr[j]] = true; //for all primes <= min prime factor, set the min prime factor of all the multiples(i*pr[j]) below N to pr[j]
            if(i%pr[j]==0) break;
        }
            
    }
}

bool isPrime(int n){
	if(n<2) return false;
	if(n<=3) return true;
	if(!(n&1)) return false;
	
    for(int i = 1; pr[i] * pr[i] <= n; i++)
        if(n%pr[i] == 0)
            return false;
	
	return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    seive();
    int n;
    while(cin >> n){
        bool flag = false;
        if (n & 1){
                if (n>2 && isPrime(n-2)){
                    flag = true;
                    cout << n << " is the sum of " << 2 << " and " << n-2 <<  "." << endl;
                }
        } 
        else {
             for(int i = n/2-1; i > 1; i--) {
                  if(isPrime(i) && isPrime(n-i)){
                        cout << n << " is the sum of " << i << " and " << n-i <<  "." << endl;
                        flag = true;
                        break;
                  }
             }
        }
        if(!flag) cout << n << " is not the sum of two primes!" << endl;
    }
    return 0;
}