// adjacency matrix implementation

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createAdjacencyMatrix(vector<vector<int>> &graph, int numberOfVertices)
{
    vector<vector<int>> adjMatrix(numberOfVertices, vector<int>(numberOfVertices, 0));

    for (int i = 0; i < numberOfVertices; i++)
    {
        for (int j = 0; j < numberOfVertices; j++)
        {
            if (graph[i][j] == 1)
            {
                adjMatrix[i][j] = 1;
                adjMatrix[j][i] = 1;
            }
        }
    }
    return adjMatrix;
}

int main()
{
    vector<vector<int>> inputMatrix = {
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 1, 1}};
    int numberOfVertices = inputMatrix.size();
    cout << numberOfVertices << endl;

    vector<vector<int>> myGraph = createAdjacencyMatrix(inputMatrix, numberOfVertices);
     for (int i = 0; i < numberOfVertices; ++i) {
        for (int j = 0; j < numberOfVertices; ++j) {
            cout << myGraph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}



