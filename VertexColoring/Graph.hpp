#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vertex.hpp"
#include <queue>

// Representation of one no directed graph.

class Graph {
private:
    int verticesAmount;
    int edgesAmount;
    std::list<Vertex*> vertices;
    std::vector<std::pair<int, int>> edges;
    void setEdges(std::vector<std::pair<int, int>> edges);
public:
    Graph(std::list<Vertex*> vertices,
        std::vector<std::pair<int, int>> edges);
    Graph(const Graph& graph);

    Graph();

    ~Graph();
    
    int getEdgesAmount() { return this->edgesAmount; }

    int getVerticesAmount() { return this->verticesAmount; }

    std::list<Vertex*> getVertices() { return this->vertices; };

    bool colorVertex(Vertex* vertex);

    bool existsValidColoring();

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        for (const auto& vertex: graph.vertices)
            os << *vertex << std::endl;
        return os;
    }
};

#endif
