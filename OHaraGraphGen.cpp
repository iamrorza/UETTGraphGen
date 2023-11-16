#include <iostream>
#include "Student.hpp"
#include "Graph.hpp"
#include "randomInts.hpp"
#include "outputToFile.hpp"

void createGraph(std::string url, int exam, float den, int stu, int per){
    try{
        int exams = exam;
        float density = den;
        int edges = exams * (exams - 1) * density / 2;
        int students = stu;
        int periods = per;

        Graph * g = new Graph(exams, edges, density, students);
        std::vector<Student> studentVector = std::vector<Student>();

        /*
            Density = 2 * E / Exams * Exams - 1
            Exams * Exams - 1 * density / 2 = E
        */
        
        for(int i = 0 ; i < students; ++i){
            if(g->getAmountOfEdges() >= edges){
                break;
            }
            Student s = Student(getRandomInt(1,8),exams - 1);
            studentVector.push_back(s);
            g->addEdge(s);
            
        }   
        int currentEdges = g->getAmountOfEdges();
        
        while(studentVector.size() < students){
            Edge * randomEdge = g->edges->at(getRandomInt(0,currentEdges-1));
            Student repeatStudent = Student(true, randomEdge->n1->examID, randomEdge->n2->examID);
            randomEdge->addStudent();
            studentVector.push_back(repeatStudent);
        }

        for(int i = 0; i < g->nodes->size(); ++i){
            if(g->nodes->at(i)->students == 0){
                Student s = Student(i);
                g->nodes->at(i)->addStudent();
                studentVector.push_back(s);
            }
        }
        outputToFile(url,g,&studentVector,periods);
        
    }
    catch(const std::exception& e){

    }
    
}

int main(int argc, char** argv){

    std::string textFile = argv[1];
    int exam = std::stoi(argv[2]);
    float den = std::stof(argv[3]);
    int students = std::stoi(argv[4]);
    int periods = std::stoi(argv[5]);
    
    createGraph(textFile, exam, den, students, periods);

    return 0;
}
