#include <iostream>

using namespace std;

int cal(int n){
    if (n==1)
        return 2;

    return 3*cal(n-1) + 2;
}
int main(){
    int n;
    while(cin >> n){
        cout << cal(n) << endl;
    }
}