#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;


void dfs(int n, vector<int> edges[], int maxEdges[], bool visited[]){
	maxEdges[n] = 0;
    visited[n] = true;
	for(int v:edges[n-1]){
		if(!visited[v]){
			dfs(v, edges, maxEdges, visited);
		}
		maxEdges[n] = max(maxEdges[n] , 1 + maxEdges[v]);
    }
}


int biggestSequence(vector<int> edges[], int n)
{   
    int maxSequence = 0;
    int maxEdges[n+1]; 
    bool visited[n+1];
    for(int i =0; i<=n; i++){
        maxEdges[i]=0;
        visited[i]=false; 
    }
    for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i, edges, maxEdges, visited);
		}
        maxSequence = max(maxSequence, maxEdges[i]);
	}
    return maxSequence + 1; 
}

int minimumIntervetion(vector<int> edges[], int n)
{
    int aux[n]; 
    int count=0; 
    for(int u = 1; u<=n; u++){
        aux[u]=0; 
    }   
    for(int u =1; u<=n; u++){
        for (int w: edges[u-1]){
            aux[w]=aux[w]+1; 
        }
    }
    for(int u =1; u<=n; u++){
        if(aux[u]==0){
            count++; 
        }
    } 
    return count;
}


int main()
{     
    int n,m;
    scanf("%d %d", &n, &m);
	vector<int> edges[n];
    
    for(int i=0; i<m; i++){
        int x,y;
        scanf("%d %d", &x, &y);
        edges[x-1].push_back(y);
    }  
    
    int k= minimumIntervetion(edges, n); 
    int l =  biggestSequence(edges, n);
    
    printf("%d %d\n",k, l);  
	return 0;
}

