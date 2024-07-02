#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> djisktraUsingSet(int S, int V, vector<vector<pair<int, int>>> adj)
{
    // initialize a min-heap using set
    set<pair<int, int>> st;
    // initlize a array for storing distance to every node from the source
    vector<int> dist(V, INT_MAX);
    // initializing distance from source to source is 0.
    dist[S] = 0;
    // insert the {distance,node} pair in the min-heap
    st.insert({0, S});

    // traverse every path and find the shortest one
    while (!st.empty())
    {
        // grab the iterator to the first pair in the set.
        // set by default sorts the pairs
        auto it = *(st.begin());

        // take distance and node
        int nodeDistance = it.first;
        int topNode = it.second;

        // pop or erase the pair after grabbing it above
        st.erase(it);

        // traverse the adjacent nodes
        for (auto neighbour : adj[topNode])
        {
            // first grab the adjcent node and its weight
            int adjNode = neighbour.first;
            int edgeWeight = neighbour.second;
            // check if shorter distance exist
            if (nodeDistance + edgeWeight < dist[adjNode]){
                // check if the pair already exists in the min-heap
                auto alreadyExistingRecord = st.find({dist[neighbour.second],neighbour.first});
                // remove if pairs already exists
                if(alreadyExistingRecord!=st.end()){
                    st.erase(alreadyExistingRecord);
                }
                dist[adjNode] = nodeDistance + edgeWeight;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}
int main()
{
    vector<vector<pair<int, int>>> adjList = {
        {{1, 1}, {2, 4}},
        {{0, 1}, {2, 2}, {3, 5}},
        {{0, 4}, {1, 2}, {3, 1}, {4, 3}},
        {{1, 5}, {2, 1}, {4, 2}},
        {{2, 3}, {3, 2}}};

    int Source = 0;
    int Vertices = 5;

    vector<int> distances = djisktraUsingSet(Source, Vertices, adjList);
    for (int i = 0; i < distances.size(); i++)
    {
        cout << "0 -> " << i << " = " << distances[i] << endl;
    }
    return 0;
    return 0;
}