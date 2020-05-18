#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> Set(30001, -1);
int maxs = 0;

void UnionSet(int set1, int set2){
	Set[set1] += Set[set2]; 
	Set[set2] = set1;
    if(-Set[set1] > maxs){
        maxs = -Set[set1];
    }  
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
    if(root1 == root2) return;
	if  (Set[root1] < Set[root2]) 	
        UnionSet(root1, root2);	
    else		
        UnionSet(root2, root1);
}


int main(){
    int t, n, m, i;
    int from, to;
    cin >> t;
    while(t--){
        cin >> n >> m;
        maxs = 0;
        for(int i =1; i <= n; i++){
            Set[i] = -1;
        }
        for(i=0; i <m; i++){
            cin >> from >> to;
            Union(from, to);
        }
        if(m==0) cout << 1 << endl;
        else{
            cout << maxs << endl;
        }
    }
   
}