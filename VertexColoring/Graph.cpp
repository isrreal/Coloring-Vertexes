#include "Graph.hpp"

// Constructors 

Graph::Graph(std::list<Vertex*> vertices,
    std::vector<std::pair<int, int>> edges): 
        vertices(vertices),
        edges(edges),
        verticesAmount(vertices.size()),
        edgesAmount(0) {
            this->setEdges(edges);
            for (const auto& it: vertices) 
                verticesAmount += it->adjacencies.size();           
}

Graph::Graph(const Graph& graph) {
    this->vertices = graph.vertices;
    this->edges = graph.edges;
    this->verticesAmount = graph.verticesAmount; 
    this->edgesAmount = graph.edgesAmount;
}

Graph::Graph() {}

// Destructor
Graph::~Graph() {
    for (auto& it: vertices)
        delete it;
}

// O(|V| * |E|)

void Graph::setEdges(std::vector<std::pair<int, int>> edges) {
    for (const auto& start: edges) {
        int source = start.first;
        int destiny = start.second;
        Vertex* v1 = nullptr;
        Vertex* v2 = nullptr;
        for (const auto& it: vertices) {
            if (it->identificator == source) {
                v1 = it;
                break;
            }
        }

        for (const auto& it: vertices) {
            if (it->identificator == destiny) {
                v2 = it;
                break;
            }
        }
   
        if (v1 && v2) { 
            v1->adjacencies.push_back(v2);
            v2->adjacencies.push_back(v1);
        }
    }
}

bool Graph::existsValidColoring() {
    for (auto& it: vertices) {
        if (it->color == ' ') {
            it->color = 'R';
            if (!colorVertex(it))
                return false;
        }
    }
    return true;
}

// Time complexity: O(|V| + |E|)

bool Graph::colorVertex(Vertex* vertex) {
    std::queue<Vertex*> queue;
    queue.push(vertex);
    Vertex* temp = nullptr;
    while (!queue.empty()) {
        temp = queue.front();
        queue.pop();
        char colorNext = (temp->color == 'R') ? 'B' : 'R';
        for (const auto& it: temp->adjacencies) {
            if (it->color == ' ') {
                it->color = colorNext;
                queue.push(it);
            } 
            
            else if (it->color == temp->color)
                return false;
        }
    }
    return true;
}
