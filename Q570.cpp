#include<iostream>
#include<string>
#include<vector>
using namespace std;

int step(char c){
    if((int)(c-'A') <= 13) 
        return (int)(c-'A');
    return 13 - ((int)(c - 'N'));
}
int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        bool flag = true;
        cin >> s;
        vector<int> notA;
        int res = 0;
        for(int i=0; i < s.length();i++){
            if(s[i] != 'A'){
                res += step(s[i]);
                notA.push_back(i);
            }
           
        }
        //count step for left/right
        if(res > 0){
            if(notA.size() > 1 && notA[0] == 0){
                int right = s.length() - notA[1];
                for (int i = 1; i < notA.size()  - 1; i++)
				    right = min(notA[i] * 2 + s.length() - notA[i + 1], right);
            }
            else if(notA[0] > 0){
                if(notA[notA.size()-1] <= 1 + notA[0] + s.length() - 1 - notA[1]){
                    res += notA[notA.size()-1];
                } 
                else {
                    res += 1 + notA[0] + s.length() - 1 - notA[1];
                }
            }
        }

        cout << res << endl;
    }
}