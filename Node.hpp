#ifndef NODEHPP
#define NODEHPP

#include <vector>

class Edge;

class Node{
    public:
        std::vector<Edge> * edges;
        int students;
        int examID;
        Node(int examID);
        void addStudent();
};

#endif