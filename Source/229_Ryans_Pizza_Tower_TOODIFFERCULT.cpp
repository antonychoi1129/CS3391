/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

//https://stackoverflow.com/questions/13784274/detect-if-one-rect-can-be-put-into-another-rect

#include<stdio.h>
#include<algorithm>
using namespace std;

#define oo (int)1e9
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define abs(n) ((n<0)?(-n):(n))

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
double magic[100000];

struct Shape{
	double area;
	double r1, r2;
}

void m(){
	int n;
	while(~sfd(n)){
		getchar();	//eat \n
		int i,j;
		
		char shape;
		double r;
		double s1, s2;	//retengle's 2 sides
		for(i=0; i<n; i++){
			scanf("%c",&shape);
			if(shape=='C'){
				scanf("%lf",&r);
			}
			else{
				scanf("%lf %lf",&s1, &s2);
			}
			
			getchar(); //eat \n
			
			/*if(shape=='C') printf("Circle radius: %.1f\n",r);
			else printf("Rectangle: %.1f %.1f\n",s1, s2);*/
		}
		
		sort(magic,magic+n);
		int ans = 1;
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
