
// Problem -> https://leetcode.com/problems/path-with-maximum-probability/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
{
    // first let us build the graph suitable for using djikstra's algorithm
    // {node,succProb}
    vector<vector<pair<int, double>>> graph(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        double prob = succProb[i];
        graph[u].push_back({v, prob});
        graph[v].push_back({u, prob});
    }
    // using a max heap as we have to find maximum success probability
    priority_queue<pair<double,int>> pq;
    pq.push({1.0,start_node});

    vector<double> probabilites(n,0.0);
    // initializing 1.0 as multiplying with 1.0 doesnot change the value also the probability for reaching from source to same node always 1.
    probabilites[start_node] = 1.0;

    while(!pq.empty()){
        double curr_prob = pq.top().first;
        int topNode = pq.top().second;
        pq.pop();
        // checking beforehand to skip unnecessary iterations for other nodes
        if(topNode==end_node){
            return curr_prob;
        }
        // traversinh everynode
        for(auto neighbour:graph[topNode]){
            int adjNode = neighbour.first;
            double probab = neighbour.second;
            double new_prob = curr_prob*probab;
            if(new_prob>probabilites[adjNode]){
                probabilites[adjNode] = new_prob;
                pq.push({probabilites[adjNode],adjNode});
            }
        }

    }
    return probabilites[end_node];
}

int main()
{
    // this is the given input format in the leetcode
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    int start = 0;
    int end = 2;
    double maxSuccessProbability = maxProbability(n, edges, succProb, start, end);
    cout << maxSuccessProbability << endl;
    return 0;
}
