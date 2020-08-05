#include <iostream>
#include <queue>

using namespace std;

int main(){
	//ios::sync_with_stdio(false);

	int N;			//Number of customers
	int A, O, L;	// Arrival time A, Service time O, Maximum number L
	int orderBeginTime;
	queue<int> customers;

	while (cin >> N) {
		//Clear queue, store the finish time of each customer
		customers = queue<int>();

		for (int i = 0; i < N; i++) {
			cin >> A >> O >> L;
					
			//Pop all finished customers
			while(!customers.empty()){
				if(customers.front()<=A)
					customers.pop();
				else break;
			}
			
			orderBeginTime = A;
			if(!customers.empty() && orderBeginTime<customers.back())
				orderBeginTime = customers.back();
						
			if(L>=(int)customers.size()){
				customers.push(orderBeginTime+O);
			}else orderBeginTime=-1;
		}
		cout << orderBeginTime << endl;
	}

	return 0;
}
