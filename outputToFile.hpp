#ifndef OUTPUTTOFILEHPP
#define OUTPUTTOFILEHPP

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "Student.hpp"
#include "Graph.hpp"

void outputToFile(std::string fileName, Graph * g, std::vector<Student> * students, int periods){
    std::ofstream MyFile(fileName);

    MyFile << g->nodes->size() << " " << students->size() << " " << periods << std::endl;

    for(int i = 1; i <= g->nodes->size(); ++i){
        std::string examString = std::to_string(i) + " " + std::to_string(g->nodes->at(i-1)->students);

        MyFile << examString << std::endl;
    }
    MyFile << "\n";

    for(int i = 0; i < students->size(); ++i){
        for(int j = 0; j < students->at(i).classes.size(); ++j){
            std::string studentString = "s" + std::to_string(i+1) + " " + std::to_string(students->at(i).classes.at(j)+1);
            MyFile << studentString << std::endl;
        }
        
    }

    MyFile.close();

    std::cout << fileName << " Complete" << std::endl;
}   


#endif