#ifndef EDGEHPP
#define EDGEHPP

#include <vector>

class Node;

class Edge{
    public:
        Node * n1;
        Node * n2;
        int weight;
        Edge(Node * n1, Node * n2);

        void addStudent();
};

#endif