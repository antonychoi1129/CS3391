#include<iostream>
using namespace std;

int a,b,c,n;	//WhAt Is V? The room number?	Yes.	~_~
int gems[305];

int gogogo(int v){
	if(gems[v]==1){
		int nextChamber = (a*v*v + b*v + c)%n;
		if(nextChamber!=v && gems[nextChamber] == 0)
			gems[v] = 1 + gogogo(nextChamber);
	}
	
	return gems[v];
}

int maxGem(){
	int max = 0;
	for(int i=0; i<n; i++)
		gems[i]=1;
	
	for(int i=0; i<n; i++){
		if(gems[i]==1)
			gogogo(i);
		if(gems[i]>max) max = gems[i];
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
