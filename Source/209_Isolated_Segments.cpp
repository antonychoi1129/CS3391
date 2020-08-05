/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<algorithm>
using namespace std;

struct P{
	double x,y;
};

struct Sm{
	P f, t;
}lines[100];

bool bt(double m, double left, double right){
	return left <= m && m <= right;
}

bool olep(Sm s, P p){
	static double bigX, bigY, smlX, smlY;
	smlX = min(s.f.x, s.t.x);
	bigX = max(s.f.x, s.t.x);
	smlY = min(s.f.y, s.t.y);
	bigY = max(s.f.y, s.t.y);
	
	if( bt(p.x,smlX,bigX) && bt(p.y,smlY,bigY) ){
		if( (s.f.x-s.t.x)*(p.y-s.f.y) == 
			(s.f.y-s.t.y)*(p.x-s.f.x) )
			return true;
	}
	return false;
}

double cp(P o, P p1, P p2){
	return (p1.x-o.x) * (p2.y-o.y) - (p1.y-o.y) * (p2.x-o.x) ;
}

bool itst(Sm s1, Sm s2){
	
	if( olep(s1, s2.f) || olep(s1, s2.t) || 
		olep(s2, s1.f) || olep(s2, s1.t) )
		return true;
		
	if( cp(s1.f, s1.t, s2.f)*cp(s1.f, s1.t, s2.t)<0 &&
		cp(s1.t, s1.f, s2.f)*cp(s1.t, s1.f, s2.t)<0 &&
		cp(s2.f, s2.t, s1.f)*cp(s2.f, s2.t, s1.t)<0 &&
		cp(s2.t, s2.f, s1.f)*cp(s2.t, s2.f, s1.t)<0
	) return true;
	
	return false;
}

int main(){
	int cases;
	scanf("%i",&cases);
	while(cases--){
		int m;
		scanf("%i",&m);
		
		int i,j;
		for(i=0; i<m;i++)
			scanf("%lf %lf %lf %lf",&lines[i].f.x,&lines[i].f.y,&lines[i].t.x,&lines[i].t.y);
		
		int res=0;
		for(i=0;i<m;i++){
			bool found = false;
			for(j=0; j<m; j++){
				if(i==j) continue;
				if(itst(lines[i],lines[j])){
					found = true;
					break;
				}
			}
			
			if(!found) res++;
		}
		
		
		printf("%i\n",res);
	}
	
	return 0;
}
