#include <iostream>
#include <math.h>
using namespace std;

int nodeNum;

struct black2x2 {
	bool upLeft, upRight;
	bool btLeft, btRight;

	black2x2(bool black){
		//Black or not black?
		upLeft = upRight = btLeft = btRight = black;
	}
};

struct TreeNode {
	char color;
	TreeNode *uLChild, *uRChild;
	TreeNode *bLChild, *bRChild;

	TreeNode(char c){
		color = c;
		uLChild = uRChild = bLChild = bRChild = NULL;
	}
};

struct QuadTree {
	TreeNode* root;
	QuadTree(bool * pic, int size){
		root = treeBuilder(pic, size, 0, 0);
	}


	TreeNode* treeBuilder(bool * pic, int size, int tLRow, int tLCol){
		
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	int k, n;
	bool pic[1024][1024];
	char input;
	int m;
	int row, col;
	int i, j;

	cin >> T;
	for (int cases = 0; cases < T; cases++) {
		cin >> k;
		n = pow(2, k);

		nodeNum = 1;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				cin >> input;
				pic[i][j] = input - '0';
			}
		QuadTree tree(*pic, n);
		cin >> m;
		for (i = 0; i < m; i++) {
			cin >> row >> col;
			cout << nodeNum << endl;
		}
	}
	return 0;
}
