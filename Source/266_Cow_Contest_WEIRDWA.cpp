/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<stack>
#include<vector>
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

vector<int> win[101], lose[101];

int dfs(bool countWin, int to){
	bool ved[101];
	memset(ved,false,sizeof ved);
	
	stack<int> s;
	s.push(to);
	
	int canGo=0;
	while(!s.empty()){
		int cur = s.top();
		s.pop();
		if(ved[cur])continue;
		ved[cur] = true;
		canGo++;
		
		if(countWin){
			for(int i=0; i<win[cur].size(); i++){
				if(!ved[win[cur][i]])
					s.push( win[cur][i] );
			}
		}
		else{
			for(int i=0; i<lose[cur].size(); i++){
				if(!ved[lose[cur][i]])
					s.push( lose[cur][i] );
			}
		}
	}
	return canGo;
}

void m(){
	int n,m;
	while(scanf("%d%d",&n,&m)){
		if(n==0||m==0) break;
		int i,j;
		
		for(i=1;i<=n;i++){
			win[i].clear();
			lose[i].clear();
		}
		
		for(i=0;i<m;i++){
			int winner, loser;
			scanf("%d %d",&winner,&loser);
			win[winner].push_back(loser);
			lose[loser].push_back(winner);
		}
		
		int ans = 0;
		
		for(i=1;i<=n;i++)
			if( dfs(true,i)+dfs(false,i)-1 == n ) ans++;
		
		printf("%d\n",ans);
	}
}

int main(){
	m();
}
