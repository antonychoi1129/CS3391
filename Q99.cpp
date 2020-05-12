#include <iostream> 
#include <iomanip> 
#include <cmath>
#include <algorithm>
using namespace std; 

#define MAXN 200
#define pi acos(-1.0)

struct point { 
    double x, y; 
}; 

struct Circle{
    int h, k, r;
    Circle() {}
    Circle(int _x, int _y, int _r) : h(_x), k(_y), r(_r) {}
}circles[MAXN];


int main(){
    int n,i,j,h,k,r;
    double x, y;
    int time = 60*24;
    while(cin >> n){
        if(n==0) break;

        for(i = 0; i < n; i++){
            cin >> h >> k >> r;
            circles[i] = Circle(h , k, r);
        }

        double maxshade = 0.0;
        for(i = 0; i < time; i++){
            double rad = 2*pi*i/(24*60);
            x = sin(rad) * 500.0;
            y = cos(rad) * 500.0;
            double sum = 0.0;
            for(j = 0; j < n; j++){ 
                double proj = (x * circles[j].h + y * circles[j].k) / 500.0;
                if (proj < 0) continue;
                double dist = circles[j].h*circles[j].h + circles[j].k*circles[j].k - proj*proj;

                if(dist <= circles[j].r*circles[j].r){
                    sum += 2.0*sqrt(circles[j].r * circles[j].r - dist);
                }
            }
            maxshade = max(maxshade, sum);

        }
        cout << fixed << setprecision(3) << maxshade << endl; 
    } 
    return 0; 
}