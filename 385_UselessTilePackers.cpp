#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std; 

#define MAXN 110

struct point{ 
    int x, y; 
};

point p[MAXN]; 

double area(point p1[], int n) {
    double ans = 0;
    for(int i = 0; i < n; i++)
        ans += p1[i].x * p1[i+1].y - p1[i].y*p1[i+1].x;
    return 0.5*fabs(ans);
}

double crossproduct(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

double dist(point a, point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp1(point a, point b){
	if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool cmp2( point a, point b ){
	double cp = crossproduct( p[0], a, b );
	if (cp != 0) return cp > 0;
	else return dist(p[0], b) > dist(p[0], a);
}

double convexHull(int n){
    sort(p, p+n, cmp1);
	sort(p+1, p+n, cmp2);
	
	int top = 1;
	for (int i = 2 ; i < n ; i++) {
		while (top > 0 && crossproduct(p[top-1], p[top], p[i]) <= 0) 
            top--;
		p[++top] = p[i];
	}
    return top+1;
} 

int main(){
    int n;
    int cnt = 0;
    while(cin >> n){
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            cin >> p[i].x >> p[i].y;
        }
        p[n] = p[0];
        double tileArea = area(p, n);
        int top = convexHull(n);
       
        p[top] = p[0];
        double hullArea = area(p, top);
        cout << "Tile #" << ++cnt << endl;
        cout << "Wasted Space = " << fixed << setprecision(2) << (1-tileArea/hullArea)*100.0 << " %" << endl;
        cout << endl; 
    } 
    return 0; 
} 