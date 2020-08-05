/*

https://ipsc.ksp.sk/2012/real/solutions/booklet.pdf

Failed to code the faster solution.
*/

#include<iostream>
using namespace std;

int a,b,c,n;	//WhAt Is V? The room number?	Yes.	~_~

int gogogo(int v){
	bool visited[305]={false};
	int gem=0;
	
	int next = v;
	do{
		gem++;
		visited[next] = true;
		
		next = (a*next*next + b*next + c)%n;
	}while( next!=v && !visited[next] );
	
	return gem;
}

int maxGem(){
	int max = 0;
	for(int i=0; i<n; i++){
		int vvv = gogogo(i);
		if(vvv>max) max = vvv;
	}
	
	return max;
}

int main(){
	//ios::sync_with_stdio(false);
	int testcases;
	cin>>testcases;
	
	for(int t=0; t<testcases; t++){
		cin>>a>>b>>c>>n;	//cin eats blank line. :D
		cout<<maxGem()<<endl;
	}
	
	return 0;
}
