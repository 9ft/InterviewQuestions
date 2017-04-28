#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <vector>


#define V 7

using namespace std;

int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

int printSolution(int dist[], int n, int to)
{
    cout << dist[to] << endl;
}
void dijkstra(int graph[V][V], int src, int to, vector<vector<int> > &path)
{
     int dist[V];
     bool sptSet[V];
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
     dist[src] = 0;
     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)

         // Update dist[v] only if is not in sptSet, there is an edge from
         // u to v, and total weight of path from src to  v through u is
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                path[v].push_back(u);
        }

     }
     printSolution(dist, V, to);
}

// driver program to test above function
int main()
{
    int to, fog;
    while(cin >> to >> fog){
        int graph[V][V] = {
           {1000, 1000, 1000, 1000, 1000, 1000, 1000},
           {1000, 0, 2, 10, 5, 3, 1000},
           {1000, 1000,0, 12, 1000, 1000 ,10},
           {1000, 1000, 1000, 0, 1000, 7, 1000},
           {1000, 2, 1000, 1000, 1, 0, 1000},
           {1000, 4, 1000, 1000, 1, 0, 1000},
           {1000, 3, 1000, 1, 1000, 2, 0}
        };
        if(fog){
             for(int i = 1; i <= 6; i++){
                 graph[fog][i] = 1000;
                 graph[i][fog] = 1000;
             }
        }
        vector<vector<int> > path = {
            {},
            {},
            {},
            {},
            {},
            {},
            {}
        };
        dijkstra(graph, 5, to, path);
        vector<int> result = path[to];
        cout << "[";
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << ", ";
        }
        cout << to << "]" << endl;
    }

    return 0;
}
