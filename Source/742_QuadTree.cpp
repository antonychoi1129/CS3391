#include <iostream>
#include <math.h>
using namespace std;

bool pic[1024][1024];

int quadTree(int k, int topLeftRow, int topLeftCol){
	//Shortcut
	if (k == 0) return 1;

	int i, j;
	if (k == 1) {
		for (i = topLeftRow; i < topLeftRow + 2; i++)
			for (j = topLeftCol; j < topLeftCol + 2; j++)
				if (pic[i][j] != pic[topLeftRow][topLeftCol])
					return 5;
		return 1;
	}
	//Shortcut ends
	
	bool allSame = true;
	int nodes = 1;
	int n = pow(2, k);

	for (i = topLeftRow; allSame && i < topLeftRow + n; i++) {
		for (j = topLeftCol; j < topLeftCol + n; j++) {
			if (pic[i][j] != pic[topLeftRow][topLeftCol]) {
				allSame = false;
				
				//00 01 10 11 divide into 4 pieces
				for (int row = 0; row<2; row++)
					for (int col = 0; col<2; col++)
						nodes += quadTree(k - 1, topLeftRow + row * n / 2, topLeftCol + col * n / 2);
				
				break;
			}
		}
	}

	return nodes;
}


int main(){
	ios::sync_with_stdio(false);
	int k;      //2^k
	char input;
	int i, j;
	int n;

	while (cin >> k) {
		//Init
		n = pow(2, k);

		//Get pic
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				cin >> input;
				pic[i][j] = input - '0';
			}
		//Output
		cout << quadTree(k, 0, 0) << endl;
	}
	return 0;
}
