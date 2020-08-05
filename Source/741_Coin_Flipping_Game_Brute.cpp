#include <iostream>
using namespace std;

int n, m;
int coins[100][10] = {0};
int rowSum[100], colSum[10], oneSum;

void flip(int i, int j){
	coins[i][j]++;
	coins[i][j] %= 2;
}


void rowFlip(int rowNum){
	for (int i = 0; i < m; i++)
		flip(rowNum, i);
}


void colFlip(int colNum){
	for (int i = 0; i < n; i++)
		flip(i, colNum);
}


void printCoins(){
	int i, j, count = 0;
	cout<<endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << coins[i][j];
			count += coins[i][j];
		}
		cout << " |" << rowSum[i];
		cout << endl;
	}
	for (j = 0; j < m; j++)
		cout << colSum[j];
	cout << endl << "Count: " << count << endl;
}


int countOne(){
	int i, j, count = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			count += coins[i][j];
	return count;
}


int main(){
	char input;
	int max;
	int i, j;

	while (cin >> n >> m) {
		//Init
		for (i = 0; i < n; i++) rowSum[i] = 0;
		for (i = 0; i < m; i++) colSum[i] = 0;
		max = 0;
		
		//Get coins
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++) {
				cin >> input;
				coins[i][j] = input - '0';
				rowSum[i] += coins[i][j];
				colSum[j] += coins[i][j];
				oneSum += coins[i][j];
			}
		printCoins();
		//Destroy
			
	}
	return 0;
}
