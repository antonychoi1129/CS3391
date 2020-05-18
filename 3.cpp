#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include <iomanip>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    unsigned long y, n;
    cin >> t;

    while(t--){
        cin >> y >> n;
        cout << 520%n / y << endl;
       
    }
    return 0;

}