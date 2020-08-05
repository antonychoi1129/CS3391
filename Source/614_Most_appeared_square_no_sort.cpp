/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>

#define oo (int)1e9;
#define r0 1e-9

#define $min(a,b) a<b?a:b
#define $max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sfc(n) scanf("%c",&n)
#define sfl(n) scanf("%lld",&n)

#define pd(n) printf("%d\n",n)


// #define DEBUG true
#if DEBUG
#include<iostream>	//Memory Monster
#endif
#define $(v) if(DEBUG) cout<<#v<<"\t=\t"<<v<<endl

bool pt[31][31];	//x y

void m(){
	int cases;
	sfd(cases);
	while(cases--){
		int i,j;
		memset(pt,false,sizeof pt);
		int pNum;
		scanf("%d",&pNum);
		
		int sx, sy, bx, by;
		sx = sy = 31;
		bx = by = -1;
		for(i=0;i<pNum;i++){
			int x, y;
			scanf("%d %d",&x,&y);
			pt[x][y] = true;
			if(x<sx)
				sx = x;
			else if(x>bx)
				bx = x;
			if(y<sy)
				sy = y;
			else if(y>by)
				by = y;
		
		}
		
		int maxCount=0;
		int maxLength=0;
		
		for(int length=1; length<=30;length++){
			int count = 0;
			
			int i,j;
			for(i=sx;i<=bx;i++)
				for(j=sy;j<=by;j++){
					if (!pt[i][j]) continue;
					
					if(pt[i+length][j]
					&& pt[i][j+length]
					&& pt[i+length][j+length]
					) count++;
				}
			if(count>=maxCount){
				maxLength = length;
				maxCount = count;
			}
		}
		if(maxCount==0)
			puts("No squares among the points.");
		else
			printf("LENGTH = %i, COUNT = %i\n",maxLength,maxCount);
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
