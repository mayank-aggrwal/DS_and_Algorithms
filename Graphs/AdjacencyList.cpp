
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// FUNCTION TO PRINT THE ADJACENCY LIST FORMED OF THE GRAPH //
void printAdjacencyList( unordered_map<int, vector<int> *> &graph) {
    int V = graph.size();
    cout << "Adjacency list: \n";
    for(int i=0; i<V; i++) {
        cout << "  " << i <<"  |  ";
        int n = graph[i]->size();
        for(int j=0; j<n; j++) {
            cout << graph[i] -> at(j);
            if(j != n-1) {
                cout << ", ";
            }
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
    edges[7][0] = 3;edges[7][1] = 6;
    edges[8][0] = 7;edges[8][1] = 3;

    //FORMING THE ADJACENCY LIST
    for(int i=0; i<E; i++) {
        graph[edges[i][1]] -> push_back(edges[i][0]);
        graph[edges[i][0]] -> push_back(edges[i][1]);
    }

    printAdjacencyList(graph);

}