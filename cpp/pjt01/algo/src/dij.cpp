// C++ program for the above approach

#include <bits/stdc++.h>
#include <utility>

using namespace std;
#define INF 1e9

// Function for Dijkstra Algorithm to
// find single source shortest path
void dijkstra(int source, int n, vector<pair<int, int>> adj[],
              vector<int> &dist) {
  // Resize dist[] to N and assign
  // any large value to it
  dist.resize(n, INF);

  // Initialise distance of source
  // node as 0
  dist[0] = 0;

  // Using min-heap priority_queue
  // for sorting wrt edges_cost
  ///  pair.first  : const, pair :  second
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  // Push the current dist
  // and source to pq
  pq.push({0, 0});

  // Until priority queue is empty
  while (!pq.empty()) {

    // Store the cost of linked
    // node(u) to edges
    int u = pq.top().second;

    // Pop the top node
    pq.pop();

    // Iterate over edges
    for (auto &edge : adj[u]) {

      // Find the starting and
      // ending vertex of edge
      int node = edge.first;      // first : node
      int distance = edge.second; // second : distance

      // Update the distance of node v to minimum of
      // dist[u] + w if it is
      // minimum
      if (dist[u] + distance < dist[node]) {
        dist[node] = dist[u] + distance;
        pq.push({dist[node], node});
      }
    }
  }
}

// Function to find the minimum cost
// between node 1 to node n
void minCostPath(vector<pair<int, pair<int, int>>> &edges, int n, int M) {

  // To create Adjacency List
  vector<pair<int, int>> adj[100005];

  // Iterate over edges
  for (int i = 0; i < M; i++) {

    // Get source, destination and
    // edges of edges[i]
    int x = edges[i].first;
    int y = edges[i].second.first;
    int z = edges[i].second.second;

    // Create Adjacency List
    adj[x].push_back({y, z});
    adj[y].push_back({x, z});
  }

  // To store the cost from node 1
  // and node N
  vector<int> dist_from_source;
  vector<int> dist_from_dest;

  // Find the cost of travel between
  // source(1) to any vertex
  dijkstra(1, n + 1, adj, dist_from_source);

  // Find the cost of travel between
  // destination(n) to any vertex
  dijkstra(n, n + 1, adj, dist_from_dest);

  // Initialise the minimum cost
  int min_cost = dist_from_source[n];

  // Traverse the edges
  for (auto &it : edges) {

    // Get the edges
    int u = it.first;
    int v = it.second.first;
    int c = it.second.second;

    // Find the current cost from
    // node 1 to u and node u to v
    // and node v to N with only
    // current edge cost reduced
    // to half
    int cur_cost = dist_from_source[u] + c / 2 + dist_from_dest[v];

    // Update the min_cost
    min_cost = min(min_cost, cur_cost);
  }

  // Print the minimum cost
  cout << min_cost << '\n';
}

// Driver Code
int main() {
  // Give Nodes and Edges
  int N = 3;
  int M = 4;

  // Given Edges with cost
  vector<pair<int, pair<int, int>>> edges;

  edges.push_back({1, {2, 3}});
  edges.push_back({2, {3, 1}});
  edges.push_back({1, {3, 7}});
  edges.push_back({1, {3, 7}});

  // Function Call
  minCostPath(edges, N, M);
  return 0;
}
