#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// #define size 52

vector<int> Set(52);

//Stragegy: sort the cost, if original road are in the same set, mark the road can be removed, if not then mark it can be added
struct destroy{
    int from, to;
    int weight;
    bool canDestroy;
    destroy(){}
    destroy(int from, int to, int weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
        this->canDestroy = false;
    }
};

struct add{
    int from, to;
    int weight;
    bool canAdd;
    add(){}
    add(int from, int to, int weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
        this->canAdd = false;
    }
};

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

void Union (int root1, int root2){
	if(Set[root1] < Set[root2]){
        UnionSet(root1, root2);
    }	
    else{
        UnionSet(root2, root1);
    }
}

bool CMP(add a, add b){
    return a.weight < b.weight;
}

bool CMP1(destroy a, destroy b){
    return a.weight > b.weight;
}

int main(){
    int n;

    while(cin >> n){
        if(n == 0) break;
        vector<add> b;
        vector<destroy> d;
        vector<vector<bool> > o(n+1, vector<bool>(n+1));

        for(int i = 1; i <= n; i++){
            Set[i] = -1;
        }
            
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                char c;
                cin >> c;
                o[i][j] = (int)(c - '0');
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int temp;
                cin >> temp;
                if(j > i)
                    b.push_back(add(i, j, temp));
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int temp;
                cin >> temp;
                if(j > i)
                    d.push_back(destroy(i, j, temp));
            }
        }
       
        sort(d.begin(), d.end(), CMP1);
        for(int i = 0; i < d.size(); i++){
            if(o[d[i].from][d[i].to]){
                int root1 = Find(d[i].from);
                int root2 = Find(d[i].to);
                if(root1 == root2){
                    d[i].canDestroy = true;
                }
                else{
                    Union(root1, root2);
                }
            }
        }

        sort(b.begin(), b.end(), CMP);
        for(int i = 0; i < b.size(); i++){
            if(!o[b[i].from][b[i].to]){
                int root1 = Find(b[i].from);
                int root2 = Find(b[i].to);
                if(root1 != root2){
                    b[i].canAdd = true;
                    Union(root1, root2);
                }
            } 
        }

        int rebuild = 0;
        for(int i = 0; i < d.size(); i++){
            if(d[i].canDestroy){
                rebuild += d[i].weight;
            }
        }

        for(int i = 0; i < b.size(); i++){
            if(b[i].canAdd){
                rebuild += b[i].weight;
            }
        }
        cout << rebuild << endl;
    }
}