/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

const short oo = 1e4;
const int MAXV = 300;

struct P{
	short x,y;
}v[MAXV];

//Cross Product with point o
int cp(P o, P a, P b){
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y);
}

//Magnitude
int mnt(P a, P b){
	int xdiff = a.x-b.x, ydiff = a.y-b.y;
	return sqrt(xdiff*xdiff+ydiff*ydiff);
}

//angle comparison for sorting
bool agCmp(P a, P b){
	int crossP = cp(v[0], a, b);
	if(crossP!=0) return crossP > 0;
	return mnt(b,v[0]) > mnt(a,v[0]);
}

int main(){
	int cases;
	scanf("%i",&cases);
	printf("%i\n",cases);
	while(cases--){
		int i,j;
		int vNum;
		scanf("%i",&vNum);
		
		P lMost = {oo,oo};
		int lmi = 0;
		
		for(i=0;i<vNum;i++){
			scanf("%i %i",&v[i].x,&v[i].y);
			if(v[i].y<lMost.y || (v[i].x<lMost.x) && v[i].y==lMost.y ){
				lMost = v[i];
				lmi = i;
			}
		}
		if(cases>0)scanf("%*i");	//delimiter -1
		
		swap(v[0],v[lmi]);
		sort(v+1, v+vNum, agCmp);
		
		//return
		v[vNum] = v[0];
		P res[MAXV];
		res[0] = v[0];
		res[1] = v[1];
		int st = 2;	//Stack top;
		for(i=st; i<=vNum;i++){
			while(0>=cp(res[st-2],res[st-1],v[i]) && st>=2)
				st--;
			res[st++] = v[i];
		}
		
		printf("%i\n",st);
		for(i=0;i<st;i++)
			printf("%i %i\n",res[i].x,res[i].y);
		if(cases>0)puts("-1");	//Show my delimiter
	}
	
	return 0;
}
