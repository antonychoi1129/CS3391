/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define oo (int)1e9
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sfd_sn(n) scanf("%d\n",&n)
#define sfs(n) scanf("%s",n)
#define sfc(n) scanf("%c",&n)
#define sfl(n) scanf("%lld",&n)

#define pd(n) printf("%d\n",n)

// #define DEBUG true
#ifdef DEBUG
	#include<iostream>	//Memory Monster
	#define $(v) cout<<#v<<"\t=\t"<<v<<endl
	#define $printf(fs, ...) printf(fs, ##__VA_ARGS__)
#else
	#define $(v) 
	#define $printf(fs, ...)
#endif
//--------------------------------------------------------------------------

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

Sm straws[15];
int parent[15];

int find(int n){
	if(parent[n]==n) return n;
	else{
		parent[n] = find(parent[n]);
		return parent[n];
	}
}

void uion(int a, int b){
	int aRoot = find(a);
	int bRoot = find(b);
	parent[aRoot] = bRoot;
}

void m(){
	bool first = true;
	int cases;
	sfd(cases);
	while(cases--){
		int n;
		sfd(n);
		
		int i,j;
		//init
		for(i=1; i<=n; i++)
			parent[i] = i;
		
		for(i=1; i<=n; i++){
			scanf("%lf %lf %lf %lf",&straws[i].f.x,&straws[i].f.y,
								&straws[i].t.x,&straws[i].t.y);
		}
		
		for(i=1; i<=n; i++)
			for(j=i+1; j<=n; j++)
				if( itst(straws[i],straws[j]) ){
					uion(i,j);
				}
			
		/*for(i=1; i<=n; i++)
			printf("parent[%i]:%i\n",i,parent[i]);*/
		
		int a, b;
		if(!first)puts("");
		if(first) first = false;
		while(~scanf("%d %d",&a, &b)){
			if(a==0 && b==0) break;
			if(find(a)!=find(b)) printf("NOT ");
			puts("CONNECTED");
		}
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
