/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<iostream>
#include<sstream>
#include<string>
using namespace std;

#define oo (int)1e9
#define r0 1e-9

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

#define ll long long
#define ull unsigned long long

#define sfd(n) scanf("%d",&n)
#define sfd_sn(n) scanf("%d\n",&n)
#define sfs(n) scanf("%s\n",n)
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

stringstream ss;
void letsdorecursion(){
	string s;
	if(ss>>s) letsdorecursion();
	else return;
	cout<<" "<<s;
}

void m(){
	int n;
	cin>>n;
	cin.ignore();
	for(int i=1; i<=n;i++){
		ss.clear();
		string line;
		getline(cin,line);
		ss<<line;
		cout<<"Case #"<<i<<":";
		letsdorecursion();
		cout<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	#if DEBUG
	    puts("DEBUGGING");
	#endif
	
	m();
}
