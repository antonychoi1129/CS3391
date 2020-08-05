//Horrible code

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

double dist(int ax, int ay, int bx, int by){
	return sqrt( pow(ax-bx,2) + pow(ay-by,2) );
}

int main(){
	//ios::sync_with_stdio(false);
	int i = 1, n;
	while(cin>>n){
		if(n==0) break;
		cout<<"Scenario #"<<i++<<endl;
		
		double dt[269][269];
		int x [269], y[269];
		for(int i=0; i<n; i++)
			cin>>x[i]>>y[i];
			
		for(int i=0; i<n; i++)
			for(int j=0; j<i; j++){
				dt[i][j] = dt[j][i] = dist(x[i],y[i],x[j],y[j]);
			}
				
		//Floyd mutated
		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++){
					double m = max( dt[i][k], dt[k][j] );	//minimax
					if(dt[i][j] > m)
						dt[i][j] = m;
				}
					
		double frog_distance = dt[0][1];	//boy stone -> girl stone
											//paths with shortest jumps

		cout<<"Frog Distance = "<<fixed<<setprecision(3)<<frog_distance<<endl<<endl;
	}
	return 0;
}
