#include <iostream>
#include <math.h>
using namespace std;

#define ll long long

ll Exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll d = Exgcd(b,a%b,x,y);
    ll t = x;
    x = y;
    y = t - (a/b)*y;
    return d;
}

int main(){
    ll x, y, m, n, L;
    ll nm, xy, r;
    while(cin >> x >> y >> m >> n >> L){
        ll a, b;
        nm = n-m;
        xy = x-y;
        r = Exgcd(nm, L, a, b);
        if (xy%r == 0){
            nm /= r;
			L /= r;
			Exgcd(nm, L, a, b);
			xy /= r;
            a *= xy;
			a = a - a / L * L;
			if (a < 0) {
                a += fabs(L);
			}
			cout << a << endl;;
        } 
        else {
            cout << "Impossible" << endl;
        }		
    }
    return 0;
}
