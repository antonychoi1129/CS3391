#include <iostream>
using namespace std;

int cQueue[100000];	//MyQueue
int start, tail;

bool cQueueEmpty(){
	return (start == tail);
}

void cQueuePop(){
	start++;
}

void cQueuePush(int value){
	cQueue[tail] = value;
	tail++;
}

int main(){
	ios::sync_with_stdio(false);

	int N;			//Number of customers
	int A, O, L;	// Arrival time A, Service time O, Maximum number L
	int orderBeginTime;

	while (cin >> N) {
		start = tail = 0;

		for (int i = 0; i < N; i++) {
			cin >> A >> O >> L;
					
			//Pop all finished customers
			while(!cQueueEmpty() && cQueue[start]<=A)
					cQueuePop();
			
			orderBeginTime = A;
			if(!cQueueEmpty() && orderBeginTime<cQueue[tail-1])
				orderBeginTime = cQueue[tail-1];
						
			if(L>=(tail-start)){
				cQueuePush(orderBeginTime+O);
			}else orderBeginTime=-1;
		}
		cout << orderBeginTime << endl;
	}

	return 0;
}
