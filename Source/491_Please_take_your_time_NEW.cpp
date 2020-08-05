/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int oo = 1e9;

struct Node{
	int to, w, rDist;
	Node(int a, int b, int r){
		to = a;
		w  = b;
		rDist = r;
	}
	Node(){};
	
	bool operator < (const Node &n) const{
		return w > n.w;
	}
};

int main(){
	int jNum, rNum, tNum;	// j - junction; r - road; t - trap
	while(~scanf("%i%i%i",&jNum, &rNum, &tNum)){
		int i,j;
		
		//Forest building
		vector< vector<Node> > forest;
		forest.assign(jNum+1, vector<Node>());
		
		for(i=0; i<rNum; i++){
			int u, v, m;
			scanf("%i%i%i",&u, &v, &m);
			forest[u].push_back( Node(v, m, 0) );
			forest[v].push_back( Node(u, m, 0) );
		}
		
		//Time init
		int time = oo;
		
		//ved Init
		bool ved[jNum][...]	
		
		//Traps
		int traps[jNum+1];
		memset(traps,0,sizeof(traps));
		for(i=0; i<tNum; i++){
			int pos, recoveryDist;
			scanf("%i%i",&pos, &recoveryDist);
			traps[pos] = recoveryDist;
		}

		priority_queue<Node> dijk;
		dijk.push( Node(1,0,traps[1]) );
		while(!dijk.empty()){
			Node top = dijk.top();
			dijk.pop();
			
			for(i=0; i<forest[top.to].size(); i++){
				Node nxt = forest[top.to][i];
				int next = nxt.to;
				
				int nextCost = min(nxt.w*2, top.rDist + nxt.w);
				if(next == jNum){
					time = min(time, top.w+nextCost);
					continue;
				}

				int newRDist = max(0, top.rDist-nxt.w) + traps[next];
				dijk.push( Node( next, top.w+nextCost, newRDist ) );
			}
		}
		
		if(time>=oo){
			puts("Impossible!");
		}
		else{
			printf("%i\n",time);
		}
	}

	return 0;
}
