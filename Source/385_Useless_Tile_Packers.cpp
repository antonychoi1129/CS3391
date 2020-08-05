/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

//I'm horrible at maths, don't read.

#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int oo = 6000;	//0<=x,y<=1000
const int MAXV = 200;	//3<=N<=100

struct P{
	int x,y;
}v[MAXV];

//Cross Product with point o
double cp(P o, P a, P b){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
	// return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y);
}

double cx(P a, P b){
	return a.x*b.y - b.x*a.y;
}

//Magnitude
double mnt(P a, P b){
	int xdiff = a.x-b.x, ydiff = a.y-b.y;
	return sqrt(xdiff*xdiff+ydiff*ydiff);
}

//angle comparison for sorting
bool agCmp(P a, P b){
	double crossP = cp(v[0], a, b);
	if(crossP!=0) return crossP > 0;
	return mnt(b,v[0]) > mnt(a,v[0]);
}

int main(){
	int vNum;
	
	int ts=1;
	while(~scanf("%i",&vNum)){
		if(vNum==0) break;
		printf("Tile #%i\n",ts++);
		
		int i,j;
		
		P lMost = {oo,oo};
		int lmi = 0;
		for(i=0;i<vNum;i++){
			scanf("%i %i",&v[i].x,&v[i].y);
			if(v[i].y<lMost.y || (v[i].x<lMost.x) && v[i].y==lMost.y ){
				lMost = v[i];
				lmi = i;
			}
		}
		
		double tileSize=0;
		v[vNum] = v[0];
		for(i=1;i<=vNum;i++)
			tileSize+=cx(v[i-1],v[i]);
		tileSize*=0.5;
		
		swap(v[0],v[lmi]);
		sort(v+1, v+vNum, agCmp);
		
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
		
			
		double hullSize=0;
		for(i=1;i<st;i++)
			hullSize+=cx(res[i-1],res[i]);
		hullSize*=0.5;
		
		tileSize = fabs(tileSize);
		//printf("tSize:%.2lf\n",tileSize);
		hullSize = fabs(hullSize);
		//printf("hullSize:%.2lf\n",hullSize);
		
		printf("Wasted Space = %.2lf %%\n\n" , (1-tileSize/hullSize)*100); 
	}

	return 0;
}
