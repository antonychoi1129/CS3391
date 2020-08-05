#include<iostream>
#include<vector>
using namespace std;

int ans;

void knock(int target, bool* knocked, vector<int> fall[]){
	if(!knocked[target]){
		knocked[target] = true;
		ans++;

		while(!fall[target].empty()){
			int next = fall[target].back();
			fall[target].pop_back();
			if(!knocked[next])
				knock(next, knocked, fall);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int testcases;
	cin >> testcases;
	for(int t=0; t<testcases; t++){
		int n,m,l;	//n - number of domino tiles
		cin>>n>>m>>l;

		vector<int>fall [n+1];

		int x,y;	// domino x fall which causing y fall as well
		for(int i=0; i<m; i++){
			cin>>x>>y;
			fall[x].push_back(y);
		}

		bool knocked[n+1];
		for(int i=1; i<=n; i++) knocked[i] = false;
		ans = 0;

		int z;	//knocked domino
		for(int i=0; i<l; i++){
			cin>>z;
			if(!knocked[z])
				knock(z, knocked, fall);
		}
		cout<<ans<<endl;
	}

	return 0;
}
