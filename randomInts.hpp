#ifndef RANDOMINTSHPP
#define RANDOMINTSHPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

std::vector<int>  getVectorOfRandomInts(int numberOfInts, int max) {
    // Check if the requested number of unique integers is greater than the range.
    if (numberOfInts > max + 1) {
        std::cerr << "Error: Cannot generate more unique integers than the specified range allows." << std::endl;
        return std::vector<int>();  // Return an empty vector to indicate an error.
    }

    std::vector<int> result;
    result.reserve(numberOfInts);

    // Create a vector with integers from 0 to max.
    std::vector<int> candidateValues(max + 1);
    std::iota(candidateValues.begin(), candidateValues.end(), 0);

    // Shuffle the vector to randomize the order.
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(candidateValues.begin(), candidateValues.end(), g);

    // Take the first 'numberOfInts' values from the shuffled vector.
    std::copy(candidateValues.begin(), candidateValues.begin() + numberOfInts, std::back_inserter(result));

    return result;
}

int getRandomInt(int min, int max) {
    // Check if the specified range is valid.
    if (min > max) {
        std::cerr << "Error: Invalid range (min > max)." << std::endl;
        return -1;  // Return -1 to indicate an error.
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(gen);
}
#endif