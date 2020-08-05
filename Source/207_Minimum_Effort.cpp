
#include<cstdio>
#include<map>
#include<queue>
#include<string>
using namespace std;

#define oo (int)1e10

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

bool isNum(char c){
	return (c>='0' && c<='9');
}

int ppp;
void makePath(int to, int pre[], int path[]){
	if(pre[to]==-1) return;
	makePath(pre[to], pre, path);
	path[ppp++] = to;
}

char places[20] [300];

int main(){
	int n;
	int i,j,k;
	map<string, int>::iterator it;
	
	while(~scanf("%i\n",&n)){
		map<string, int> pMap;
		vector< vector<Node> > roads;
		roads.assign(n+1, vector<Node>());
		
		bool num = false;
		for(i=0;i<n;i++){
			gets(places[i]);
			pMap.insert(pair<string,int>(places[i],i));
		}
		
		int p;
		char line[60];
		scanf("%i\n",&p);
		for(i=0; i<p; i++){
			gets(line);
			char place1[20], place2[20];
			int w1, w2;
			w1 = w2 = -1;
			
			for(j=1; line[j]!=':'; j++){}
			strncpy(place1,line,j);
			place1[j]='\0';
			k=j;
			do{
				for(k++; line[k]!=' ' ; k++);
				strncpy(place2,line+j+1,k-j-1);
				place2[k-j-1] = '\0';
			}while(pMap.find(place2)==pMap.end());

			sscanf(line+k, "%i %i", &w1, &w2);
			
			//printf("w1: %i w2: %i\n",w1,w2);
			
			//uni-directional
			int p1 = pMap.find(place1)->second;
			int p2 = pMap.find(place2)->second;
			if(w2==-1){
				roads[p1].push_back( Node(p2, w1) );
			}
			//bi-directional
			else{
				roads[p1].push_back( Node(p2, w1) );
				roads[p2].push_back( Node(p1, w2) );
			}
		}
		
		int office = pMap.find("office")->second;
		int hall = pMap.find("hall")->second;
		
		int pre[n];
		int path[n*2+5];
		ppp=0;
		int dist[n];
		bool ved[n];
		
		for(i=0; i<n; i++){
			dist[i] = oo;
			ved[i] = false;
		}

		priority_queue<Node> dijk;
		dijk.push(Node(office,0));
		while(!dijk.empty()){
			Node r = dijk.top();
			dijk.pop();
			
			if(ved[r.to])continue;
			if(r.to==hall) break;
			
			ved[r.to] = true;
			for(i=0; i<roads[r.to].size(); i++)
				if(dist[ roads[r.to][i].to ] > r.w + roads[r.to][i].w){
					dist[ roads[r.to][i].to ] = r.w + roads[r.to][i].w;
					dijk.push( Node( roads[r.to][i].to , dist[roads[r.to][i].to] ) );
					pre[ roads[r.to][i].to ] = r.to;
				}
		}
		int ans = dist[hall];
		pre[office] = -1;
		makePath(hall, pre, path);
		
		for(i=0; i<n; i++){
			dist[i] = oo;
			ved[i] = false;
		}
		
		dijk = priority_queue<Node>();
		dijk.push(Node(hall,0));
		while(!dijk.empty()){
			Node r = dijk.top();
			dijk.pop();
			if(ved[r.to])continue;
			if(r.to==office) break;
			
			ved[r.to] = true;
			for(i=0; i<roads[r.to].size(); i++)
				if(dist[ roads[r.to][i].to ] > r.w + roads[r.to][i].w){
					dist[ roads[r.to][i].to ] = r.w + roads[r.to][i].w;
					dijk.push( Node( roads[r.to][i].to , dist[roads[r.to][i].to] ) );
					pre[ roads[r.to][i].to ] = r.to;
				}
		}
		
		ans+=dist[office];
		pre[hall] = -1;
		makePath(office, pre, path);
		printf("%i\noffice",ans);
		for(i=0; i<ppp; i++)
		 	printf(" -> %s", places[ path[i] ]);
		puts("\n");
	}

	return 0;
}
