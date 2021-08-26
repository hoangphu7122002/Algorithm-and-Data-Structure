#include <iostream>

using namespace std;

#define add(a,b) a + b

struct Edge{
    int start;
    int end;
};

struct Graph{
    int V;
    int E;
    Edge* edge;
};

struct subset{
    int parent;
    int rank;
};

Graph* createGraph(int V,int E){
    Graph* graph= new Graph[V * sizeof(Graph)];
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E * sizeof(Edge)];
    return graph;
}

int find(subset* subsets,int i){
    if (subsets[i].parent != i){
        subsets[i].parent = find(subsets,subsets[i].parent);        
    }
    return subsets[i].parent;
}

void Union(subset* subsets,int x,int y){
    if (subsets[x].rank > subsets[y].rank){
        subsets[y].parent = x;
    }
    else if (subsets[y].rank > subsets[x].rank){
        subsets[x].parent = y;
    }
    else {
        subsets[y].parent = x;
        subsets[x].rank++;
    }
}

bool isCycle(Graph* graph){
    subset* subsets = new subset[graph->V * sizeof(subset)];
    for (int i = 0; i < graph->V; i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    for (int i = 0; i < graph->E; i++){
        int x = find(subsets,graph->edge[i].start);
        int y = find(subsets,graph->edge[i].end);
        if (x == y){
            return true;
        }
        Union(subsets,x,y);
    }
    return false;
}

// class Dsu {
//     public: 
//     vector<int> parent; 

//     Dsu(int n) {
//         parent.resize(n+1); 
//         for (int i=0; i < parent.size(); i++) parent[i] = -1; 
//     }
    
//     int getParent(int x) { return parent[x]; }
    
//     int find(int x) { return (parent[x] < 0) ? x : find(parent[x]); }
    
//     int merge(int x, int y) {
//         int px = find(x), py = find(y); 
        
//         if (px == py) return -1; 
        
//         parent[px] += parent[py]; 
//         parent[py] = x; 
        
//         return px;         
//     }
// };

// #define vi vector<int>
// #define vvi vector<vi>

// class Solution {
// public:
//     vi findRedundantDirectedConnection(vvi &edges) {
//         int n = edges.size(); 
//         Dsu dsu(n); 
        
//         vi edge1 = {}, edge2 = {}, best = {}; 
        
//         for (auto edge: edges) 
//             if (dsu.getParent(edge[1]) > 0) {
//                 edge1 = vi {dsu.getParent(edge[1]), edge[1]}; 
//                 edge2 = vi {edge[0], edge[1]}; 
//             } else if (dsu.merge(edge[0], edge[1]) == -1) best = edge;             
    
//         return edge2.size() ? best.size() ? edge1 : edge2 : best; 
//     }
// };
