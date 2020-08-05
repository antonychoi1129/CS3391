/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<iostream>
#include<sstream>
#include<set>
#include<string>

#define strsm stringstream
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	set<string> dict;
	string s,word;
	
	int i;
	while(cin>>s){
		for(i=0;i<s.length();i++)
			if(isalpha(s[i]))
				s[i] = tolower( s[i] );
			else s[i] = ' ';
			
		strsm ss(s);
		while(ss>>word)
			dict.insert(word);
	}
	
	set<string>::iterator it;
	for(it=dict.begin();it!=dict.end();it++)
		puts(it->c_str());

	return 0;
}
