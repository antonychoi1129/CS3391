#include<iostream>
#include<queue>
#include<vector>
#include <algorithm>
using namespace std;

vector<int> Set;

struct edges{
    int from, to ,weight;
    edges(){}
    edges(int from, int to, int weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

bool CMP(edges a, edges b){
    return a.weight > b.weight;
}

void UnionSet(int set1, int set2){
	Set[set1] += Set[set2]; 
	Set[set2] = set1;  
}

int Find(int element){	
    if (Set[element] < 0)		
        return element;	
    else{
        return Set[element] = Find(Set[element]);
    }		
        
}

void Union (int root1, int root2) {
	if  (Set[root1] < Set[root2]) 	
        UnionSet(root1, root2);	
    else		
        UnionSet(root2, root1);
}

int kruskal(vector<edges> edg, int n){
    sort(edg.begin(), edg.end(), CMP);
    int longest = edg[0].weight;
    for(int i=0; i < edg.size(); i++){
        if(edg[i].weight < longest) break;
        int root1 = Find(edg[i].from);
	    int root2 = Find(edg[i].to); 
		
        if(root1 != root2){
            Union(root1, root2);
        }
    }
    int max;
    int index;
    for(int i=1; i <= n; i++){
        if(Set[i] < 0){
            max = Set[i];
            index = i;
            break;
        }
    
    }
    for(int i=index; i <= n; i++){
        if(Set[i] < max) max = Set[i];
    }
    return (-max);
}
   


int main(){
    int n, m, i;
    int from, to, weight;
    
    while(cin >> n >> m){

        if(n==0 && m == 0) break;

        Set.resize(n+1);
        for(int i =1; i <= n; i++){
            Set[i] = -1;
        }

        vector<edges> edg;

        for(i=0; i <m; i++){
            cin >> from >> to >> weight;
            edges temp(from, to, weight);
            edg.push_back(temp);
        }

        cout << kruskal(edg, n) << endl;
    }
}