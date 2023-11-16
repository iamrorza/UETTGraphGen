#ifndef GRAPHHPP
#define GRAPHHPP

#include "Edge.hpp"
#include "Node.hpp"
#include "Student.hpp"
Node::Node(int examID){
    this->examID = examID;
    this->students = 0;
}

void Node::addStudent(){
    ++this->students;
}

Edge::Edge(Node * n1, Node * n2){
    this->n1 = n1;
    this->n2 = n2;
    this->weight = 1;
    
    n1->addStudent();
    n2->addStudent();
}

void Edge::addStudent(){
    this->n1->addStudent();
    this->n2->addStudent();
    ++this->weight;
}

class Graph{
    public:
        std::vector<Node*>  * nodes;
        std::vector<Edge*>  * edges;
        
        Graph(int exams, int edges, float density, int students){
            this->nodes = new std::vector<Node*>();
            this->setUpNodes(exams);

            this->edges = new std::vector<Edge*>();
        }

        void setUpNodes(int nodeNum){
            for(int i = 0; i < nodeNum; ++i){
                this->nodes->push_back(new Node(i));
            }
        }

        void addEdge(Student s){

            for(int i = 0; i < s.classes.size(); ++i){
                for(int j = i+1; j < s.classes.size(); ++j){
                    Edge * edgeBetween = searchEdges(s.classes.at(i),s.classes.at(j));

                    if(edgeBetween == nullptr){
                        this->edges->push_back(new Edge(this->nodes->at(s.classes.at(i)),this->nodes->at(s.classes.at(j))));
                    }
                    else{
                        edgeBetween->addStudent();
                    }
                }
            }
        }

        Edge * searchEdges(int n1, int n2){
            for(int i = 0; i < this->edges->size(); ++i){
                if((this->edges->at(i)->n1->examID == n1 && this->edges->at(i)->n2->examID == n2)
                    ||
                    (this->edges->at(i)->n2->examID == n1 && this->edges->at(i)->n1->examID == n2)
                )
                {
                    return this->edges->at(i);
                }
            }
            return nullptr;
        }

        int getAmountOfEdges(){
            return this->edges->size();
        }
};

#endif