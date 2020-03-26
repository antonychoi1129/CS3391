#include<iostream>
#include<queue>
#include<vector>
#include <algorithm>
#include <map> 

using namespace std;

vector<int> Set;

struct edges{
    int from, to;
    int weight;
    edges(){}
    edges(int from, int to, int weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

//sort in ascending order
bool CMP(edges a, edges b){
    return a.weight < b.weight;
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
    if(edg.empty()){
        return 0;
    }
    else{
        sort(edg.begin(), edg.end(), CMP);
        int res = 0;
        int connected = 0;
        for(int i=0; i < edg.size(); i++){
            int root1 = Find(edg[i].from);
	        int root2 = Find(edg[i].to);
            if(root1 != root2){
                Union(root1, root2);
                res += edg[i].weight;
                connected++;
            }
        }
        if(connected < n-1)
            res = 0;
        return res;
    }
}
   
int main(){
    int n, m, i;
    string from, to;
    int weight;
    string source;
    while(cin >> n >> m){

        if(n==0 && m == 0) break;

        Set.resize(n+1);
        map<string, int> mymap; 


        for(int i =1; i <= n; i++){
            string place;
            cin >> place;
            mymap[place] = i;
            Set[i] = -1;
        }

        vector<edges> edg;

        for(i=0; i < m; i++){
            cin >> from >> to >> weight;
            edges temp(mymap.find(from)->second, mymap.find(to)->second, weight);
            edg.push_back(temp);
        }
        cin >> source;

        int res = kruskal(edg, n);
        if(res)
            cout << res << endl;
        else 
            cout << "Impossible" << endl;
    }
}