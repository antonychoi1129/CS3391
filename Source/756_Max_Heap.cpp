#include <iostream>
using namespace std;

void swap(int &a, int &b){
	a = a + b;
	b = a - b;
	a = a - b;
}


int main(){
	//Dont read, bad code
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int myHeap[100000];
	while (cin >> n) {
		int sumOfAllNum = 0;
		int heapSize = 0;
		int newNum, newNumPos;

		char oprt;
		for (int line = 0; line < n; line++) {
			cin >> oprt;
			switch (oprt) {
			case 'a':
				cin >> newNum;
				sumOfAllNum += newNum;

				//Insert
				newNumPos = heapSize;
				myHeap[newNumPos] = newNum;

				while (newNumPos > 0 && myHeap[(newNumPos - 1) / 2] < myHeap[newNumPos]) {
					swap(myHeap[(newNumPos - 1) / 2], myHeap[newNumPos]);
					newNumPos = (newNumPos - 1) / 2;
				}
				heapSize++;
				break;

			case 'p':
				sumOfAllNum -= myHeap[0];
				//Pop
				heapSize--;
				myHeap[0] = myHeap[heapSize];
				newNumPos = 0;
				while (true) {
					int lChild = newNumPos * 2 + 1;
					int rChild = newNumPos * 2 + 2;

					if (lChild >= heapSize) lChild = newNumPos;
					if (rChild >= heapSize) rChild = newNumPos;

					if (myHeap[newNumPos] >= myHeap[lChild])
						if (myHeap[newNumPos] >= myHeap[rChild])
							break;
							
					if (myHeap[lChild] > myHeap[rChild]) {
						swap( myHeap[newNumPos], myHeap[lChild] );
						newNumPos = lChild;
					}else {
						swap( myHeap[newNumPos], myHeap[rChild] );
						newNumPos = rChild;
					}
				}
				break;
			case 'r':
				cout << sumOfAllNum << endl;
				break;
			}
		}
	}

	return 0;
}
