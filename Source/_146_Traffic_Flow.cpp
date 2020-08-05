/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#define oo 0x3f3f3f3f	//https://www.kawabangga.com/posts/1153
#define MAXV 15	//Wow, only a few vertices are tested, prim is the best under this scenario!?

int dist[MAXV][MAXV], highCost[MAXV];
bool ved[MAXV];

int prim(int vNum){
	int minCap = oo;
	memset(ved,false,sizeof(ved));
	int i,j;
	
	//Select vertex 0 as the starting point
	ved[0] = true;
	for(i=0;i<vNum;i++)
		highCost[i] = dist[0][i];
		
	for(i=0; i<vNum; i++){	//vNum iterations
		//find max edge connecting 2 v sets
		int temp = 0;
		int udV;	//to be updated vertex
		for(j=0;j<vNum;j++)
			if(!ved[j] && temp<highCost[j])
				temp = highCost[udV = j];	//will update udV
		
		if(temp==0) break;	//M(aximum)ST found
		
		//Update
		ved[udV] = true;
		if(temp<minCap) minCap = temp;	//Ummm... I thought it will always be the minCap if we update vertex
		for(j=0;j<vNum;j++)
			if(!ved[j] && highCost[j] < dist[udV][j])
				highCost[j] = dist[udV][j];
		
	}
	
	return minCap;
}

int main(){
	int cases;
	scanf("%i",&cases);
	for(int c=1; c<=cases; c++){
		memset(dist, 0, sizeof(dist));
		int n, m;
		scanf("%i%i",&n,&m);
		while(m--){
			int u, v, capacity;
			scanf("%i%i%i",&u,&v,&capacity);
			if(capacity > dist[u][v])
				dist[u][v] = dist[v][u] = capacity;
		}
		
		printf("Case #%i: %i\n",c,prim(n));
	}
	
	return 0;
}
