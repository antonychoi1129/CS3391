/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
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

#define MAXN 1000
int heat[MAXN][MAXN];

//https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm
void fwa(int n){
	int i,j,k;	//i = start; j = target; k = middle
	for(k=0; k<n; k++)
		for(i=0; i<n; i++)
			for(j=0;j<n;j++)
				if(heat[i][j]>heat[i][k]+heat[k][j])
					heat[i][j] = heat[i][k]+heat[k][j];
}

void m(){
	int n;
	while(~sfd(n)){
		int i,j;
		for(i=0; i<n; i++)
			for(j=0;j<n;j++)
				sfd( heat[i][j] );
				
		fwa(n);
		
		for(i=0; i<n; i++)
			sort(heat[i],heat[i]+n);
		
		int median = n/2;
		
		if(n&1){	//odd
			for(i=0; i<n; i++)
				pd( heat[i][median] );
		}
		else{	//even
			for(i=0; i<n; i++){
				int ansx2 = (heat[i][median] + heat[i][median-1]);
				if(ansx2&1)
					printf("%.1f\n", ansx2/2+0.5 );
				else
					pd(ansx2/2);
			}
		}
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
