#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Graph
{

public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight, bool direction)
    {
        // direction = 0->undirected
        // direction = 1->directed
        // create edge from u to v
        adjList[u].push_back({v, weight});
        // add edge v to u if undirected
        if (direction == 0)
        {
            adjList[v].push_back({u, weight});
        }
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "->";
            for (auto neighbours : node.second)
            {
                cout << '{' << neighbours.first << "," << neighbours.second << '}' << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;

    // directed edge
    g.addEdge(0, 1, 8, 1);
    g.addEdge(1, 2, 6, 1);
    g.addEdge(0, 2, 5, 1);
    cout << endl;
    g.printAdjList();

    // undirected input
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(0, 2, 0);
    // cout << endl;
    // g.printAdjList();

    return 0;
}