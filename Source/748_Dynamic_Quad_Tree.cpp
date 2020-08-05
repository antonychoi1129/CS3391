#include <iostream>
#include <math.h>
using namespace std;

int nodeNum;

//Pixel position
struct Point {
	int row, col;
	Point(int r, int c){
		row = r;
		col = c;
	}


	Point(){row = col = 0;}
};

class QuadTree {
Point topLeft;
Point btmRight;
char color;

//Children
QuadTree *tLTree;
QuadTree *tRTree;
QuadTree *bLTree;
QuadTree *bRTree;

public:
QuadTree(Point tL, Point bR, char c){
	tLTree = tRTree = bLTree = bRTree = NULL;
	topLeft = tL;
	btmRight = bR;
	color = c;
	/*cout << "TopLeft:(" << topLeft.row << "," << topLeft.col << ") BottomRight:(" << btmRight.row << "," << btmRight.col <<
	   ") Node Color:" << node->color << endl;*/
}


~QuadTree(){
	if (color == 'G') {
		delete tLTree;
		delete tRTree;
		delete bLTree;
		delete bRTree;
	}
}


void flip(Point pos){
	//cout<<"TopLeft:("<<topLeft.row<<","<<topLeft.col<<") BottomRight:("<<btmRight.row<<","<<btmRight.col<<")"<<endl;
	//cout<<node->color<<endl;
	if (color != 'G') {
		split4();
		color = 'G';
		nodeNum += 4;
	}

	if (isSize2x2()) {
		if (tLTree->contains(pos)) tLTree->leafPixelFlip();
		else if (tRTree->contains(pos)) tRTree->leafPixelFlip();
		else if (bLTree->contains(pos)) bLTree->leafPixelFlip();
		else bRTree->leafPixelFlip();
	}else {
		if (tLTree->contains(pos)) tLTree->flip(pos);
		else if (tRTree->contains(pos)) tRTree->flip(pos);
		else if (bLTree->contains(pos)) bLTree->flip(pos);
		else bRTree->flip(pos);
	}

	if (color == 'G') {
		char subTreesColor = tLTree->color;
		if (subTreesColorAllSame() ) {
			//Merge
			color = subTreesColor;
			nodeNum -= 4;
			delete tLTree;
			delete tRTree;
			delete bLTree;
			delete bRTree;
		}
	}
}


void split4(){
	tLTree = new QuadTree(
			topLeft,
			Point((topLeft.row + btmRight.row) / 2, (topLeft.col + btmRight.col) / 2 ),
			color);
	tRTree = new QuadTree(
			Point(topLeft.row, (topLeft.col + btmRight.col) / 2 + 1),
			Point((topLeft.row + btmRight.row) / 2, btmRight.col),
			color);
	bLTree = new QuadTree(
			Point((topLeft.row + btmRight.row) / 2 + 1, topLeft.col),
			Point(btmRight.row, (topLeft.col + btmRight.col) / 2),
			color);
	bRTree = new QuadTree(
			Point((topLeft.row + btmRight.row) / 2 + 1, (topLeft.col + btmRight.col) / 2 + 1),
			btmRight,
			color);
}


bool contains(Point p){
	return (
		p.row >= topLeft.row &&
		p.col >= topLeft.col &&
		p.row <= btmRight.row &&
		p.col <= btmRight.col
		);
}


bool isSize2x2(){
	return(
		abs(topLeft.row - btmRight.row) <= 1 &&
		abs(topLeft.col - btmRight.col) <= 1
		);
}


void leafPixelFlip(){
	if (color == 'B')
		color = 'W';
	else color = 'B';
}


bool subTreesColorAllSame(){
	int black, white;
	black = white = 0;

	black += (tLTree->color == 'B') + (tRTree->color == 'B');
	black += (bLTree->color == 'B') + (bRTree->color == 'B');
	white += (tLTree->color == 'W') + (tRTree->color == 'W');
	white += (bLTree->color == 'W') + (bRTree->color == 'W');

	return (white == 4 || black == 4);
}
};



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	int k, n;
	QuadTree * pic;
	char input;
	int m;
	int row, col;
	int i, j;

	cin >> T;
	for (int cases = 0; cases < T; cases++) {
		cin >> k;
		n = pow(2, k);

		nodeNum = 1;
		pic = new QuadTree(Point(1, 1), Point(n, n), 'W');
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++) {
				cin >> input;
				if (input == '1')
					pic->flip(Point(i, j));
			}
		cin >> m;
		for (i = 0; i < m; i++) {
			cin >> row >> col;
			pic->flip(Point(row, col));
			cout << nodeNum << endl;
		}
		delete pic;
	}
	return 0;
}
