#include<iostream>
#include<vector>

using namespace std;

vector<int> Set;

struct destroy{
    int from, to;
    int weight;
    destroy(){}
    destroy(int from, int to, int weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

struct add{
    int from, to;
    int weight;
    add(){}
    add(int from, int to, int weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
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

void Union (int root1, int root2, int edges[]){
	if(Set[root1] < Set[root2]){
        UnionSet(root1, root2);
        edges[root1]++;
    }	
    else{
        UnionSet(root2, root1);
        edges[root2]++;
    }
}

bool CMP(add a, add b){
    return a.weight < b.weight;
}

bool CMP1(destroy a, destroy b){
    return a.weight < b.weight;
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0) break;

        vector<add> b;
        vector<destroy> d;
        int edges[n+1];

        Set.resize(n+1);
        for(int i = 1; i <= n; i++){
            Set[i] = -1;
            edges[i] = 0;
        }
            
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                char c;
                cin >> c;
                if(c == '1' && j > i){
                    int root1 = Find(i);
                    int root2 = Find(j);
                    if(root1 != root2){
                        Union(root1, root2, edges);
                    }
                    else {
                        edges[root1]++;
                    }
                    	
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int temp;
                cin >> temp;
                if(j > i){
                    b.push_back(add(i, j, temp));
                }
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
        // for(int i = 1; i <= n; i++)
        //     cout << "ed " << edges[i] << endl;
        int rebuild = 0;
        sort(b.begin(), b.end(), CMP);
        for(int i = 0; i < b.size(); i++){
            int root1 = Find(b[i].from);
	        int root2 = Find(b[i].to);
            if(root1 != root2){
                Union(root1, root2, edges);
                rebuild += b[i].weight;
                if(Set[root1] < Set[root2]){
                    cout << i << " " << edges[root1] << " " << Set[root2] << endl;
                    edges[root1] += Set[root2]; 
                }	
                else{
                    edges[root2] += Set[root1];
                    cout << i << " " <<edges[root2] << " " << Set[root1] << endl;

    }
            }
        }
        
// for(int i = 1; i <= n; i++)
//             cout << "   ed " << edges[i] << endl;
        sort(d.begin(), d.end(), CMP1);
        for(int i = 0; i < d.size(); i++){
            int root = Find(d[i].from);
            // cout << "condi " << root << " " << d[i].from << " " <<  d[i].to << endl;
            // cout << "compare " << edges[root] << " " <<  -Set[root]-1 << endl;
            if(edges[root] > (-Set[root]) - 1){
                // cout << "remove " << root << " " << d[i].from << " " <<  d[i].to << endl;
                rebuild += d[i].weight;
                edges[root]--;

            }
        }
        cout << rebuild << endl;
    }
}