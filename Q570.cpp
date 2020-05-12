#include<iostream>
#include<string>
#include<vector>
using namespace std;

int step(char c){
    return min((int)(c-'A'), (int)('Z' - c) + 1);
}
int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        int len = s.length();
        vector<int> notA;
        int sum = 0;
        for(int i=0; i < len;i++){
            if(s[i] != 'A'){
                sum += step(s[i]);
                notA.push_back(i);
            }
        }
        int r, l = 0;
        int s = 0; // If all a, not additional steps
        if(sum > 0){
            s = notA[notA.size()-1];//steps from first non-a to last non-a
            if(notA[0] == 0){//if first char is non-a
                for(int i = 0; i < notA.size()-1; i++){
                    l = notA[i];
                    r = notA[i+1];
                    s = min(s, min(l*2+len-r,(len-r)*2+l)); // find minimum step from left non-a to right non-a
                }
            }
            else{
                l = 0;
                for(int i = 0; i < notA.size(); i++){
                    r = notA[i];
                    s = min(s, min(l*2+len-r,(len-r)*2+l));
                    l = notA[i];
                }
            }
        }
        cout << sum + s << endl;
    }
}