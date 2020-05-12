#include <iostream> 
#include <iomanip> 
#include <cmath>
#include <algorithm>
using namespace std; 

#define MAXN 100

struct point{ 
    int x, y, d; 
}; 

point p[MAXN+3], h[1000];;


int crossproduct(point a, point b, point c){

	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

int dist(point a, point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool cmp(point a, point b) {
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

double convexHull(int n){
    double tile = 0;
	for (int i = 1 ; i < n-1; i++)
		tile += crossproduct(p[0], p[i], p[i+1]);
    tile = fabs(tile)*0.5;
    

    sort(p, p+n, cmp);
    
    int top = 1;
    h[0] = p[0];
	for (int i = 2 ; i < n ; i++) {
		while (top > 0 && crossproduct(h[top-1], h[top], p[i]) <= 0) 
            top--;
		h[++top] = p[i];
	}
    
    top = 1;
    for (int i = n-1 ; i >=0; i--) {
		while (top > 0 && crossproduct(h[top-1], h[top], p[i]) <= 0) 
            top--;
		h[++top] = p[i];
	}

    double sum = 0.0;
	for (int i = 1 ; i < top ; ++ i )
		sum += crossproduct( p[0], p[i], p[i+1] );
    sum = fabs(sum)*0.5;
    // cout << "s2 " << S2 << endl;
    return (sum - tile)/sum * 100.0;

} 

int main(){
    int n;
    int cnt = 0;
    while(cin >> n){
        cnt ++;
        for(int i = 0; i < n; i++){
            cin >> p[i].x >> p[i].y;
        }
        // double tileArea = getTileArea(p, n);
        // double convexHullArea = convexHull(p, n);
        
        cout << "Tile #" << cnt << endl;
        cout << "Wasted Space = " << fixed << setprecision(2) << convexHull(n) << " %" << endl; 
        // cout << "Wasted Space = " << fixed << setprecision(2) << ((convexHullArea - tileArea)/convexHullArea) * 100.0 << " %" << endl; 
        cout << endl;
    } 
    return 0; 
} 