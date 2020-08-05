/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define tp pair<int, pair<int, int> >
int parent[1005];

int find(int city){
	if(parent[city]<0) return city;
	else{
		parent[city] = find(parent[city]);
		return parent[city];
	}
}

void uion(int a, int b){
	int aRoot = find(a);
	int aHeight = abs(parent[aRoot]);
	int bRoot = find(b);
	int bHeight = abs(parent[bRoot]);
	
	if(aHeight>bHeight)
		parent[bRoot] = aRoot;
	else
		parent[aRoot] = bRoot;
	
	if(aHeight==bHeight) parent[bRoot]--;
}

int main(){
	int n,m;
	while(~scanf("%i %i",&n, &m)){
		if(n==0&&m==0) break;
		
		vector<tp>lines;
		for(int i=0; i<m; i++){
			int u, v, w;
			scanf("%i %i %i",&u,&v,&w);
			lines.push_back({w,{u,v}});
		}
		
		memset(parent,-1,sizeof(int)*n);
		sort(lines.begin(), lines.end());	//Sort weight ASC
		int link=0;
		int cost=0;
		char unused[2000];
		vector<tp>::iterator it;
		for(it=lines.begin();it!=lines.end();it++){
			int cityA, cityB;
			cityA = it->second.first;
			cityB = it->second.second;
			
			int rootA = find(cityA);
			int rootB = find(cityB);
			if(rootA!=rootB){
				link++;
				cost+=it->first;
				uion(rootA,rootB);
			}
			else unused.push_back(it->first);
		}
		
		if(link+1<n) printf("\\(^o^)/ pray to god\n");
		else{
			printf("Min cost: %i\n",cost);
			vector<int>::iterator ir;
			for(ir=unused.begin(); ir!=unused.end(); ir++){
				if(ir!=unused.begin()) printf(" ");
				printf("%i",*ir);
			}
			printf("\n");
		}
			//printf("%i %i %i\n",it->second.first, it->second.second, it->first);
	}

	return 0;
}
