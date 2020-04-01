#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x, y, z, a, b, c;
        cin >> x >> y >> z >> a >> b >> c;

        if(x <= a){
            a = a - x;
            x = 0;
        }
        
        if( y <= a){
            a = a-y;
            y = 0;
        }
        else{
            
            y = y-a;
            a = 0;
        }

        if(y <= b){
            b = b-y;
            y = 0;
        }
        else {
            y = y-b;
            b = 0;
        }

        if(a+b+c >= z)
            z = 0;
        if(x+y+z == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}