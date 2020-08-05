/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<algorithm>
using namespace std;

#define oo (int)1e9;
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sfc(n) scanf("%c",&n)
#define sfl(n) scanf("%lld",&n)

#define pd(n) printf("%d\n",n)

#define DEBUG false

#if DEBUG
#include<iostream>
#endif
#define $(v) {if(DEBUG) cout<<#v<<"\t=\t"<<v<<endl;}

int speed[1000];

void m(){
	int n;
	while(~scanf("%i",&n)){
		int i;
		for(i=0; i<n; i++)
			scanf("%i",&speed[i]);
		if(n==1){
			printf("%i\n",speed[0]);
			continue;
		}

		if(n==2){
			printf("%i\n",max(speed[0],speed[1]));
			continue;
		}
		
		sort(speed,speed+n);

		int time = speed[1];
		for(i=n-2-1;i>=1;i-=2)
			time+= min( speed[i+2]+speed[1]*2 + speed[0],
						speed[i+2]+speed[i+1] + speed[0]*2 );
		if(n&1) time+=speed[0]+speed[2];
		printf("%i\n",time);
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	m();
}
