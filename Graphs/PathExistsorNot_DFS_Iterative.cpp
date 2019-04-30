
#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

bool hasPath(unordered_map<int, vector<int>*> &graph, int v1, int v2, bool *visited) {

    stack<int> s;
    s.push(v1);
    
    while(!s.empty()) {
        int curr = s.top();
        s.pop();
        
        // IF CURRENT VERTEX HAS BEEN VISITED, THEN SKIP IT
        if(!visited[curr]) {

            // MARK CURRENT VERTEX AS VISITED
            visited[curr] = true;

            // IF FOUND RETURN TRUE
            if(curr == v2) 
                return true;
            
            // OTHERWISE PUSH ALL ADJACENT VERTICES (UNVISITED) INTO THE STACK AND CONTINUE
            for(int i=0; i<graph[curr]->size(); i++) {
                int x = graph[curr] -> at(i);
                if(!visited[x]) 
                    s.push(x);
            }
            
        }
    }

    // IF NOT FOUND RETURN FALSE
    return false;

}

bool hasPath(unordered_map<int, vector<int>*> &graph, int v1, int v2) {

    // NUMBER OF VERTICES IN GRAPH
    int V = graph.size();

    // INITIALISE A VISITED BOOLEAN ARRAY
    bool *visited = new bool[V];
    for(int i=0; i<V; i++) {
        visited[i] = false;
    }

    return hasPath(graph, v1, v2, visited);

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

    // VERTICES TO FIND PATH BETWEEN
    int v1 = 2, v2 = 7;
    
    // FIND PATH
    bool ans = hasPath(graph, v1, v2);
    cout << "Path exists? : ";
    ans == true ? cout << "Yes\n" : cout << "No\n";

}