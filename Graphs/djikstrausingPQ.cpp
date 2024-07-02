#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> djisktraUsingPQ(int S, int V, vector<vector<pair<int, int>>> adj)
{
    // initialize a pririty queue with min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // initialize a vector to store minimum distance to reach each node from source
    vector<int> dist(V, INT_MAX);
    // initilially we start from source node whose distance from source is 0.
    dist[S] = 0;
    // push the pair into pq
    // we store it in the pair {distance,node}
    pq.push({0, S});

    while (!pq.empty())
    {
        // grab the distance and node from the pair from the minheap
        int dis = pq.top().first;
        int node = pq.top().second;
        // now we can pop this pair from the queue
        pq.pop();
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;
            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis+edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    // give a adjList with following input
    // collections of arrays with array of integer pairs
    vector<vector<pair<int, int>>> adjList = {
        {{1, 1}, {2, 4}},
        {{0, 1}, {2, 2}, {3, 5}},
        {{0, 4}, {1, 2}, {3, 1}, {4, 3}},
        {{1, 5}, {2, 1}, {4, 2}},
        {{2, 3}, {3, 2}}};

    int Source = 0;
    int Vertices = 5;

    vector<int> distances = djisktraUsingPQ(Source, Vertices, adjList);
    for (int i = 0; i < distances.size(); i++)
    {
        cout << "0 -> "<<i<<" = "<<distances[i]<<endl;
    }
    return 0;
}
