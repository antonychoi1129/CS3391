/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
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

bool win[101][101];
void fwa(int n){
	int i,j,k;	//i = start; j = target; k = middle
	for(k=1; k<=n; k++)
		for(i=1; i<=n; i++)
			for(j=1;j<=n;j++)
					win[i][j] |= win[i][k] & win[k][j];
}

void m(){
	int n,m;
	while(scanf("%d %d",&n,&m)){
		if(n==0||m==0) continue;
		memset(win,false,sizeof win);
		int i,j;
		for(i=0;i<m;i++){
			int winner, loser;
			scanf("%d %d",&winner,&loser);
			win[winner][loser] = true;
		}
		
		fwa(n);
		
		int ans = 0;
		for(i=1;i<=n;i++){
			int count =0;
			for(j=1;j<=n;j++)
				count+=win[i][j]+win[j][i];
			if(count==n-1) ans++;
		}
		
		printf("%d\n",ans);
	}
}

int main(){
	m();
}
