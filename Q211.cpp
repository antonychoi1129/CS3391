#include <iostream> 
#include <iomanip> 
#include <cmath>
#include <algorithm>
using namespace std; 

#define MAXN 100000

struct point { 
    int x, y; 
    point(){}
    point(int _x, int _y) : x(_x), y(_y) {}
}; 

point p[MAXN];

double area(point a, point b, point c) { 
   return abs((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y))/2.0); 
} 

bool isInside(point a, point b, point c, point z) {    
   double A = area (a, b, c); 
//    cout << A << endl;
   double A1 = area (a , b, z); 
//   cout << A1 << endl;
   double A2 = area (z, b, c); 
//   cout << A2 << endl;
   double A3 = area (a, z, c); 
    // cout << A3 << endl;
   return (A == A1 + A2 + A3); 
} 

int main(){
    int n,m;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> p[i].x >> p[i].y;
        }
        cin >> m;
        while(m--){
            int x, y;
            cin >> x >> y;
            point t = point(x, y);
            bool flag;
            for(int i = 0; i < n; i++){
                flag = false;
                for(int j = i+1; j < n; j++){
                    for(int k = j+1; k < n; k++){
                        // cout << "ijk " << i << " " << j << " " << k << endl;
                        if(isInside(p[i], p[j], p[k], t)){
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(flag) break;
            }
            if(flag) 
                cout << "inside" << endl;
            else
                cout << "outside" << endl;
        }
    } 
    return 0; 
} 