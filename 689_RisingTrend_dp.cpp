#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    int LIS;
    while(cin >> n){
        int a[n];
        vector<int> input(n);
        for(int i=0; i < n; i++){
            cin >> input[i];
            a[i] = 1;
        } 

        for(int i=0 ; i < n; i++){
            for(int j=0; j < i-1; j++){
                if(input[i] >= input[j]) a[i] = a[j] + 1;
            }
        }

        cout << a[n-1] << endl;
    }
}