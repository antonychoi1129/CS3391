/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
using namespace std;

#define oo (int)1e9;
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sflf(n) scanf("%lf",&n)
#define sfc(n) scanf("%c",&n)
#define sfl(n) scanf("%lld",&n)

#define pd(n) printf("%d\n",n)

// #define DEBUG true
#ifdef DEBUG
	#include<iostream>	//Memory Monster
	#define $(v) cout<<#v<<"\t=\t"<<v<<endl
#else
	#define $(v) 
#endif
//--------------------------------------------------------------------------
#include<math.h>
#define PI acos(0)*2

void m(){
	double s;	//side length
	while(~sflf(s)){
		double square = s*s;
		
		//The rest (grid)
		double theRest = 4*(square - (square*PI/6) - (square*sqrt(3)/4));
		//dotted regions
		double dotted = 4*(square - (square*PI/4) - theRest/2);
		//striped region
		double striped = square - dotted - theRest;
		printf("%.3f %.3f %.3f\n",striped,dotted,theRest);
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
