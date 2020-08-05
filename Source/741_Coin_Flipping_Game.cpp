#include <iostream>
#include <math.h>
using namespace std;

int n, m;
bool coins[100][10];
int rowSum[100], colSum[10];

void flip(int i, int j){
	coins[i][j] = !coins[i][j];
}


void rowFlip(int rowNum){
	for (int i = 0; i < m; i++)
		flip(rowNum, i);
	rowSum[rowNum] = m - rowSum[rowNum];
	for (int i = 0; i < m; i++) {
		if (coins[rowNum][i]) colSum[i]++;
		else colSum[i]--;
	}
}


void colFlip(int colNum){
	for (int i = 0; i < n; i++)
		flip(i, colNum);
	colSum[colNum] = n - colSum[colNum];
	for (int i = 0; i < n; i++) {
		if (coins[i][colNum]) rowSum[i]++;
		else rowSum[i]--;
	}
}

int countOne(){
	int i, count = 0;
	for (i = 0; i < m; i++)
		count += colSum[i];
	return count;
}


int main(){
	char input;
	int i, j;

	int istrt, col2beFlip;
	int bigHead = 0;

	while (cin >> n >> m) {
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

		if (m == 1 || n == 1)
			bigHead = m * n;
		else {
			//Brute
			bigHead = 0;
			for (i = 0; i < pow(2, m) - 1; i++) {
				istrt = i;
				col2beFlip = m - 1;
				while (istrt > 0) {
					if (istrt % 2)
						colFlip(col2beFlip);
					istrt /= 2;
					col2beFlip--;
				}

				for (j = 0; j < n; j++)
					if (rowSum[j] < m - rowSum[j]) rowFlip(j);

				if (countOne() > bigHead) bigHead = countOne();
				if (bigHead >= m * n - 1) break;
				
				//Go back!!!!
				istrt = i;
				col2beFlip = m - 1;
				while (istrt > 0) {
					if (istrt % 2)
						colFlip(col2beFlip);
					istrt /= 2;
					col2beFlip--;
				}
			}
		}

		cout << bigHead << endl;
	}
	return 0;
}
