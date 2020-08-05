/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
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

// #define DEBUG true
#ifdef DEBUG
	#define $(v) cout<<#v<<"\t=\t"<<v<<endl
#else
	#define $(v) 
#endif
//--------------------------------------------------------------------------

bool myCmp(int a, int b) 
{ 
    return a > b; 
} 

bool ved[21];
int stick[21];
int sNum;
int sideLen;
bool found;
bool dfs(int pos,int len, int sides){
	if(found) return true;
	if(len==sideLen){
		sides++;
		len = 0;
		pos = 0;
	}
	if(sides==3) {
		found = true;
		return true;
	}
	
	for(int i=pos;i<sNum;i++){
		if(ved[i])continue;
		if(len+stick[i]<=sideLen){
			ved[i] = true;
			if(dfs(i+1, len+stick[i], sides))return true;
		}
		//failed to form square with this path, drop this stick
		ved[i] = false;
	}
	return false;
}

void m(){
	int cases;
	sfd(cases);
	for(int ccc=1; ccc<=cases; ccc++){
		sfd(sNum);
		
		int i;
		int sum=0;
		for(i=0;i<sNum;i++){
			sfd(stick[i]);
			sum+=stick[i];
		}
		
		//Decending order
		sort(stick,stick+sNum,myCmp);
		for(i=0;i<sNum;i++){
			$(stick[i]);
		}
		
		sideLen = sum/4;
		bool yes = (sum%4==0);
		if(yes) {
			for(i=0;i<sNum;i++){
				if(stick[i]>sideLen){
					yes = false;
					break;
				}
			}
		}
		if(yes){
			memset(ved,false,sizeof ved);
			found = false;
			yes = dfs(0,0,0);
		}
		
		printf("Case #%i: ",ccc);
		if(yes)puts("yes");
		else puts("no");
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
