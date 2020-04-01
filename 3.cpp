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
    while(cin >> t){
        vector<int> in(t);
        for(int i=0; i < t; i++){
            cin >> in[i];
        }
        sort(in.begin(), in.end());

        int min = in[t-1]*2;
        int max = in[0]*2;
        for (int i = 0; i < t / 2; i++) {
            int temp = in[i]+in[t-1-i];
            if (temp > max) {
                max = temp;
            }
            if (temp < min) {
                min = temp;
            }
            
        }
        cout <<max - min << endl;;
    }
    return 0;
}