#ifndef STUDENTHPP
#define STUDENTHPP

#include <vector>
#include "randomInts.hpp"
class Student{
    public:
        std::vector<int>  classes;

        Student(int numberOfSubjects, int max){
            classes = getVectorOfRandomInts(numberOfSubjects, max);
        }

        Student(bool isRepeat, int exam1, int exam2){
            classes = std::vector<int>();
            classes.push_back(exam1);
            classes.push_back(exam2);
        }

        Student(int classToAdd){
            classes = std::vector<int>();
            classes.push_back(classToAdd);
        }

        void printClasses(){
            for(int i = 0; i < this->classes.size(); ++i){
                std::cout << this->classes.at(i) << " ";
            };
            std::cout << std::endl;
        }
};

#endif