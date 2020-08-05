#include <iostream>
#include <memory>
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

	struct Node {
		bool mixed, black;	//B=Black, W=White, G=Grey(Mixed)

		Node(bool b){black = b; mixed = false;}
		Node(){
			mixed = true;
		}
	};

	class QuadTree {
	Point topLeft;
	Point btmRight;
	Node *node;

	//Children
	QuadTree *tLTree;
	QuadTree *tRTree;
	QuadTree *bLTree;
	QuadTree *bRTree;

public:
	QuadTree(){
		tLTree = tRTree = bLTree = bRTree = NULL;
		node = NULL;
		topLeft = Point();
		btmRight = Point();
	}
	QuadTree(Point tL, Point bR, bool black){
		tLTree = tRTree = bLTree = bRTree = NULL;
		topLeft = tL;
		btmRight = bR;
		node = new Node(black);
		/*cout << "TopLeft:(" << topLeft.row << "," << topLeft.col << ") BottomRight:(" << btmRight.row << "," << btmRight.col <<
		") Node Color:" << node->color << endl;*/
	}

	void flip(Point pos){
		//cout<<"TopLeft:("<<topLeft.row<<","<<topLeft.col<<") BottomRight:("<<btmRight.row<<","<<btmRight.col<<")"<<endl;
		//cout<<node->color<<endl;
		if (!node->mixed) {
			split4();
			node->mixed = true;
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

		if (node->mixed) {
			//cout << tLTree->node->color << tRTree->node->color << endl;
			//cout << bLTree->node->color << bRTree->node->color << endl;
			char subTreeIsBlack = tLTree->node->black;
			if (subTreesColorAllSame() ) {
				node->black = subTreeIsBlack;
				node->mixed = false;
				nodeNum -= 4;
			}
		}
	}


	void split4(){
		tLTree = new QuadTree(
				topLeft,
				Point((topLeft.row + btmRight.row) / 2, (topLeft.col + btmRight.col) / 2 ),
				node->black);
		tRTree = new QuadTree(
				Point(topLeft.row, (topLeft.col + btmRight.col) / 2 + 1),
				Point((topLeft.row + btmRight.row) / 2, btmRight.col),
				node->black);
		bLTree = new QuadTree(
				Point((topLeft.row + btmRight.row) / 2 + 1, topLeft.col),
				Point(btmRight.row, (topLeft.col + btmRight.col) / 2),
				node->black);
		bRTree = new QuadTree(
				Point((topLeft.row + btmRight.row) / 2 + 1, (topLeft.col + btmRight.col) / 2 + 1),
				btmRight,
				node->black);
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
		//cout << "topLeft: (" << topLeft.row << "," << topLeft.col<<")" << endl;
		//cout << "btmRight: (" << btmRight.row << "," << btmRight.col<<")" << endl;
		return(
			abs(topLeft.row - btmRight.row) <= 1 &&
			abs(topLeft.col - btmRight.col) <= 1
			);
	}


	void leafPixelFlip(){
		node->black = !node->black;
	}


	bool subTreesColorAllSame(){
		int black = 0;

		if(tLTree->node->mixed || tRTree->node->mixed ||
			bLTree->node->mixed || bRTree->node->mixed)
			return false;

		black += (tLTree->node->black) + (tRTree->node->black);
		black += (bLTree->node->black) + (bRTree->node->black);
		return (black==0 || black == 4);
	}
	};



	int main(){
		ios::sync_with_stdio(false);
		int T;
		int k, n;
		QuadTree* pic;
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
		}

		return 0;
	}
