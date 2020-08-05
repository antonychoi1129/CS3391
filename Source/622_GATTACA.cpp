/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

#define MAXL 1000005

char s[MAXL], ans[MAXL];
string ACGT = "ACGT";

int count[MAXL];
int nxt[MAXL][4]={0};

int itr;

int oDepth, oNum;

//DNA base to array index
int b2c(char c){
	if(c=='A') return 0;
	if(c=='C') return 1;
	if(c=='G') return 2;
	if(c=='T') return 3;
}

void insertN(int i, char sfx[]){
	count[i]++;
	if(sfx[0]=='\0') return;
	int &newi = nxt[i][b2c(sfx[0])];
	if(newi==-1) newi = itr++;
	insertN(newi, sfx+1);
}

void wSearch(int i, int d){
	s[d] = 0;
	if(count[i]>1 && d > oDepth){
		oNum = count[i];
		oDepth = d;
		strcpy(ans,s);
	}
	
	for(int j=0; j<4; j++)
		if(nxt[i][j]!=-1){
			s[d] = ACGT[j];
			wSearch( nxt[i][j], d+1 );
		}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		
		//Init
		memset(count,0,sizeof(count));
	    memset(nxt,-1,sizeof(nxt));
		itr = 1;
		
		int i;
		for(i=0; i<strlen(s);i++)
			insertN(0, s+i);
			
		oNum = oDepth = 0;
		wSearch(0, 0);
		
		if(oNum>0)
			cout<<ans<<" "<<oNum<<endl;
		else cout<<"No repetitions found!"<<endl;
	}

	return 0;
}
