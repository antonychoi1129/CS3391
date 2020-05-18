#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    
    while(cin >> n){
        int a[n];
        int input[n];
        // int parent[n];

        for(int i=0; i < n; i++){
            cin >> input[i];
            a[i] = 0;
        } 

        int length = 0;
        for(int i=0 ; i < n; i++){
            int low = 1;
            int high = length;
            while(low<=high){
                int mid = (low+high+1)/2;
                cout << mid << " " << a[mid] << " " << input[a[mid]] << " " << input[i] << endl;
                if(input[a[mid]] <= input[i])
                    low = mid+1;
                else
                    high = mid-1;      
            }
            int pos = low;
            // parent[i] = a[pos-1];
            a[pos] = i;
            if(pos > length)
                length = pos;
        }

        // int LIS[length];
        // int k = a[length];
        // for(int i=length-1; i>=0; i--){
        //     LIS[i] = input[k];
        //     k = parent[k];
        // }
        
        // for(int i=0; i<length; i++){
        //     cout << LIS[i] << " ";
        // }
        // cout << endl;
        cout << length << endl;
    }
}