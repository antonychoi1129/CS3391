#include<iostream>
using namespace std;


int main(){
	//ios::sync_with_stdio(false);
	
	int ways[7689];
	
	for(int i=0; i<7499; i++)
		ways[i] = 1;
	
	int coins[5]={1,5,10,25,50};
	
	for(int i=1; i<5; i++)
		for(int j=1; j<7499; j++){
			if(j>=coins[i])
				ways[j]+=ways[j-coins[i]];
		}
	
	int money;
	while(cin>>money){
		cout<<ways[money]<<endl;
	}
	
	return 0;
}
