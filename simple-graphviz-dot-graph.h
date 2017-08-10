#ifndef SIMPLE_GRAPHVIZ_LIBRARY_H
#define SIMPLE_GRAPHVIZ_LIBRARY_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

inline void hello() {
    std::cout << "Hello, World!" << std::endl;
}


inline double pi() {
    return 3.14;
}

class Node {
    //std::string label;
    public:
    char id;
    // /double weight;
    Node(char new_id) : id(new_id) {};
};

class Edge {
public:
    unsigned int from;
    unsigned int to;
    std::string label;
    double weight;
};

class Graph {
    std::vector<Edge> edges;
    std::vector<Node> nodes;

    inline void addNode() {
        nodes.push_back(Node('a' + ((char) nodes.size())));
        //std::cout << "Added id = " << nodes[nodes.size() - 1].id << "\n";
    }


    inline void addEdge(Edge &edge) {
        edges.push_back(edge);
    }

public:
    inline Node* getNode(unsigned int index) {
        return &nodes[index];
    }

    inline Edge* getEdge(unsigned int index) {
        return &edges[index];
    }


    inline void addEdge(char from, char to) {
        auto e = Edge();
        e.weight = 0.0;
        e.label = "";
        e.from = ((unsigned int) ((int) from) - 'a');
        e.to = ((unsigned int) ((int) to) - 'a');
        while (e.from >= nodes.size() || e.to >= nodes.size()) {
            this->addNode();
        }
        this->addEdge(e);
    }

    inline std::vector<Edge *> getPath(Node &from, Node &to) {
        //TODO: implement BFS
    }

    inline bool hasPath(Node &from, Node &to) {
        //TODO: implement BFS
    }

    inline std::string toGraphvizDotString() {
        std::ostringstream stream;
        stream << "digraph {\n";
        for (const auto edge : this->edges) {
            stream << "\t" << getNode(edge.from)->id << " -> " << getNode(edge.to)->id
                   << "[label=\"" << edge.label << "\",weight=\"" << edge.weight << "\"]"
                   << ";\n";
        }
        stream << " }\n";
        return stream.str();

    }
};

#endif