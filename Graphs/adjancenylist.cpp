// adjacency list based on the given edges
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createAdjacencyList(vector<vector<int>> &edges, int numberOfNodes)
{
    vector<vector<int>> adjList(numberOfNodes);
    for (int i = 0; i < edges.size(); i++)
    {
        // first node  0 -> 1
        int u = edges[i][0];
        // cout<<u<<endl;
        // second node
        int v = edges[i][1];
        // cout<<v<<endl;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    return adjList;
}

int main()
{

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {2, 5},
        {3, 4},
        {3, 5},
        {4, 5}};
    int numberOfNodes = 6;
    vector<vector<int>> myGraph = createAdjacencyList(edges, numberOfNodes);

    for (int i = 0; i < myGraph.size(); i++)
    {
        cout<<i<<" -> ";
        for(int j=0; j<myGraph[i].size(); j++){
            cout<<myGraph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}