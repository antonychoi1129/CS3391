#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define INF (int)1e9

struct Node{
	int to, length;
	bool carrying;
	Node(int a,int b,int c){
		to = a; length = b; carrying = c;
	}

	Node(){}
	
	bool operator < (const Node & n)const{
		return n.length<length;
	}
};



int main(){
	//ios::sync_with_stdio(false);

	int setNum = 1;
	int jNum, rNum;	//number of junctions, number of roads
	while(cin>>jNum>>rNum){
		cout<<"Set #"<<setNum++<<endl;

		vector< vector<Node> > bangladesh;
		bangladesh.assign(jNum+1, vector<Node>());
		
		for(int i=0; i<rNum; i++){
			int j1, j2, length;
			cin>>j1>>j2>>length;
			bangladesh[j1].push_back(Node(j2,length,0));
			bangladesh[j2].push_back(Node(j1,length,0));
		}
		
		int dist[jNum+1][4];
		bool ved[jNum+1][4];
		
		for(int i=0; i<=jNum+1; i++)
			for(int j=0; j<4; j++){
				dist[i][j]=INF;
				ved[i][j] = false;
			}
		dist[0][0] = 0;
		
		priority_queue<Node> dijk;
		dijk.push(Node(0,0,0));
		
		bool ok = false;
		while(!dijk.empty()){
			Node root = dijk.top();
			dijk.pop();
			if(ved[root.to][root.carrying]) continue;
			if(root.to == jNum-1 && !root.carrying){
				cout << dist[jNum-1][0] <<endl;
				ok = true;
				break;
			}
			ved[root.to][root.carrying] = true;
			for(int i=0; i<bangladesh[root.to].size(); i++)
				if(
					dist[bangladesh[root.to][i].to][!root.carrying]
					>
					root.length + bangladesh[root.to][i].length
				){
					dist[bangladesh[root.to][i].to][!root.carrying]
					= root.length + bangladesh[root.to][i].length;
					dijk.push
							(	Node(
									bangladesh[root.to][i].to, 
									dist[bangladesh[root.to][i].to][!root.carrying],
									!root.carrying
								)
							);
				}
		}
		if(!ok) cout<<"?"<<endl;
		
	}

	return 0;
}
