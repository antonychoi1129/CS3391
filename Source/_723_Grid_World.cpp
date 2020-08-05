/*By reading the following code,
you agree that you are going to enable the "Share Code" function.*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
#define oo 0x3f3f3f3f	//https://www.kawabangga.com/posts/1153s

#define MAXSIZE 100

char maze[MAXSIZE][MAXSIZE];

struct Cord{
	int x, y;
	
	bool operator == (const Cord & n)const{
		return (x == n.x) && (y == n.y);
	}
};

struct Node{
	Cord p;
	int dist;
	
	bool operator < (const Node & n)const{
		return n.dist < dist;
	}
};

//UpDownLeftRight 上下左右	:)
int udlrX[4] = {0 ,0,-1,1};
int udlrY[4] = {-1,1, 0,0};

bool ok(int x, int y, int size){
	return x>=0 && x<size
		&& y>=0 && y<size;
}

int bfs(Cord frm, Cord to,int size){
	bool ved[MAXSIZE][MAXSIZE];
	memset(ved,false, sizeof (ved));
	ved[frm.x][frm.y] = true;
	
	queue<Node> que;
	que.push ( {frm, 0} );
	while(!que.empty()){
		Node now = que.front();
		Cord p = now.p;
		
		if(p==to) return now.dist;
		que.pop();
		
		for(int i=0; i<4; i++){
			int gox = p.x+udlrX[i];
			int goy = p.y+udlrY[i];
			if(!ok(gox,goy,size)) continue;
			
			if(maze[gox][goy]!='#' && !ved[gox][goy]){
				ved[gox][goy] = true;
				que.push( {{ gox, goy }, now.dist+1} );
			}
		}
	}
}

int main(){
	int cases;
	scanf("%i",&cases);
	while(cases--){
		int n;
		scanf("%i\n",&n);
		Cord wallet, kevin, exit;
		
		int i,j;
		for(i=0;i<n;i++){
			gets(maze[i]);
			for(j=0;j<n;j++)
				if(maze[i][j]=='W') wallet = Cord{i,j};
				else if(maze[i][j]=='K') kevin = Cord{i,j};
		}
		for(i=1;i<n-1;i++){
			if(maze[0][i]=='.'){
				exit = Cord{0,i};
				break;
			}
			if(maze[n-1][i]=='.'){
				exit = Cord{n-1,i};
				break;
			}
			
			if(maze[i][0]=='.'){
				exit = Cord{i,0};
				break;
			}
			
			if(maze[i][n-1]=='.'){
				exit = Cord{i,n-1};
				break;
			}
		}
		printf("%i\n",bfs(kevin,wallet,n) + bfs(wallet,exit,n));
	}
	
	return 0;
}


/*

2
10
##########
#.W......#
#####.##.#
#...#.#..#
#.#.#.##K#
#.#.#..###
#.#....#.#
#.######.#
#........#
###.######

*/
