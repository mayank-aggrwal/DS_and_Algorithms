
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void printDFS(unordered_map<int, vector<int>*> &graph, int v, bool *visited) {

    // PRINT CURRENT VERTEX
    cout << v << " ";

    // MARK VERTEX v AS VISITED 
    visited[v] = true;

    // RECURSIVE CALL EVERY ADJACENT VERTEX (UNVISITED)
    for(int i=0; i<graph[v]->size(); i++) {
        int x = graph[v]->at(i);
        if(!visited[x]) {
            printDFS(graph, x, visited);
        }
    }

}

void printDFS(unordered_map<int, vector<int>*> &graph, int v) {

    // NUMBER OF VERTICES IN GRAPH
    int V = graph.size();

    // INITIALISE A VISITED BOOLEAN ARRAY
    bool *visited = new bool[V];
    for(int i=0; i<V; i++) {
        visited[i] = false;
    }

    cout << "DFS Traversal: ";
    printDFS(graph, v, visited);
    cout << endl;

}

int main() {

    /*

               0
             /  | \
            /   |   \
            1   2    3
            |   |     \
            4___5___6   7

    */
    // INITIAL INPUT FOR NUMBER OF VERTICES AND EDGES
    int V = 8, E = 9;

    unordered_map<int, vector<int> *> graph;
    for(int i=0; i<V; i++) {
        graph[i] = new vector<int>();
    }

    // INPUT FOR EDGES
    int **edges = new int*[E];
    for(int i=0; i<E; i++) {
        edges[i] = new int[2];
    }

    edges[0][0] = 0;edges[0][1] = 1;
    edges[1][0] = 0;edges[1][1] = 2;
    edges[2][0] = 0;edges[2][1] = 3;
    edges[3][0] = 1;edges[3][1] = 4;
    edges[4][0] = 4;edges[4][1] = 5;
    edges[5][0] = 2;edges[5][1] = 5;
    edges[6][0] = 5;edges[6][1] = 6;
    edges[8][0] = 7;edges[8][1] = 3;

    //FORMING THE ADJACENCY LIST
    for(int i=0; i<E; i++) {
        graph[edges[i][1]] -> push_back(edges[i][0]);
        graph[edges[i][0]] -> push_back(edges[i][1]);
    }

    printDFS(graph, 0);

}