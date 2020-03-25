#include<iostream>
#include<vector>
using namespace std;

#define N  10000

vector<int> pr;

void seive(){
    bool min_pr_factor[N+1] = {0}; //assume all are prime and haven't found any smaller factors for it
    for (int i=2; i<=N; i++) {
        if (min_pr_factor[i] == 0) {
            // min_pr_factor[i] = i; //i is prime and its smallest prime factor is i
            pr.push_back (i);
        }
        for (int j=0; j<pr.size() && i*pr[j]<=N; j++){
        // for (int j=0; j<pr.size() && pr[j]<=min_pr_factor[i] && i*pr[j]<=N; j++){
            // cout << "i " << i << " j " << j << " pr[j] " << pr[j] << " i*pr[j] " << i*pr[j] << endl;
            min_pr_factor[i * pr[j]] = true; //for all primes <= min prime factor, set the min prime factor of all the multiples(i*pr[j]) below N to pr[j]
            if(i%pr[j]==0) break;
        }
            
    }
    // cout << pr[pr.size()-1] << endl;
}

bool isPrime(int n){
	if(n<2) return false;
	if(n<=3) return true;
	if(!(n&1)) return false;
	
    for(int i = 0; i < pr.size() && pr[i] * pr[i] <= n; i++)
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
        if (n & 1){
                if (n>2 && isPrime(n-2))
                    cout << n << " is the sum of " << 2 << " and " << n-2 <<  "." << endl;
                else
                    cout << n << " is not the sum of two primes!" << endl;
        } 
        else {
            bool isSOP = false;
             for(int i = n/2-1; i >= 0; i--) {
                  if(isPrime(i) && isPrime(n-i)){
                        cout << n << " is the sum of " << i << " and " << n-i <<  "." << endl;
                        isSOP = true;
                        break;
                  }
             }
            if(!isSOP)  cout << n << " is not the sum of two primes!" << endl;
        }
    }
    return 0;
}