#include <iostream>
using namespace std;

int main(){
	int floop[60];
	ios::sync_with_stdio(false);
	
	int i;
	floop[0] = 0;
	floop[1] = 1;
	for(int i=2; i<=60 ;i++)
		floop[i] = (floop[i-1]+floop[i-2])%10;
		
	while(cin>>i)
		cout<<floop[i%60]<<endl;
	
	return 0;
}
