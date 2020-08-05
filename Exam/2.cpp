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
    long double L, v1, v2, c;
    long double ans;
    while(cin >> L >> v1 >> v2 >> c){
        ans = c*(L)/(v1+v2);
        // if(floor(ans)==ceil(ans))
        //     cout << ans << endl;
        // else 
            cout << fixed <<  setprecision(4) << ans << endl;
    }
    return 0;

}