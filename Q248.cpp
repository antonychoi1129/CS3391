#include<iostream>
#include<vector>

using namespace std;

struct point{
    int x, y;
};

bool in(point p, point a, point b)
{
	return (a.x <= p.x)&&(a.y >= p.y)&&(b.x >= p.x)&&(b.y <= p.y);
}

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
    if(collinear(p1, p2, p3, p4))
        return 1;

    double cw1 = (p1.x*p2.y - p2.x*p1.y) + (p2.x*p3.y - p2.y*p3.x) + (p3.x*p1.y - p3.y*p1.x);
    double cw2 = (p1.x*p2.y - p2.x*p1.y) + (p2.x*p4.y - p2.y*p4.x) + (p4.x*p1.y - p4.y*p1.x);
    double cw3 = (p3.x*p4.y - p4.x*p3.y) + (p4.x*p1.y - p4.y*p1.x) + (p1.x*p3.y - p1.y*p3.x);
    double cw4 = (p3.x*p4.y - p4.x*p3.y) + (p4.x*p2.y - p4.y*p2.x) + (p2.x*p3.y - p2.y*p3.x);
    return cw1*cw2 < 0 && cw3*cw4 < 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, i;
    cin >> t;
    vector<vector<point> > segment(5, vector<point>(2));
    while(t--){

        cin >> segment[0][0].x >> segment[0][0].y >> segment[0][1].x >> segment[0][1].y
            >> segment[1][0].x >> segment[1][0].y >> segment[2][0].x >> segment[2][0].y;
        
        segment[1][1].x = segment[1][0].x;
        segment[1][1].y = segment[2][0].y;
        segment[2][1].x = segment[2][0].x;
        segment[2][1].y = segment[1][0].y;

        segment[3][0].x = segment[1][0].x; segment[3][0].y = segment[1][0].y;
        segment[3][1].x = segment[2][1].x; segment[3][1].y = segment[2][1].y;

        segment[4][0].x = segment[2][0].x; segment[4][0].y = segment[2][0].y;
        segment[4][1].x = segment[1][1].x; segment[4][1].y = segment[1][1].y;

        point c; c.x = min( segment[1][0].x, segment[2][0].x  ); c.y =  max( segment[1][0].y, segment[2][0].y ) ;
		point d; d.x = max( segment[1][0].x, segment[2][0].x); d.y =  min( segment[1][0].y, segment[2][0].y ) ;
       
        if ( in( segment[0][0], c, d ) || in( segment[0][1], c, d ) ){
            cout << "T" << endl;
            continue;
        }
        bool flag;
        for(i=1; i < 5; i++){
            flag = false;
            // cout << segment[i][0].x << " " << segment[i][0].y << " " << segment[i][1].x << " " << segment[i][1].y << endl;
            if(intersect(segment[0][0], segment[0][1], segment[i][0], segment[i][1])){
                    flag = true;
                    break;
            }
        }

        if(flag)
            cout  << "T" << endl;
        else
            cout  << "F" << endl;
        
    }
    return 0;
}