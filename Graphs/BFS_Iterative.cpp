
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

void printBFS(unordered_map<int, vector<int>*> &graph, int v, bool *visited) {

    // INITIALISE QUEUE
    queue<int> q;

    // PUSH FIRST VERTEX IN QUEUE AND MARK AS VISITED
    q.push(v);
    visited[v] = true;

    while(!q.empty()) {

        // POP FIRST VERTEX AND PRINT
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        // PUSH ALL ADJACENT VERTICES (UNVISITED) IN QUEUE AND MARK THEM VISITED
        for(int i=0; i<graph[curr]->size(); i++) {
            int x = graph[curr] -> at(i);
            if(!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }

}

void printBFS(unordered_map<int, vector<int>*> &graph, int v) {

    // NUMBER OF VERTICES IN GRAPH
    int V = graph.size();

    // INITIALISE A VISITED BOOLEAN ARRAY
    bool *visited = new bool[V];
    for(int i=0; i<V; i++) {
        visited[i] = false;
    }

    cout << "BFS Traversal (" <<  v << " as starting vertex): ";
    printBFS(graph, v, visited);
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

    // FORMING THE EDGES ARRAY
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

    // PRINT BFS USING DIFFERENT VERTICES AS STARTING VERTEX
    printBFS(graph, 0);
    printBFS(graph, 1);
    printBFS(graph, 2);
    printBFS(graph, 3);
    printBFS(graph, 4);
    printBFS(graph, 5);
    printBFS(graph, 6);
    printBFS(graph, 7);

}