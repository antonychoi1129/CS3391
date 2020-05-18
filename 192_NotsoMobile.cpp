#include <iostream>
#include <vector>

using namespace std;

int eq(int w1,int d1,int w2,int d2){
	int a,b,c,d;
    int sub1, sub2;

    sub1 = w1;
    sub2 = w2;

	if (w1==0) {
		cin >> a >> b >> c >> d;
		sub1 = eq(a,b,c,d);
	}

    if (w2 == 0){
        cin >> a >> b >> c >> d;
		sub2 = eq(a,b,c,d);
    }

    if(sub1*d1 == sub2*d2)
        return (sub1+sub2);
    
    return 0;
}

int main(){
	int w1,w2,d1,d2;
	int t;
    vector<bool> ans;
	cin >> t;
	while(t--){
        cin.ignore(1,'\n');
		cin >> w1 >> d1 >> w2 >>d2;
        ans.resize(ans.size()+1, eq(w1,d1,w2,d2));
    }

    for(int i = 0; i < ans.size(); i++){
        if (ans[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        if (i != ans.size()-1){
            cout << endl;
        }
        
    }
    return 0;
}