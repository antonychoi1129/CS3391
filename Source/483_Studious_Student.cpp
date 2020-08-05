/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<iostream>
#include<string>
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

string words[50];

bool myCmp( const string a, const string b ){
	return a+b < b+a;
}

void m(){
	int n;
	cin>>n;
	
	while(n--){
		int m;
		
		cin>>m;
		
		int i;
		for(i=0; i<m; i++)
			cin>>words[i];
			
		sort(words,words+m,myCmp);
		
		for(i=0; i<m; i++)
			cout<<words[i];
		cout<<endl;
	}
}

int main(){
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
