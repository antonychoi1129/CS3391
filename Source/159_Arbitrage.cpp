/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<map>	//vector included
#include<string>
using namespace std;

#define oo (int)1e9;
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sfd_sn(n) scanf("%d\n",&n)	//slash n
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
//----------------------------------------------------------------------
#define MAXN 31
double money[MAXN][MAXN];

//https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm
void fwa(int n){
	int i,j,k;	//i = start; j = target; k = middle
	for(k=0; k<n; k++)
		for(i=0; i<n; i++)
			for(j=0;j<n;j++){
				if(money[i][j]<money[i][k]*money[k][j])
					money[i][j] = money[i][k]*money[k][j];
			}
}

#define CLEN 50
char cName[CLEN][31];	//1<=n<=30

void m(){
	int cNum;	//currencies Number
	int lNum;	//table line Number
	map<string, int> cMap;
	map<string, int>::iterator it;
	
	int ccc=1;
	
	while(~sfd(cNum)){
		if(cNum==0) break;
		getchar();	//	eat \n for gets
		int i,j;
		
		string name[100];
		for(i=0; i<cNum;i++){
			gets(cName[i]);
			//cMap.insert( pair<string,int>(cName[i],i) );
			cMap[cName[i]] = i;
		}
		sfd(lNum);
		
		//Init
		for(i=0;i<cNum;i++)
			for(j=0;i<cNum;i++)
				money[i][j] = 0;
		
		for(i=0;i<cNum;i++)
			money[i][i] = 1;
		
		for(i=0;i<lNum;i++){
			char src[CLEN], dest[CLEN];
			double exRate;
			scanf("%s %lf %s",src,&exRate,dest);
			// int isrc = cMap.find(src)->second;
			// int ides = cMap.find(dest)->second;
			int isrc = cMap[src];
			int ides = cMap[dest];
			money[isrc][ides] = exRate;
		}
		
		fwa(cNum);
		bool yes = false;
		
		for(i=0;i<cNum;i++){
			$(money[i][i]);
			if(money[i][i]>1){
				yes = true;
				break;
			}
		}
		
		printf("Case %i: ",ccc++);
		if(yes) puts("Yes");
		else puts("No");
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
