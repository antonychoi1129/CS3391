#include<iostream>
#include<queue>
#include<vector>
#include <algorithm>

using namespace std;

vector<int> Set;

struct edges{
    int from, to ,weight;
};

bool CMP(edges a, edges b){
    return a.weight < b.weight;
}

edges createEdge(int from, int to, int weight){
    edges new_edge;
    new_edge.from = from;
    new_edge.to = to;
    new_edge.weight = weight;
    return new_edge;
}

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



int kruskal(vector<edges> edg, int p){
    if(edg.empty()){
        return 0;
    }
    else{
        sort(edg.begin(), edg.end(), CMP);
        int res = 0;

        for(int i=0; i < edg.size(); i++){
            if(Find(edg[i].from) != Find(edg[i].to)){
                Union(edg[i].from, edg[i].to);
                res += edg[i].weight;
            }
        }
        return res;
    }
}

int main(){
    int p, r, i;
    int from, to, weight;
    while(cin >> p){
        if(p == 0) break;
        cin >> r;
        Set.resize(p+1);
        for(int i =1; i <= p; i++)
            Set[i] = -1;
        vector<edges> edg;
        for(i=0; i<r; i++){
            cin >> from >> to >> weight;
            edg.push_back(createEdge(from, to, weight));
        }
        
        
            
        cout << kruskal(edg, p) << endl;
        
    }
}