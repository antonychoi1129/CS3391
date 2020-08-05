#include <iostream>
#include <bitset>

using namespace std;

int tester(int arr[]){
	arr+=1;
	return arr[0];
}


int main(){
	int array[]={0,1,2,3,4,5,6};
	cout<<tester(array)<<endl;
	return 0;
}
