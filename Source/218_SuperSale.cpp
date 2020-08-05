#include<iostream>
#include<algorithm>
using namespace std;

struct obj{
	int price;
	int weight;
	
	obj(int p, int w){
		price = p;
		weight = w;
	}
	
	obj(){}
};

int main(){
	ios::sync_with_stdio(false);
	int testcases;
	
	cin>>testcases;
	
	for(int t=0; t<testcases; t++){
		int objNum;	// [1,1000]
		cin>>objNum;
		
		obj objs[objNum];
		int bags [33] = {0};
		for(int n=0; n<objNum; n++){
			int price,weight;
			cin>>price>>weight;
			objs[n] = obj(price,weight);
			
			//Knapsack...
			for(int j=30; j>=weight; j--)
				if(bags[j]< bags[j-weight]+price)
					bags[j] = bags[j-weight]+price;
		}
		
		int peopleNum;
		cin>>peopleNum;
				
		int output = 0;
		for(int p=0; p<peopleNum; p++){
			int mw;
			cin>>mw;
			output += bags[mw];
		}
		
		cout<<output<<endl;
	}
	
	return 0;
}
