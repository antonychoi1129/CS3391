/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

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
struct P{
	short x, y;
};

bool cmp(P a, P b){
	bool aBig = false;
	if(a.y>b.y) return aBig;
	if(a.x>b.x) return aBig;
	return !aBig;
}

void m(){
	int cases;
	sfd(cases);
	while(cases--){
		int i,j;
		memset(pt,false,sizeof pt);
		int pNum;
		scanf("%d",&pNum);
		
		P cords[pNum];
		
		for(i=0;i<pNum;i++){
			int x, y;
			scanf("%d %d",&x,&y);
			cords[i] = {x,y};
			pt[x][y] = true;
		}
		
		sort(cords,cords+pNum,cmp);
		
		int maxCount=0;
		int maxLength=0;
		
		for(int length=1; length<=30;length++){
			int count = 0;
			
			for(i=0;i<pNum;i++){
				if(cords[i].x+length>30 || cords[i].y+length>30) continue;
				
				if(pt[cords[i].x+length][cords[i].y]
				&& pt[cords[i].x][cords[i].y+length]
				&& pt[cords[i].x+length][cords[i].y+length]
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
