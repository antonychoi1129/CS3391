#include<iostream>
#include<queue>
#include<vector>
#include <algorithm>
#include<climits>
using namespace std;

int n;
int dist[1000+1];
bool visited[1000+1];


int target;
struct node{
    int index;
    vector<int> cost;
    vector<node> adj;
    vector<int> weight;
    friend bool operator< (node n1, node n2){
        // if(dist[n1.index] == dist[n2.index])
        //     return n1.cost
	    return dist[n1.index] > dist[n2.index];
    }
}a[1000+1];

void disktra(node source, int n){
    // cout << "hit" << endl;
    

    for(int i=1; i <= n; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    // cout << "hit1" << endl;
    visited[source.index] = 1;
    dist[source.index] = 0;
    priority_queue<node> q;
    q.push(source);

    int s1, s2;
    s1 = s2 = 0;
    while (!q.empty()){
        node u = q.top();   
        // cout << u.index << endl;

        if(u.index == target){
            cout  << dist[target] << " " <<  s1 << endl;
             break;

        }
        // cout << "hit2" << endl;
        q.pop();
        // cout << "size " << u.adj.size() << endl;
        for(int i = 0; i < u.adj.size(); i++){
            // cout << "hit3" << endl;
            // cout << u.index << endl;
            // cout << "adj " << u.adj[i].index << endl;
             if (!visited[u.adj[i].index] && dist[u.index] + u.weight[i] < dist[u.adj[i].index]){
                 dist[u.adj[i].index] = dist[u.index] + u.weight[i];
                 s1 += u.cost[i];
                 q.push(a[u.adj[i].index]);
             }
            //  cout << "hit4" << endl;
        }
    }
}

int main(){
    int n, m, i, t;

    int from, to, weight, cost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        target = n;
        for(int i=1; i <= n; i++){
            visited[i] = 0;
        }

        for(i=0; i <m; i++){
            cin >> from >> to >> weight >> cost;
            a[from].index = from;
            a[to].index = to;
            a[from].adj.push_back(a[to]);
            // cout << "f " << from << " " << a[from].adj[0].index << endl;
            a[from].cost.push_back(cost);
            a[from].weight.push_back(weight);
        }
       disktra(a[1], n);
    }
    return 0;
}



        

 