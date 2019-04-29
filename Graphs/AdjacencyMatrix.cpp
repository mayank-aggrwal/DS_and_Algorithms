
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// FUNCTION TO PRINT THE ADJACENCY MaTRIX FORMED OF THE GRAPH //
void printAdjacencyMatrix(bool **graph, int V) {

    cout << "Adjacency Matrix: \n";
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {

    /*

               0
             /  | \
            /   |   \
            1   2   3
            |   |   | \
            4___5___6   7

    */
    // INITIAL INPUT FOR NUMBER OF VERTICES AND EDGES
    int V = 8, E = 9;

    // INITIALISING ADJACENCY MATRIX
    bool **graph = new bool*[V];
    for(int i=0; i<V; i++) {
        graph[i] = new bool[V];
        for(int j=0; j<V; j++) {
            graph[i][j] = false;
        }
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
    edges[7][0] = 3;edges[7][1] = 6;
    edges[8][0] = 7;edges[8][1] = 3;

    //FILLING THE ADJACENCY MATRIX
    for(int i=0; i<E; i++) {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }

    printAdjacencyMatrix(graph, V);

}