//Need array implementation
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct weirdNode{
	bool hasData;
	int freq;
	weirdNode *lChild, *rChild;
	
	weirdNode(int f, bool h){
		freq = f;
		hasData = h;
		lChild = rChild = NULL;
	}
};

int genAns(weirdNode*top, int height){
	if(top->hasData) return top->freq*height;
	
	height+=1;
	int ans = genAns(top->lChild,height) + genAns(top->rChild,height);
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int numOfSymbol;
	int input=0;
	while(cin >> numOfSymbol){
		
		//Shortcut
		if( (numOfSymbol&(numOfSymbol-1) ) == 0){
			int ans=0;
			for(int i=0;i<numOfSymbol;i++){
				cin>>input;
				ans+=input;
			}
			cout<<ans * log(numOfSymbol)/log(2) <<endl;
			continue;
		}
		
		vector<weirdNode*>symbols = vector<weirdNode*>();
		for(int i=0;i<numOfSymbol;i++){
			cin>>input;
			symbols.push_back(new weirdNode(input,true));
		}
		
		//For smart test cases
		/*if (numOfSymbol<=1){
			cout<<input<<endl;
			continue;
		}*/
		
		struct{
			bool operator()(weirdNode* a, weirdNode* b){ return a->freq > b->freq; };
		} minHeapCmp;
		
		make_heap(symbols.begin(),symbols.end(),minHeapCmp);
		weirdNode *tempLeft, *tempRight, *top;
		while(symbols.size()!=1){
			tempLeft = symbols.front();
			pop_heap(symbols.begin(),symbols.end(),minHeapCmp);
			symbols.pop_back();
			
			tempRight = symbols.front();
			pop_heap(symbols.begin(),symbols.end(),minHeapCmp);
			symbols.pop_back();
			
			top = new weirdNode(tempLeft->freq+tempRight->freq, false);
			top->lChild = tempLeft;
			top->rChild = tempRight;
			
			symbols.push_back(top);
			push_heap(symbols.begin(),symbols.end(),minHeapCmp);
		}
		cout<<genAns(top,0)<<endl;	
	};
	
	
	return 0;
}
