#include <cstdio>
#include <vector>
#include <limits.h>
#include <list>
using namespace std;

vector< vector<int> > edgesCapacities; 

int bfs(int source, int sink, int adj[], int n){   
    vector<int> visited= vector<int>(n+2,0); 
    list<int> aux;
    aux.push_back(source);
    visited[source] = 1;
    adj[source] = -1;

    while (!aux.empty()) {
        int i = aux.front();
        aux.pop_front();
        for (int j = 0; j < n+2; j++) {
            if (edgesCapacities[i][j] > 0 && visited[j] == 0 ) {
                visited[j] = 1;
                aux.push_back(j);
                adj[j] = i;
            }
        }
    }
    return (visited[sink]==1);
}

int minimumCost(vector< vector<int>> edges, int source, int sink, int n)
{
    int minCost = 0;
    int adj[n+2]; 
    edgesCapacities= vector<vector<int>>(n + 2, vector<int>(n+2,0));

    edgesCapacities= edges;

    while (bfs(source, sink, adj, n) == 1) {   
        int capacity = INT_MAX;
        for (int j = sink; j != source; j = adj[j]) {
            int i = adj[j];
            capacity = min(capacity, edgesCapacities[i][j]);
        }
 
        for (int j = sink; j != source; j = adj[j]) {
            int i = adj[j];
            edgesCapacities[j][i] += capacity;
            edgesCapacities[i][j] -= capacity;
        }
        minCost += capacity;
    }
    return minCost;
}

int main()
{ 
    int n, k;
    scanf("%d %d", &n, &k);  
    vector< vector<int>> edges= vector<vector<int>>(n + 2, vector<int>(n+2,0));
    
    for(int i=0; i<n; i++){
        int x,y;
        scanf("%d %d", &x, &y);
        edges[0][i+1]=x; 
        edges[i+1][n+1]=y;
    }  

    for(int pro=1; pro<k+1; pro++){
        int i,j, com; 
        scanf("%d %d %d", &i, &j, &com);
        edges[i][j]=com; 
        edges[j][i]=com;
    }  

    int minCost=minimumCost(edges, 0, n+1, n); 

    printf("%d\n", minCost); 
	return 0;
}