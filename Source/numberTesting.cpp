#include<iostream>
#include<cmath>
using namespace std;

#define POWERFUL 5
#define STUPIDRADIX (2<<POWERFUL)
#define MASK (STUPIDRADIX-1)

int main(){
	//ios::sync_with_stdio(false);
	cout<<"Your number:"<<MASK<<endl;
	printf("%i",POWERFUL);
	
	return 0;
}
