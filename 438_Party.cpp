#include <bits/stdc++.h> 

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n <= 2) cout << 0 << endl;
        else cout << n-2 << endl;
    }
}