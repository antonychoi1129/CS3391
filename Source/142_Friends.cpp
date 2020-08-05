#include <iostream>
#include <vector>
using namespace std;

struct Town {
int population;
vector<int> * rship;
public:
Town(int p){
	population = p;
	rship = new vector<int>[p + 1];
};

~Town(){
	for(int i=0; i<population+1; i++)
		rship[i].clear();
}

void beFd(int a, int b){
	rship[a].push_back(b);
	rship[b].push_back(a);
}

void getGrpMemberNum(int citizen, bool * visited, int * count){
	visited[citizen] = true;
	(*count)++;

	vector<int>::iterator it;
	for (it = rship[citizen].begin(); it != rship[citizen].end(); ++it)
		if (!visited[*it])
			getGrpMemberNum(*it, visited, count);
}


int getLargest(){
	int largest = 0, gnum;
	bool visited[population];
	for (int i = 0; i <= population; i++)
		visited[i] = false;

	for (int i = 1; i <= population; i++) {
		if (visited[i]) continue;
		gnum = 0;
		getGrpMemberNum(i, visited, &gnum);
		if (gnum > largest) {
			largest = gnum;
			if (largest >= population / 2 + 1) break;
		}
	}
	return largest;
}
};

int main(){
	ios::sync_with_stdio(false);
	int cases;
	int N, M;
	int A, B;

	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> N >> M;
		Town town = Town(N);


		for (int i = 0; i < M; i++) {
			cin >> A >> B;
			town.beFd(A, B);
		}
		cout << town.getLargest() << endl;
	}
	return 0;
}
