/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<math.h>

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
	int aSize = abs(parent[aRoot]);
	int bRoot = find(b);
	int bSize = abs(parent[bRoot]);

	if(aSize>bSize){
		parent[bRoot] = aRoot;
		parent[aRoot]-=bSize;
		if(-parent[aRoot] >output) output = -parent[aRoot];
	}
	else{
		parent[aRoot] = bRoot;
		parent[bRoot]-=aSize;
		if(-parent[bRoot] >output) output = -parent[bRoot];
	}
}

struct Edge{
	int u, v, w;
	Edge(int a, int b, int c){
		u = a;
		v = b;
		w = c;
	}
	Edge(){}
}edges[1000005];

int compare(const void*a, const void*b){
	Edge *edgeA = (Edge *)a;
	Edge *edgeB = (Edge *)b;
	return ( edgeB->w - edgeA->w );
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
			if(w>maxPPA) maxPPA = w;
			edges[i]=Edge(u,v,w);
		}

		for(int i=0; i<m; i++){
			//printf("%i %i %i\n",edges[i].u,edges[i].v,edges[i].w);
			if(edges[i].w!=maxPPA) continue;
			int rootA = find(edges[i].u);
			int rootB = find(edges[i].v);
			if(rootA!=rootB)
				uion(rootA,rootB);
		}
		printf("%i\n",output);
	}

	return 0;
}

/*
4 5
1 2 100
1 3 100
1 4 1
2 3 100
3 4 1
9 14
1 2 9
6 9 8
2 4 9
2 3 9
4 5 1
4 3 9
5 9 2
9 8 9
7 8 9
7 9 5
6 7 9
5 6 4
5 8 7
7 5 9
0 0
*/
