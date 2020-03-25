#include <bits/stdc++.h>
using namespace std;

#define N 8

vector<vector<int>> b(N, vector<int>(N));
vector<vector<int>> res;
vector<int> row;
vector<vector<bool>> marked(N, vector<bool>(N)); 
int r;
int c;

void mark(int i, int j){
    int n ,m;
    
    marked[i][j] = true;

    for(n = i, m = j; n+1 < N && m+1 < N; n++, m++){
        marked[n+1][m+1] = true;
    }

    for(n = i, m = j; n+1 < N && m-1 >= 0; n++, m--){
        marked[n+1][m-1] = true;
    }

    for(n = i, m = j; n-1 >= 0 && m-1 >= 0; n--, m--){
        marked[n-1][m-1] = true;
    }

    for(n = i, m = j; n-1 >= 0 && m+1 < N; n--, m++){
        marked[n-1][m+1] = true;
    }
}

bool check(int i, int j){
    int n,m;

    for(m = j; m >= 0; m--) 
        if (b[i][m]) return false;

    for(n = i, m = j; n+1 < N && m-1 >= 0;n++, m--) 
        if (b[n+1][m-1]) return false;

    for(n = i, m = j; n-1 >= 0 && m-1 >= 0;n--, m--) 
        if (b[n-1][m-1]) return false;
    
    return true;
}

void play(int j){
    int n;
    if(row.size() == N){ 
        res.push_back(row);
    }

    if(j != c && j < N){
        for(n = 0; n < N; n++){
            if(n != r) {
                if(!marked[n][j] && check(n,j)){
                    b[n][j] = 1;
                    row.push_back(n);
                    play(j+1);
                    b[n][j] = 0;
                    row.pop_back();
                }
            }
        }
    }
    if(j == c){
        row.push_back(r);
        play(j+1);
        row.pop_back();                     //important
    } 
}

int main() {
    int t;
    int i;
    int j;
    cin >> t;
    while(t--){
        res.resize(0);
        row.resize(0);
        for(i=0; i<N; i++)
            for(j=0; j < N; j++){
                b[i][j] = 0;
                marked[i][j] = 0;
            }
        cin.ignore(1,'\n');
        cin >> r >> c;
        r--; c--;
        mark(r,c);
        b[r][c] = 1;
        play(0);
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
        for(i = 0; i < res.size(); i++){
            cout << setw(2) << i+1 << "     ";
            for(j = 0; j < N; j++){
                cout << " " << res[i][j] + 1 ;
            }
            cout << endl;
        }

        if(t) cout << endl;
    }
    return 0;
}