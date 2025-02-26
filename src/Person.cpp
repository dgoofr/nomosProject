#include "../include/Person.h"

// Constructor
Person::Person(const std::string& tempName, int tempRank) : name(tempName), rank_position(tempRank) {}

// Getters
std::string Person::getName() const { return name; }
int Person::getRank() const { return rank_position; }
std::vector<std::string> Person::getTags() const { return tags; }

// Setters
void Person::setRank(int newRank) {
    if (newRank >= 1) {  // Ensures rank starts from 1
        rank_position = newRank;
    }
}

void Person::addTag(const std::string& newTag) {
    if (std::find(tags.begin(), tags.end(), newTag) == tags.end()) {
        tags.push_back(newTag);
    }
}

void Person::removeTag(const std::string& targetTag) {
    tags.erase(std::remove(tags.begin(), tags.end(), targetTag), tags.end());
}

// CSV Conversion
std::string Person::toCSV() const {
    std::ostringstream oss;
    oss << name << "," << rank_position;
    for (const auto& tag : tags) { 
        oss << "," << tag; 
    }
    return oss.str();
}

Person Person::fromCSV(const std::string& csvLine) {
    std::istringstream iss(csvLine);
    std::string token;
    std::vector<std::string> parts;

    while (std::getline(iss, token, ',')) {
        parts.push_back(token);
    }

    if (parts.size() < 2) return Person("", -1); // Ensures valid input

    Person newPerson(parts[0], std::stoi(parts[1])); // Create new Person

    for (size_t i = 2; i < parts.size(); i++) {  
        newPerson.addTag(parts[i]);  
    }

    return newPerson;
}

// Display Function
void Person::display() const {
    std::cout << rank_position << ". " << name << " | Tags: ";
    
    for (size_t i = i; i < tags.size(); i++) {
        std::cout << tags[i];
        if (i < tags.size() - 1) {  // Print a comma **only if it's not the last tag**
            std::cout << ", ";
        }
    }
    
    std::cout << "\n";
}
