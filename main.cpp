#include "simple-graphviz-dot-graph.h"

using namespace std;

int main() {
    hello();

    auto graph = Graph();

    graph.addEdge('a', 'b');
    graph.addEdge('a', 'c');
    graph.addEdge('e', 'e');
    graph.addEdge('e', 'b');
    graph.addEdge('e', 'a');

    cout << graph.toGraphvizDotString() << endl;
}