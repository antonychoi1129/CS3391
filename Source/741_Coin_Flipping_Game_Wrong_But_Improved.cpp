#include <iostream>
using namespace std;

int n, m;
int coins[100][10] = {0};

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
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << coins[i][j];
			count += coins[i][j];
		}
		cout << endl;
	}
	cout << "Count: " << count << endl;
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
	int rowMin1, colMin1, row1, col1;
	bool same;
	int goodRow[10], goodCol[10];

	int i, j;

	while (cin >> n >> m) {
		//Get coins
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++) {
				cin >> input;
				coins[i][j] = input - '0';
			}
		printCoins();

		rowMin1 = m;
		for (i = 0; i < n; i++) {
			row1 = 0;
			for (j = 0; j < m; j++)
				row1 += coins[i][j];
			if (row1 < rowMin1) {
				rowMin1 = row1;
				for (int j2 = 0; j2 < m; j2++)
					goodRow[j2] = coins[i][j2];
			}
		}

		colMin1 = n;
		for (i = 0; i < m; i++) {
			col1 = 0;
			for (j = 0; j < n; j++)
				col1 += coins[j][i];
			if (col1 < colMin1) {
				colMin1 = col1;
				for (int i2 = 0; i2 < n; i2++)
					goodCol[i2] = coins[j][i2];
			}
		}

		if (rowMin1 <= colMin1) {
			for (i = 0; i < n; i++) {
				same = true;
				for (j = 0; same && j < m; j++) {
					if (coins[i][j] != goodRow[j]) same = false;
				}
				if (same)
					rowFlip(i);
			}
			
			for (i = 0; i < m; i++) {
				col1 = 0;
				for (j = 0; j < n; j++)
					col1 += coins[j][i];
				if (col1 < m / 2.0)
					colFlip(i);
			}
			
			
		}else {
			for (i = 0; i < m; i++) {
				same = true;
				for (j = 0; same && j < n; j++) {
					if (coins[j][i] != goodCol[i]) same = false;
				}
				if (same)
					colFlip(i);
			}
			for (i = 0; i < n; i++) {
				row1 = 0;
				for (j = 0; j < m; j++)
					row1 += coins[i][j];
				if (row1 < n / 2.0)
					rowFlip(i);
			}
		}


		printCoins();
	}
	return 0;
}
