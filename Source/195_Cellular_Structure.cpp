#include<iostream>
#include <string>
using namespace std;

int tellme(string o){
	//A		|	SIMPLE		|	for simple stage
	if(o=="A") return 0;
	
	int ol = o.length();

	//OAB	|	FULLY-GROWN	|	for fully-grown stage
	if(o[ol-2]=='A' && o[ol-1]=='B'){
		//remove last 2 character x(
		o.pop_back();
		o.pop_back();
		
		if(tellme(o)!=-666) return 1;
	}
	
	//BOA	|	MUTAGENIC	|	for mutagenic stage
	else if(o[0]=='B'&&o[ol-1]=='A'){
		o=o.substr(1, ol-2);
		if(tellme(o)!=-666) return 2;
	}
	
	//MUTANT		any other (in case of mutated aliens) 				;)
	return -666;
}

int main(){
	ios::sync_with_stdio(false);
	int testcases;
	cin>>testcases;
	
	int ans;
	string ogns;
	for(int i=0; i<testcases; i++){
		cin>>ogns;
		ans = tellme(ogns);
		if(ans==0) cout<<"SIMPLE"<<endl;
		else if(ans==1) cout<<"FULLY-GROWN"<<endl;
		else if(ans==2) cout<<"MUTAGENIC"<<endl;
		else cout<<"MUTANT"<<endl;
	}
	
	return 0;
}
