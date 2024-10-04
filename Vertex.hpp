#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <vector>
#include <list>
#include <utility>

struct Vertex {
    int identificator;
    char color;
    std::list<Vertex*> adjacencies;
    Vertex(int identificator, char color = ' '): identificator(identificator), color(color) {}
    ~Vertex() {}

    friend std::ostream& operator<<(std::ostream& os, const Vertex& vertex) {
        os << vertex.identificator << " -> ";
        for (const auto& it: vertex.adjacencies)
            os << it->identificator << " ";
        return os;
    }
    
    bool operator== (const Vertex& vertex) {
        return this->identificator == vertex.identificator;
    }
};

#endif