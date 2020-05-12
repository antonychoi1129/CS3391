#include<iostream>
#include<vector>

using namespace std;

struct point{
    int x, y;
};

bool collinear(point p1, point p2, point p3, point p4){
    //collinear
    int minx = min(p1.x, p2.x);
    int maxx = max(p1.x, p2.x);
    int miny = min(p1.y, p2.y);
    int maxy = max(p1.y, p2.y);
    if(minx <= p3.x && p3.x <= maxx && miny <= p3.y && p3.y <= maxy){
        if((p2.y - p3.y)*(p2.x-p1.x) == (p2.y-p1.y)*(p2.x-p3.x)){
            return 1;
        }
    }
    if(minx <= p4.x && p4.x <= maxx && miny <= p4.y && p4.y <= maxy){
        if((p2.y - p4.y)*(p2.x-p1.x) == (p2.y-p1.y)*(p2.x-p4.x)){
            return 1;
        }
    }
    minx = min(p3.x, p4.x);
    maxx = max(p3.x, p4.x);
    miny = min(p3.y, p4.y);
    maxy = max(p3.y, p4.y);
    if(minx <= p1.x && p1.x <= maxx && miny <= p1.y && p1.y <= maxy){
        if((p4.y - p1.y)*(p1.x-p3.x) == (p1.y-p3.y)*(p4.x-p1.x)){
            return 1;
        }
    }
    if(minx <= p2.x && p2.x <= maxx && miny <= p2.y && p2.y <= maxy){
        if((p4.y - p2.y)*(p2.x-p3.x) == (p2.y-p3.y)*(p4.x-p2.x)){
            return 1;
        }
    }
    
    return 0;
}
bool intersect(point p1, point p2, point p3, point p4){
    double cw1 = (p1.x*p2.y - p2.x*p1.y) + (p2.x*p3.y - p2.y*p3.x) + (p3.x*p1.y - p3.y*p1.x);
    double cw2 = (p1.x*p2.y - p2.x*p1.y) + (p2.x*p4.y - p2.y*p4.x) + (p4.x*p1.y - p4.y*p1.x);
    double cw3 = (p3.x*p4.y - p4.x*p3.y) + (p4.x*p1.y - p4.y*p1.x) + (p1.x*p3.y - p1.y*p3.x);
    double cw4 = (p3.x*p4.y - p4.x*p3.y) + (p4.x*p2.y - p4.y*p2.x) + (p2.x*p3.y - p2.y*p3.x);
    if(collinear(p1, p2, p3, p4))
        return 1;
       
    return cw1*cw2 < 0 && cw3*cw4 < 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, i, j;
    cin >> t;
    vector<vector<point> > segment(100, vector<point>(2));
    while(t--){
        cin >>  n;
        for(i=0; i < n; i++){
            cin >> segment[i][0].x >> segment[i][0].y >> segment[i][1].x >> segment[i][1].y;
        }
        bool isolated;
        int ans = 0;
        for(i=0; i < n; i++){
            isolated = true;
            for(j=0; j < n; j++){
                if(i == j) continue;
                if(intersect(segment[i][0], segment[i][1], segment[j][0], segment[j][1]) == 1){
                    isolated = false;
                    break;
                }
            }
            if(isolated){
                ans++;
            }
        }
        cout  << ans << endl;
    }
    return 0;
}