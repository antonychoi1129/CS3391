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
    cout << "Rabbits:" << endl;
    while(t--){
        vector<int> in(10);
        for(int i=0; i < 10; i++){
            cin >> in[i];
        }

        vector<int> v = in;
        sort(v.begin(), v.end()); 
        bool flag = true;
        for(int i=0; i < 10; i++){
            if(in[i] != v[i])   
                flag = false;
        }

        if(!flag){
            sort(v.begin(), v.end(), greater<int>()); 
            flag = true;
            for(int i=0; i < 10; i++){
                if(in[i] != v[i])   
                    flag = false;
            }
        }
       

        if(flag) cout << "Ordered" << endl;
        else cout << "Unordered" << endl;
    }
    return 0;
}