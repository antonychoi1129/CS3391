#include<iostream>

using namespace std;

int main(){
    int n,m;
    int s;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        bool flag = false;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> s;
                if(s == 1) {
                    if(i == 1 || i == n || j == 1 || j == m)
                        flag = true;
                }
            }
        }
        if(flag) cout << "2" << endl;
        else cout << "4" << endl;
    }
}