#include<iostream>
#include<vector>
#include<math.h>
#include <iomanip>

using namespace std;

double min(double x, double y){
    return (x<y)?x:y;
}

double max(double x, double y){
    return (x>y)?x:y;
}

int main(){
    int t, k, i, j, cnt;
    vector<vector<int>> stone(200, vector<int>(2));
    vector<vector<double>> floyd(200, vector<double>(200));
    cnt = 0;
    while(cin >> t){
        if(!t) break;
        cnt++;
        
        for(i=0; i<t; i++)
            cin >> stone[i][0] >> stone[i][1];

        for(i=0; i<t; i++){
            for(j = i+1; j < t; j++){
                floyd[i][j] = floyd[j][i] = sqrt((stone[i][0] - stone[j][0])*(stone[i][0] - stone[j][0]) + (stone[i][1] - stone[j][1])*(stone[i][1] - stone[j][1]));
            }
        }

        for(k = 0 ; k < t; k++){
            for(i = 0; i < t; i++){
                if(floyd[i][k] > 0){
                    for(j = i+1; j < t; j++){
                        floyd[i][j] = floyd[j][i] = min(floyd[i][j], max(floyd[i][k], floyd[k][j]));
                    }
                }
            }
        }
        cout << "Scenario #" << cnt << endl;
        cout<< "Frog Distance = " << fixed << setprecision(3) << floyd[0][1] << endl;
        cout << endl;
    }
    return 0;
}