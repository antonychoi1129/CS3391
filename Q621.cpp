#include<iostream>
#include<vector>

using namespace std;

vector<int> Set;

void UnionSet(int set1, int set2){
	Set[set1] += Set[set2]; 
	Set[set2] = set1;     
}

int Find(int element){	
    if (Set[element] < 0)		
        return element;	
    else		
        return Set[element] = Find(Set[element]);
}

void Union (int element1, int element2) {
	int root1 = Find(element1);
	int root2 = Find(element2);
	if  (Set[root1] < Set[root2]) 	
        UnionSet(root1, root2);	
    else		
        UnionSet(root2, root1);
}

int remove(int n, int connected,  int dijointSet_num, vector<vector<bool>> c, vector<vector<int>> b,  vector<vector<int>> d){
    int cost = 0;
   
    for(int i=1; i <= n; i++){
        if(Set[i] < 0){
            
        }
    }
}

int add(int n, int connected,  int dijointSet_num, vector<vector<bool>> c, vector<vector<int>> b,  vector<vector<int>> d){
    int cost = 0;
}

int main(){
    int n;
    while(cin >> n){
        vector<vector<bool>> c(n+1, vector<bool>(n+1));
        vector<vector<int>> b(n+1, vector<int>(n+1));
        vector<vector<int>> d(n+1, vector<int>(n+1));

        Set.resize(n+1);
        for(int i =1; i <= p; i++)
            Set[i] = -1;

        int connected = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> c[i][j];
                if(c[i][j] == 1 && j > i){
                    Union(i,j);
                    connected++;
                }
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> b[i][j];
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> d[i][j];
            }
        }

        int dijointSet_num = 0;
        for(int i=1; i <= n; i++){
            if(Set[i] < 0) dijointSet_num++;
        }

        int rebuild = 0;
        rebuild += remove(n, connected, dijointSet_num, c, b, d);
        rebuild += add(n, connected, dijointSet_num, c, b, d);
        cout << rebuild << endl;
    }
}