#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Graph
{

public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0->undirected
        // direction = 1->directed
        // create edge from u to v
        adjList[u].push_back(v);
        // add edge v to u if undirected
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "->";
            for (auto neighbours : node.second)
            {
                cout << neighbours << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;

    // directed edge
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 1);
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