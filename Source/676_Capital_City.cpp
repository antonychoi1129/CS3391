/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>

#define oo (int)1e9;

#define MAXN 1000
int country[MAXN][MAXN];

//https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm
void fwa(int n){
	int i,j,k;	//i = start; j = target; k = middle
	for(k=1; k<=n; k++)
		for(i=1; i<=n; i++)
			for(j=1;j<=n;j++){
				if(country[i][j]>country[i][k]+country[k][j])
					country[i][j] = country[i][k]+country[k][j];
			}
}

int main(){
	int n, m;
	while(~scanf("%i %i",&n,&m)){
		int i,j;
		//Build the conuntry
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				country[i][j] = oo;
				
		for(i=1;i<=n;i++)
			country[i][i] = 0;
			
		while(m--){
			int u, v, w;
			scanf("%i %i %i",&u,&v,&w);
			country[u][v] = country[v][u] = w;
		}
		
		//Gen Ans
		fwa(n);
		int captialCity=0;
		int minD=oo;
		
		for(i=n;i>=1;i--){
			int d2all=0;
			for(j=1;j<=n;j++)
				d2all+=country[i][j];
			if(d2all<=minD){
				minD= d2all;
				captialCity = i;
			}
		}
		printf("%i\n",captialCity);
	}
}
