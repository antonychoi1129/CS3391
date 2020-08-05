/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
	//ios::sync_with_stdio(false);
	string line;
	stringstream ss1;
	long double num, ans=0;
	
	getline(cin,line);
	ss1<<line;
	while(ss1>>num)
		ans+=num;
	cout<<fixed<<setprecision(4)<<ans<<endl;
	
	while(getline(cin,line)){
		stringstream ss;
		ans=0;
		ss<<line;
		while(ss>>num)
			ans+=num;
		cout<<endl<<fixed<<setprecision(4)<<ans<<endl;
	}
	
	return 0;
}
