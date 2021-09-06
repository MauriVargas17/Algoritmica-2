#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
 
#define V 5

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, minimumVertex = 0;
 
    for (int v = 0; v < V; v++){
        if (mstSet[v] == false && key[v] < min){
            min = key[v];
            minimumVertex = v;
        }
    }   
    return minimumVertex;
}
 
void prim(int graph[V][V]){
    
    int parent[V];
    int key[V];
    bool MST[V];
 
   
    for (int i = 0; i < V; i++){
        key[i] = INT_MAX;
        MST[i] = false;
    }
      
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < V - 1; count++) {
       
        int u = minKey(key, MST);

        MST[u] = true;
 
        for (int v = 0; v < V; v++){
            
            if (graph[u][v] && MST[v] == false && graph[u][v] < key[v]){
                
                parent[v] = u;
                key[v] = graph[u][v];
            }
                
        }
           
    }
    printMST(parent, graph);
}
 


void printMST(int parent[], int graph[V][V]) {
    
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}


int main(){
    
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    prim(graph);
 
}

 