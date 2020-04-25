#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define N 1000000

vector<bool> prime(N+1); 

bool isCPrime(int n){

    if(!prime[n]) return false;
    
    string s = to_string(n);
    for(int i = 0; i < s.length()-1; i++){
        char MSB = s[0];
        s.erase(s.begin());
        s.push_back(MSB);
        if(!prime[stoi(s)]){
            return false;
        }
    }
    
    
    return true;
}

int main(){
    
    
    fill(prime.begin(), prime.end(), true); 
    prime[0] = false;
    prime[1] = false;
    for (int p=2; p*p<=N; p++) 
    { 
       
        if (prime[p] == true) 
        { 
            
            for (int i=p*p; i<=N; i += p) 
                prime[i] = false; 
        } 
    } 

    int n,m;
    while(cin >> n){
        if(n == -1) break;
        cin >> m;
        int ans = 0;
        for(int i=n; i <=m; i++){
            if(isCPrime(i)){
                ans++;
            }
        }

        if(ans == 0){
            cout << "No Circular Primes." << endl;
        }
        else if(ans == 1){
            cout << "1 Circular Prime." << endl;
        }
        else {
            cout << ans << " Circular Primes." << endl;
        }
        

    }
}