/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int abs(int a){
	if(a<0) return -a;
}

char codes[505][4+1];
int rolls[10][10];

int parent[10000];

int find(int t){
	if(parent[t]<0) return t;
	else{
		parent[t] = find(parent[t]);
		return parent[t];
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

struct Edge{
	int u, v, w;
	Edge(int a, int b, int c){
		u=a;
		v=b;
		w=c;
	}
	Edge(){}
}es[500*(500)/2+5];

int compare(const void*a, const void*b){
	Edge *edgeA = (Edge *)a;
	Edge *edgeB = (Edge *)b;
	return ( edgeA->w - edgeB->w );	//ASC
	//return ( edgeB->w - edgeA->w );	//DESC
}

void calRolls(){
	int i,j,r;
	for(i=0; i<10; i++)
		for(j=i; j<10; j++){
			r = abs(i-j);
			if(r>5) r = 10-r;
			rolls[i][j]=rolls[j][i]=r;
		}
}

int weight(char*a, char*b){
	int ans=0;
	for(int i=0; i<4; i++)
		ans+=rolls[a[i]-'0'][b[i]-'0'];
	
	return ans;
}

char all0[5]="0000";

int main(){
	calRolls();
	
	int ttt;
	scanf("%i",&ttt);
	for(int tcs=0; tcs<ttt; tcs++){
		int n;
		scanf("%i",&n);
		
		scanf("%s",codes[0]);
		int firstRoll=weight(all0,codes[0]);
		for(int i=1; i<n; i++){
			scanf("%s",codes[i]);
			if(firstRoll > weight(all0,codes[i]))
				firstRoll = weight(all0,codes[i]);
		}
		
		int edgeNum=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<i; j++){
				int a, b;
				a = atoi(codes[i]);
				b = atoi(codes[j]);
				
				parent[a] = parent[b] = -1;
				
				es[edgeNum]=Edge(a,b, weight(codes[i],codes[j]));
				edgeNum++;
			}
		
		int ans = firstRoll;
		//Kruskal
		qsort(es, edgeNum, sizeof(Edge), compare);
		memset(parent,-1,sizeof(parent));
		for(int i=0; i<edgeNum; i++){
			int codeA = find(es[i].u);
			int codeB = find(es[i].v);
			if(codeA!=codeB){
				uion(codeA,codeB);
				ans+=es[i].w;
			}
		}
		
		printf("%i\n",ans);
	}

	return 0;
}
