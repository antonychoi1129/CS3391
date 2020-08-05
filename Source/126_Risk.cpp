#include<iostream>
#include<iomanip>
using namespace std;

const int BIG = 30;//4294967294;
int wMap[20][20];

//https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm
void fwa(){
	int i,j,k;	//i = start; j = target; k = middle
	for(k=0; k<20; k++)
		for(i=0; i<20; i++)
			for(j=0;j<20;j++){
				if(wMap[i][j]>wMap[i][k]+wMap[k][j])
					wMap[i][j] = wMap[i][k]+wMap[k][j];
			}
}

int main(){
	//ios::sync_with_stdio(false);
	
	int testNum = 1;
	int cuntries, c;	//;)
	int npairs;
	int c1, c2;
	
	while(cin>>cuntries){
		cout<<"Test Set #"<<testNum<<endl;
		
		for(int i=0; i<20; i++)
			for(int j=0; j<20; j++)
				wMap[i][j] = BIG;
		
		
		int t=0;
		for(int i=0; i<cuntries; i++){
			cin>>c;
			wMap[t][c-1] = wMap[c-1][t] = 1;
		}
		
		for(t=1;t<19;t++){
			cin>>cuntries;
			for(int i=0; i<cuntries; i++){
				cin>>c;
				wMap[t][c-1] = wMap[c-1][t] = 1;
			}
		}
		
		fwa();
		
		cin>>npairs;
		for(int n=0; n<npairs; n++){
			cin>>c1>>c2;
			cout<<setw(2)<<c1<<" to "<<setw(2)<<c2<<": "<<wMap[c1-1][c2-1]<<endl;
		}
		testNum++;
		cout<<endl;
	}
	
	return 0;
}
