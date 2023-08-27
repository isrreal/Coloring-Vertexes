#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vertex.hpp"
#include <queue>

// Representation of one no directed graph.

class Graph {
private:
    int vertexesAmount;
    int edgesAmount;
    std::list<Vertex*> vertexes;
    std::vector<std::pair<int, int>> edges;
    void setEdges(std::vector<std::pair<int, int>> edges);
public:
    Graph(std::list<Vertex*> vertexes,
        std::vector<std::pair<int, int>> edges);
    Graph(const Graph& graph);

    Graph();

    ~Graph();
    
    int getEdgesAmount() { return this->edgesAmount; }

    int getVertexesAmount() { return this->vertexesAmount; }

    std::list<Vertex*> getVertexes() { return this->vertexes; };

    bool colorVertex(Vertex* vertex);

    bool existsValidColoring();

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        for (const auto& vertex: graph.vertexes)
            os << *vertex << std::endl;
        return os;
    }
};

#endif
