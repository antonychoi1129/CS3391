#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> list;
	ios::sync_with_stdio(false);
	int N, input, Q, oprt, pos, posj;
	int i;
	
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> input;
		list.push_back(input);
	}
	
	cin >> Q;
	for (i = 0; i < Q; i++) {
		cin >> oprt >> pos;
		switch (oprt) {
		case 1:
			cin >> input;
			list.insert(list.begin()+pos,input);
			break;
		case 2:
			list.erase(list.begin()+pos-1);
			break;
		case 3:
			cin >> posj;
			reverse(list.begin()+pos-1,list.begin()+posj);
			break;
		case 4:
		cout<<*(list.begin()+pos-1)<<endl;
			break;
		}
	}
	return 0;
}
