/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<iostream>
#include<bitset>
#include<string>
using namespace std;

string trim(string s){
	return s.erase(0, s.find_first_not_of('0'));
}

int main(){
	ios::sync_with_stdio(false);
	long long input;
	
	while(cin>>input){
		if(input<=1) cout<<input<<endl;
		else{
			bitset<65> output(input);
			cout<<trim(output.to_string())<<endl;
		}
	}
	
	return 0;
}
