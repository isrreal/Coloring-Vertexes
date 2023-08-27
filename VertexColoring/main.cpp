#include "Graph.hpp"

#include <sstream>
#include <fstream>

// Read whole info of the file "graph.txt"

std::vector<Graph*> readGraphs() {
    std::vector<Graph*> graphs;
    std::list<Vertex*> vertexes;
    std::vector<std::pair<int, int>> edges;
    std::string line;
    int vertexesAmount = 0;
    int edgesAmount = 0;
    int source = 0;
    int destiny = 0;
    std::ifstream file("graph.txt", std::fstream::in);
    if (!file) {
        std::cerr << "Error!" << std::endl;
        return {};
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        ss >> vertexesAmount >> edgesAmount;

        for (size_t i = 0; i < vertexesAmount; ++i)
            vertexes.push_back(new Vertex(i));

        while (edges.size() < edgesAmount) {
            std::getline(file, line);
            std::stringstream ssEdges(line);

            while (edges.size() < edgesAmount && ssEdges >> source >> destiny)
                edges.push_back({source, destiny});
        }
        
        graphs.push_back(new Graph(vertexes, edges));
        vertexes.clear();
        edges.clear();
    }
    return graphs;
}


int main() {
    std::vector<Graph*> graphs = readGraphs();
    for (const auto& it: graphs)
        std::cout << (it->existsValidColoring() ? "YES" : "NO") << std::endl;
    graphs.clear();
    return 0;
}