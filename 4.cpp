#include<iostream>
#include<string>
#include<queue>
#include<set>
using namespace std;

int KMP(string s, string p){
    int len = s.length();
    int M = p.length();
    int lps[M];
    int l = 0;
    lps[0] = 0;
    int i,j;
    i = 1;
    while(i < M){
        if(p[i] == p[l]){
            l++;
            lps[i] = l;
            i++;
        }
        else{
            if(l != 0){
                l = lps[l-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }

    i = j = 0;
    int cnt;
    cnt  = 0;
    while(i < len){
        if(p[j] == s[i]){
           
            i++; j++;
        } 
        if(j == M){
            cnt++;
            j = lps[j - 1]; 
        }
        else if(i < len && p[j] != s[i]){
            if(j != 0) 
                j = lps[j-1];
            else
                i++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, k, ans;
    string s1,s2;
    set<string> dict;
    cin >> t;
    while(t--){
        cin >> s1 >> s2;
        cin >> k;
        ans = 0;
        // k += 1;
        for(int i = 0; i < s1.length(); i++){
            for(int j = i+k; j < s1.length(); j++){
                string sub = s1.substr(i,j);
                dict.insert(sub);

            }
        }
        //  for(int i = 0; i < s2.length(); i++){
        //     for(int j = i+k; j < s2.length(); j++){
        //         string sub = s2.substr(i,j);
        //         dict.insert(sub);
                
                    

        //     }
        // }
        for (set<string>::const_iterator it=dict.begin(); it!=dict.end(); ++it){
                int x,y;
                string p = *it;
                // cout << p << endl;
                x = KMP(s1, p);
                y = KMP(s2, p);
                if(x > 0 && y > 0){
                    // cout << p << endl;
                    ans += x + y;
                    // cout << "xy " << x << " " << y << endl;
                    
                }
        }
        cout << ans << endl;
    }
    return 0;
}