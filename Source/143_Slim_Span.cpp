/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define oo 1e9

const int mx = 105;


struct Edge{
	int fm, to, w;
	Edge(){}
	Edge(int f, int t, int www){
		fm = f;
		to = t;
		w = www;
	}
};

int compare(const void*a, const void*b){
	Edge *edgeA = (Edge *)a;
	Edge *edgeB = (Edge *)b;
	return ( edgeA->w - edgeB->w );	//ASC
	//return ( edgeB->w - edgeA->w );	//DESC
}

int p[mx];
int find(int t){
	if(p[t]==t) return t;
	else{
		p[t] = find(p[t]);
		return p[t];
	}
}

int main(){
	int vNum, eNum;
	int i,j;
	while(~scanf("%i %i",&vNum, &eNum)){
		if(vNum==0&& eNum==0) break;
		
		Edge e[eNum];
		for(i=0;i<eNum;i++)
			scanf("%i %i %i", &e[i].fm, &e[i].to, &e[i].w);
		qsort(e,eNum,sizeof(Edge),compare);
		
		int ans = oo;
		for(int i=0; i<eNum; i++){
			for(j=0;j<=vNum;j++) p[j] = j;	//parent init;
			int num = 0;
			for(j=i;j<eNum;j++){
				Edge je = e[j];
				int from = find(je.fm);
				int tooo = find(je.to);
				if(from!=tooo){
					p[from] = tooo;
					num++;
					if(num+1==vNum)
						ans = min(ans, e[j].w - e[i].w);	//slim
				}
			}
		}
		if(ans==oo) puts("-1");
		else printf("%i\n",ans);
	}

	return 0;
}
