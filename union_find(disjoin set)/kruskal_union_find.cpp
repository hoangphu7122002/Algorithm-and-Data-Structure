#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Edge{
    int start;
    int end;
    int weight;
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
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[graph->E];
    return graph;
}

int find(subset* subsets,int i){
    if (i != subsets[i].parent){
        cout << "hey" << endl;
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

int compare(const void* a,const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return (a1->weight > b1->weight);
}

void Kruskal(Graph* graph){
    cout << "success" << endl;
    int V = graph->V;
    Edge* result = new Edge[V];
    int e = 0;
    int i = 0;
    int E = graph->E;
    //spanning tree has V - 1 edge
    //increase
    qsort(graph->edge,graph->E,sizeof(graph->edge[0]),compare);
    cout << "miami" << endl;
    subset* subsets = new subset[V];
    cout << "pro" << endl;
    for (int v = 0; v < V; v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    cout << "aha" << endl;
    while (e < V - 1 && i < E){
        Edge curr = graph->edge[i++];
        int x_par = find(subsets,curr.start);
        int y_par = find(subsets,curr.end);
        //doesn't has a cycle
        if (x_par != y_par){
            result[e++] = curr;
            Union(subsets,x_par,y_par);
        }
    }
    cout << "flag" << endl;
    int weight = 0;
    for (e = 0; e < V - 1; e++){
        cout << result[e].start << " " << result[e].end << " " << result[e].weight<< endl;
        weight += result[e].weight;
    }
    cout << "Weight: ";
    cout << weight << endl;
    cout << "hzz";
    delete[] subsets;
    delete[] result;
}

int main()
{
    /* Let us create following weighted graph
            10
        0--------1
        | \ |
    6| 5\ |15
        | \ |
        2--------3
            4 */
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph* graph = createGraph(V, E);
 
    // add edge 0-1
    graph->edge[0].start = 0;
    graph->edge[0].end = 1;
    graph->edge[0].weight = 10;
 
    // add edge 0-2
    graph->edge[1].start = 0;
    graph->edge[1].end = 2;
    graph->edge[1].weight = 6;
 
    // add edge 0-3
    graph->edge[2].start = 0;
    graph->edge[2].end = 3;
    graph->edge[2].weight = 5;
 
    // add edge 1-3
    graph->edge[3].start = 1;
    graph->edge[3].end = 3;
    graph->edge[3].weight = 15;
 
    // add edge 2-3
    graph->edge[4].start = 2;
    graph->edge[4].end = 3;
    graph->edge[4].weight = 4;
 
   
    // Function call
    Kruskal(graph);
 
    return 0;
}
