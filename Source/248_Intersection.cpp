/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

#define $(x) {cout << #x << " = " << x << " " << "\n";}

#define oo 0x3f3f3f3f	//https://www.kawabangga.com/posts/1153s
#define r0 1e-9;

struct P{
	double x,y;
};

struct Sm{
	P f, t;
};

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

Sm line;
Sm rtgSeg[4];
double xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;

bool inRegtangle(){
	
	P a = line.f;
	P b = line.t;
	
	// Inside/on those 4 sides
	if( (xleft<=a.x&&a.x<=xright && ybottom<=a.y && a.y<=ytop)||
		(xleft<=b.x&&b.x<=xright && ybottom<=b.y && b.y<=ytop) )
		return true;
		
	// Hi-bin cases	Hi-bin = "揩邊", marginal cases.
	for(int i=0; i<4; i++)
		if( itst(line,rtgSeg[i]) ) return true;
	
	return false;
}

int main(){
	int cases;
	scanf("%i",&cases);
	while(cases--){
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&xstart, &ystart, &xend, &yend, &xleft, &ytop, &xright, &ybottom);
		
		line={{xstart,ystart},{xend,yend}};
		
		if(xleft>xright)
			swap(xleft,xright);
		if(ytop<ybottom)
			swap(ytop,ybottom);
		
		rtgSeg[0] = { {xleft,ytop} , {xright,ytop} };			//top
		rtgSeg[1] = { {xleft,ybottom} , {xright,ybottom} };	//bottom
		rtgSeg[2] = { {xleft,ytop} , {xright,ybottom} };		//left
		rtgSeg[3] = { {xright,ytop} , {xright,ybottom} };		//right
		
		if(inRegtangle())
			puts("T");
		else puts("F");
		
	}
	
	return 0;
}
