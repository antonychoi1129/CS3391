#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	//ios::sync_with_stdio(false);

	int testcases;
	cin >> testcases;

	int peopleNum;
	for(int t=0; t<testcases; t++){
		cin >> peopleNum;
		float grade[peopleNum];
		float avg=0;
		for(int p=0; p< peopleNum; p++){
			cin>>grade[p];
			avg+=grade[p];
		}
		avg/=peopleNum;
		int ans=0;
		for(int p=0; p<peopleNum; p++)
			if(grade[p]>avg) ans++;

		cout<<setprecision(3)<<fixed
				<<(float)ans/peopleNum*100<<"%"<<endl;
	}

	return 0;
}
