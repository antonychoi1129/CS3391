#include <iostream>
using namespace std;

int extended_gcd(int a, int b, int &x, int &y) {
    x = 1;
    y = 0;

    if (0 == b) return a;

    int new_x = 0;
    int new_y = 1;
    int new_r = b;
    int r = a;
    int quotient, tmp;
    while (new_r) {
        quotient = r / new_r;

        tmp = r;
        r = new_r;
        new_r = tmp - quotient * new_r;

        tmp = x;
        x = new_x;
        new_x = tmp - quotient * new_x;

        tmp = y;
        y = new_y;
        new_y = tmp - quotient * new_y;
    }
    return r;
}
bool linear_congruence_equation(int a, int b, int n) {
    int x, y;
    int d = extended_gcd(a, n, x, y);
    if (b % d)  // no solutions
        return false;
    int x0 = x * (b / d) % n;  // particular solution
    cout << d  << endl;
    for (int i = 1; i < d; ++i) {

        cout << (x0 + i * (n / d)) % n << endl;
    }
    return true;
}
int main(){
    int t, y, n;
    cin >> t;
    while(t--){
        cin >> y >> n;
        bool x = linear_congruence_equation(y,n, 520);
         cout << x << endl;
    }

    return 0;
}
