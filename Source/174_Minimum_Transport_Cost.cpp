/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int const INF = 1e9;

int main(){
	//ios::sync_with_stdio(false);
	int ds;
	cin>>ds;
	cin.ignore();	//eat \n
	string fstLine;
	getline(cin,fstLine);	//eat empty line
	
	while(ds--){
		getline(cin,fstLine);
		
		int n=1;
		for(int i=0; fstLine[i]!='\0'; i++)
			if(fstLine[i]==' ')n++;
			
		stringstream ss;
		ss<<fstLine;
		int costs[n][n], cost, itr=0;
		while(ss>>cost) costs[0][itr++] = cost;
		
		for(int i=1; i<n; i++)
			for(int j=0; j<n; j++)
				cin>>costs[i][j];
				
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(costs[i][j] == -1) costs[i][j]=INF;
		
		int taxs[n];
		for(int i=0; i<n; i++)
			cin>>taxs[i];
		cin.ignore();	//eat \n
		
		//Crazy shit input.
		
		//Gogogo
		int gogogo[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				gogogo[i][j] = j;
		
		//FW
		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++){
					if(costs[i][j]>costs[i][k]+costs[k][j]+taxs[k]){
						costs[i][j] = costs[i][k]+costs[k][j]+taxs[k];
						gogogo[i][j] = gogogo[i][k];
					}
				}
		
		string line;
		int from, to;
		int more=0;
		while( getline(cin,line) ){
			if(line=="") break;
			if(more++) cout<<endl;
			stringstream ss2;
			ss2<<line;
			ss2>>from>>to;
			cout<<"From "<<from<<" to "<<to<<" :"<<endl;
			
			cout<<"Path: "<<from;
			
			int start = from -1;
			int end = to - 1;
			while(start!=end){
				cout<<"-->"<<gogogo[start][end]+1;
				start = gogogo[start][end];
			}
			cout<<endl;
			cout<<"Total cost : "<<costs[from-1][to-1]<<endl;
		}
		if(ds>0) cout<<endl;	//Print a blank line between datasets
	}
	
	return 0;
}
/*
3

0 3 22 -1 4
3 0 5 -1 -1
22 5 0 9 20
-1 -1 9 0 4
4 -1 20 4 0
5 17 8 3 1
1 3
3 5
2 4

0 3 22 -1 4
3 0 5 -1 -1
22 5 0 9 20
-1 -1 9 0 4
4 -1 20 4 0
5 17 8 3 1
1 3
3 5
2 4

0 3 22 -1 4
3 0 5 -1 -1
22 5 0 9 20
-1 -1 9 0 4
4 -1 20 4 0
5 17 8 3 1
1 3
3 5
2 4

*/
