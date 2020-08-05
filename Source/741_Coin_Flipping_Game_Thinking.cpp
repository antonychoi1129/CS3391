#include <iostream>
using namespace std;
int n, m;
int rowSum[100], colSum[10];
int coins[100][10];

void flip(int i, int j){
	coins[i][j]++;
	coins[i][j] %= 2;
}


void rowFlip(int rowNum){
	for (int i = 0; i < m; i++)
		flip(rowNum, i);
	rowSum[rowNum] = m - rowSum[rowNum];
	for (int i = 0; i < m; i++) {
		if (coins[rowNum][i] == 1) colSum[i]++;
		else colSum[i]--;
	}
}


void colFlip(int colNum){
	for (int i = 0; i < n; i++)
		flip(i, colNum);
	colSum[colNum] = n - colSum[colNum];
	for (int i = 0; i < n; i++) {
		if (coins[i][colNum] == 1) rowSum[i]++;
		else rowSum[i]--;
	}
}


void printCoins(){
	int i, j, count = 0;
	cout << endl;
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
	int i, count = 0;
	for (i = 0; i < n; i++)
		count+=rowSum[i];
	return count;
}


int main(){

	int i, j;
	char input;
	int num;

	while (1) {
		cin >> n >> m;
		//Init
		for (i = 0; i < n; i++)
			rowSum[i] = 0;
		for (i = 0; i < m; i++)
			colSum[i] = 0;

		//Get coins
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				cin >> input;
				coins[i][j] = input - '0';
				rowSum[i] += coins[i][j];
				colSum[j] += coins[i][j];
			}
		}
		printCoins();
		while (1) {
			cin >> input >> num;
			if (input == 'r')
				rowFlip(num);
			else if (input == 'c')
				colFlip(num);
			else break;
			printCoins();
		}
	}
	return 0;
}
