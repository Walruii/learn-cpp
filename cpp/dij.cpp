/*
  code and analize to find the shortest path in a graph with +ve edge weights
  using dijiksh's algorithm (single shortest path algorithm)
 */

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>

typedef struct Edge {
  int vertex;
  int weight;
} Edge;

class Graph {
public:
  int V;
  std::map<int, std::list<Edge>> adj;
  std::vector<std::vector<int>> adjMatrix;
  void addEdge(int v, Edge a);
  void showEdges();
  void shortestPath(int src);
  void initMatrix();
  void setMatrix();
  Graph(int v) : V(v), adjMatrix(v, std::vector<int>(v)) { initMatrix(); }
};
void Graph::initMatrix() {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      adjMatrix[i][j] = 0;
    }
  }
}
void Graph::setMatrix() {
  adjMatrix = {{0, 5, 2, 0, 0, 0}, {5, 0, 1, 2, 0, 0}, {2, 1, 0, 0, 3, 2},
               {0, 2, 0, 0, 0, 1}, {0, 0, 3, 0, 0, 5}, {0, 0, 2, 1, 5, 0}};
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (adjMatrix[i][j] != 0) {
        adj[i].push_back({j, adjMatrix[i][j]});
      }
    }
  }
}

void Graph::addEdge(int v, Edge a) {
  adj[v].push_back(a);
  for (const auto &p : adj) {
    for (const auto &q : p.second) {
      adjMatrix[p.first][q.vertex] = q.weight;
    }
  }
}

void Graph::showEdges() {
  std::cout << "adj List" << std::endl;
  for (const auto &p : adj) {
    std::cout << p.first << ": ";
    for (const auto &q : p.second) {
      std::cout << q.weight << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << "adj matrix" << std::endl;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      std::cout << adjMatrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
void Graph::shortestPath(int src) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq;

  std::vector<int> dist(V, std::numeric_limits<int>::max());

  pq.push(std::make_pair(0, src));
  dist[src] = 0;

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (const auto &i : adj[u]) {
      int v = i.vertex;
      int weight = i.weight;

      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(std::make_pair(dist[v], v));
      }
    }
  }

  std::cout << "Vertex Distance from Source\n";
  for (int i = 0; i < V; ++i)
    std::cout << i << "\t\t" << dist[i] << std::endl;
}

int main() {
  Graph g(6);
  /* g.addEdge(0, {1, 1}); */
  /* g.addEdge(0, {2, 2}); */
  /* g.addEdge(1, {0, 3}); */
  /* g.addEdge(1, {2, 1}); */
  /* g.addEdge(2, {0, 2}); */
  /* g.addEdge(2, {1, 3}); */
  g.setMatrix();
  g.showEdges();
  g.shortestPath(2);
  return 0;
}
