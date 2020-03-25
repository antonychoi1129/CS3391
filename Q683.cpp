#include<iostream>
#include<vector>

using namespace std;

int main(){
    int k,a,b,v;
    while(cin >> k >> a >> b >> v){
        int used = 0;
        int box = 0;
        while(1){
            if(a == 0) break;
            box++;
            int temp = 0;
            int placed = 0;
            for(int i=0; i < k; i++){
                if(used + i <= b){ 
                    if(a >= v*(i+1)){
                        placed = v*(i+1);
                        temp = i;
                    }
                    else {
                        placed = a;
                    }
                }
            }
            a -= placed;
            used += temp;
        }
        cout << box << endl;
    }
}