#include "Graph.hpp"

// Constructors 

Graph::Graph(std::list<Vertex*> vertexes,
    std::vector<std::pair<int, int>> edges): 
        vertexes(vertexes),
        edges(edges),
        vertexesAmount(vertexes.size()),
        edgesAmount(0) {
            this->setEdges(edges);
            for (const auto& it: vertexes) 
                vertexesAmount += it->adjacencies.size();           
}

Graph::Graph(const Graph& graph) {
    this->vertexes = graph.vertexes;
    this->edges = graph.edges;
    this->vertexesAmount = graph.vertexesAmount; 
    this->edgesAmount = graph.edgesAmount;
}

Graph::Graph() {}

// Destructor
Graph::~Graph() {
    for (auto& it: vertexes)
        delete it;
}

// O(|V| * |E|)

void Graph::setEdges(std::vector<std::pair<int, int>> edges) {
    for (const auto& start: edges) {
        int source = start.first;
        int destiny = start.second;
        Vertex* v1 = nullptr;
        Vertex* v2 = nullptr;
        for (const auto& it: vertexes) {
            if (it->identificator == source) {
                v1 = it;
                break;
            }
        }

        for (const auto& it: vertexes) {
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
    for (auto& it: vertexes) {
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
            // quer dizer que meu graph não possui uma coloração válida
            else if (it->color == temp->color)
                return false;
        }
    }
    return true;
}
