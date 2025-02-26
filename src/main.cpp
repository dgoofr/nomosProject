#include <iostream>
#include <sstream>
#include "../include/Person.h"
#include "../include/FileManager.h"

const std::string DATA_FILE = "data/people.csv";

int main() {
    // Load people from CSV
    //std::vector<Person> people = FileManager::loadFromFile(DATA_FILE);

    std::vector<Person> runtimePeople;

    std::cout << "\nPlease add new people to the list: \n";
    bool exit = false;
    int i = 1;

    while (!exit) { 
        std::string tempName;
        std::string tempTags;
        std::string continueResponse;

        std::cout << "\nPerson " << i << ":\n";
        std::cout << "Name: ";
        std::getline(std::cin, tempName);
     
        std::cout << "Tags (separated by commas, e.g., Scientist,Superhero): ";
        std::getline(std::cin, tempTags);

        Person newPerson(tempName, 1);

        // Split tempTags and add to the person
        std::stringstream ss(tempTags);
        std::string tag;
        while (std::getline(ss, tag, ',')) {
            newPerson.addTag(tag);
        }

        runtimePeople.push_back(newPerson);
        i++;

        std::cout << "Add more people? (y/n): ";
        bool exit1 = false;

        while (!exit1) {
            std::getline(std::cin, continueResponse);

            if (continueResponse == "n") {
                exit = true;
                exit1 = true;
            } else if (continueResponse == "y") {
                exit = false;
                exit1 = true;
            } else {
                std::cout << "Please answer y or n: ";
            }
        }
    }

    FileManager::saveToFile(runtimePeople, DATA_FILE);
    std::cout << "Data saved to " << DATA_FILE << "\n";

    return 0;
}
