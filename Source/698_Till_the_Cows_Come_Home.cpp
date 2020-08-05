/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>

#include<vector>
#include<queue>
using namespace std;

#define oo (int)1e9

struct Node{
	int to, w;
	Node(int a, int b){
		to = a;
		w  = b;
	}
	Node(){};
	bool operator < (const Node &n) const{
		return w > n.w;
	}
};

int main(){
	int i,j;
	int n,t;
	while(~scanf("%i %i",&n,&t)){
		vector< vector<Node> > field;
		field.assign(n+1,vector<Node>());
		
		for(i=1; i<=t; i++){
			int lm1, lm2, dist;
			scanf("%i %i %i",&lm1, &lm2, &dist);
			//	Bi-directional
			field[lm1].push_back(Node(lm2,dist));
			field[lm2].push_back(Node(lm1,dist));
		}
		int dists[n+1];
		bool ved[n+1];
		for(i=1;i<=n;i++){
			dists[i] = oo;
			ved[i] = false;
		}
		dists[1] = 0;
		
		priority_queue<Node> dijk;
		dijk.push({1,0});
		while(!dijk.empty()){
			Node top = dijk.top();
			dijk.pop();
			if(ved[top.to]) continue;
			ved[top.to] = true;
			
			for(i=0; i<field[top.to].size();i++){
				Node nodeto = field[top.to][i];
				int ito = nodeto.to;
				if(dists[ito]>top.w+nodeto.w){
					dists[ito] = top.w+nodeto.w;
					if(ito==n) break;
					dijk.push(Node(ito,dists[ito]));
				}
			}
		}
		printf("%i\n",dists[n]);
	}

	return 0;
}
