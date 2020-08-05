/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<cstdlib>

int parent[505];
int output;

int find(int city){
	if(parent[city]<0) return city;
	else{
		parent[city] = find(parent[city]);
		return parent[city];
	}
}

void uion(int a, int b){
	int aRoot = find(a);
	int aSize = -parent[aRoot];
	int bRoot = find(b);
	
	parent[aRoot] = bRoot;
	parent[bRoot]-=aSize;
	int bSize = -parent[bRoot];
	if(bSize >output) output = bSize;
}

int main(){
	int n,m;
	while(~scanf("%i %i",&n, &m)){
		if(n==0&&m==0) break;

		memset(parent,-1,sizeof(int)*(n+1));
		output = 1;

		int maxPPA;
		for(int i=0; i<m; i++){
			int u,v,w;
			scanf("%i %i %i",&u,&v,&w);
			if(i==0) maxPPA = w;
			if(w<maxPPA) continue;
			
			if(w>maxPPA){
				maxPPA = w;
				memset(parent,-1,sizeof(int)*(n+1));
			}
			
			int rootA = find(u);
			int rootB = find(v);
			if(rootA!=rootB)
				uion(rootA,rootB);
		}
		printf("%i\n",output);
	}

	return 0;
}
