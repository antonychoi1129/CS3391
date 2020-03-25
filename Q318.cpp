#include <iostream>
#include <vector>
#define INT_MAX 1000
using namespace std;

vector<int> t;
int n;

int extract_Min(bool visited[], int dist[]){
    int min = INT_MAX;
    int index = 0;
    for(int i = 1; i <= n*n; i++){
        if(dist[i] != INT_MAX){
             if(!visited[i] && dist[i] < min){
            min = dist[i];
            index = i;
            }
        }
    }
    return index; // return vertice index
}

vector<int> getNeighbours(int u, bool visited[]){
    vector<int> nei;
    int i,j;
    i = (u-1)/n + 1;
    j = (u-1)%n + 1;

    if(i-1 >= 1 && !visited[n*(i-1-1) + j])
        nei.push_back(n*(i-1-1) + j);

    if(i+1 <= n && !visited[n*(i-1+1) + j])
         nei.push_back(n*(i-1+1) + j);
       
    if(j-1 >= 1 && !visited[u-1])
        nei.push_back(u-1);

    if(j+1 <= n && !visited[u+1])
        nei.push_back(u+1);
    
    return nei;
}

int dijkstra(){

    int dist[n*n+1];
    bool visited[n*n+1];
   
    for(int i=1; i <= n*n; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[1] = t[1];
    for (int s = 1; s <= n*n; s++) { 
        int u = extract_Min(visited, dist); 
        if(u){
            visited[u] = true; 
            vector<int> neighbours;
            neighbours = getNeighbours(u, visited);
            for (int v = 0; v < neighbours.size(); v++) {
                if (!visited[neighbours[v]] && dist[u] + t[neighbours[v]] < dist[neighbours[v]])
                    dist[neighbours[v]] = dist[u] + t[neighbours[v]];
            }
        }
    } 
    return dist[n*n];
}

int main() {
    int i,j, problem;
    problem = 0;
    while (cin >> n){
        if(n==0) break;
        problem++;
        t.resize(n*n+1);
        for(i = 1; i <= n*n; i++){
            cin >> t[i];
        }
        cout << "Problem " << problem << ": " << dijkstra() << endl;
    }
}