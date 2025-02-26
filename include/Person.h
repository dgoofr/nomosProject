#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

class Person {
private:
    std::string name;
    int rank_position;
    std::vector<std::string> tags;

public:
    // Constructor
    Person(const std::string& tempName, int tempRank);

    // Getters
    int getRank() const;
    std::string getName() const;
    std::vector<std::string> getTags() const;

    // Setters
    void setRank(int newRank);
    void addTag(const std::string& newTag);
    void removeTag(const std::string& targetTag);

    // CSV conversion
    std::string toCSV() const;
    static Person fromCSV(const std::string& csvLine);

    // Display
    void display() const;
};

#endif
