#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define INFINITY 10000000

int getPosition(vector<string> place, string target){
    for(int i=0 ; i< place.size(); i++){
        if(target.compare(place[i]) == 0)
            return i;
    }
    return -1;
}

int main(){
    int n,m;
    string place1;
    string place2;
    int p1_pos;
    int p2_pos;
    string s;
    size_t last_space;
    size_t sndLast_space;
    int cost1;
    int cost2;

    while(cin >> n){
        vector<string> place(n);
        vector<vector<int>> d(n, vector<int>(n,INFINITY));
        vector<vector<int>> next(n, vector<int>(n,-1));

        for(int i=0; i < n; i++){
            next[i][i] = i;
        }

        cin.ignore(1, '\n');    // cin >> n stops at the first non-numeric character, which is the newline
        for(int i=0; i < n; i++){
            getline(cin, place[i]);
        }

        cin >> m;
        cin.ignore(1, '\n');    // cin >> m stops at the first non-numeric character, which is the newline
        for(int i=0; i < m; i++){
            getline(cin, place1, ':');
            p1_pos = getPosition(place, place1);
            getline(cin, s);
            last_space = s.find_last_of(" ");
            cost1 = stoi(s.substr(last_space+1));
            p2_pos = getPosition(place, s.substr(0,last_space));

            if(p2_pos >= 0){ //unidirectional
             
                place2 = s.substr(0,last_space);
                d[p1_pos][p2_pos] = cost1;
                next[p1_pos][p2_pos] = p2_pos;
                
            } 
            else {  //bidirectional
               
                sndLast_space = s.substr(0,last_space).find_last_of(" ");
                cost2 = stoi(s.substr(sndLast_space + 1, last_space));
                place2 = s.substr(0, sndLast_space);
                p2_pos = getPosition(place, place2);
                d[p1_pos][p2_pos] = cost2;
                d[p2_pos][p1_pos] = cost1;
                next[p1_pos][p2_pos] = p2_pos;
                next[p2_pos][p1_pos] = p1_pos;
            }

        }

        p1_pos = getPosition(place, "office");
        p2_pos = getPosition(place, "hall");
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                if(d[i][k] == INFINITY) continue;
                    for(int j = 0; j < n; j++){
                        if(i == j) continue;
                        if(d[i][j] > d[i][k] + d[k][j]){
                             d[i][j] = d[i][k] + d[k][j];
                             next[i][j] = next[i][k];
                        }
                           
                    }
            }
        }
      
        cout << (d[p1_pos][p2_pos] + d[p2_pos][p1_pos]) << endl;
        p1_pos = getPosition(place, "office");
        p2_pos = getPosition(place, "hall");

        int p = p1_pos;
        while(place[p] != "hall"){
            cout << place[p] << " -> ";
            p = next[p][p2_pos];
        }

       p = p2_pos;
       while(place[p] != "office"){
            cout << place[p] << " -> ";
            p = next[p][p1_pos];
        }

        cout << "office" << endl << endl; 

    }
    return 0;
}