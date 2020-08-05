#include <iostream>
#include <list>

using namespace std;

list <int> myList;

list<int>::iterator posn(int p){
	list<int>::iterator itr;
	itr = myList.begin();
	for (int i = 0; i < p; i++)
		itr++;
	return itr;
}

int main(){
	ios::sync_with_stdio(false);
	int N, input, Q, oprt, pos, posj;
	int i;

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> input;
		myList.push_back(input);
	}

	cin >> Q;
	for (i = 0; i < Q; i++) {
		cin >> oprt >> pos;
		switch (oprt) {
		case 1:
			cin >> input;
			myList.insert(posn(pos),input);
			break;
		case 2:
			myList.erase(posn(pos-1));
			break;
		case 3:
			cin >> posj;
			for(int i=pos+1;i<=posj; i++){
				myList.insert(posn(pos-1),*posn(i-1));
				myList.erase(posn(i));
			}
			break;
		case 4:
			cout<<*posn(pos-1)<<endl;
			break;
		}
	}


	return 0;
}
