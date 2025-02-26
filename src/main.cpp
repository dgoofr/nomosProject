#include <iostream>
#include <sstream>  // For splitting tags
#include "../include/Person.h"
#include "../include/FileManager.h"

const std::string DATA_FILE = "data/people.csv";

int main() {
    // Load people from CSV
    std::vector<Person> people = FileManager::loadFromFile(DATA_FILE);

    // Display loaded people
    std::cout << "Loaded People:\n";
    for (const auto& person : people) {
        person.display();
    }

    std::vector<Person> runtimePeople;

    // Add new people through console
    std::cout << "\nPlease add new people to the list: \n";
    bool exit = false;
    int i = 1;

    while (!exit) {  // Corrected loop condition
        std::string tempName;
        std::string tempTags;
        char continueResponse;

        // Get person name
        std::cout << "\nPerson " << i << ":\n";
        std::cout << "Name: ";
        std::getline(std::cin, tempName);

        // Get tags as a comma-separated string
        std::cout << "Tags (separated by commas, e.g., Scientist,Superhero): ";
        std::getline(std::cin, tempTags);

        // Create new person with default rank 1
        Person newPerson(tempName, 1);

        // Split tempTags and add to the person
        std::stringstream ss(tempTags);
        std::string tag;
        while (std::getline(ss, tag, ',')) {
            newPerson.addTag(tag);
        }

        // Add to runtimePeople vector
        runtimePeople.push_back(newPerson);
        i++;  // Increment count

        // Ask if user wants to add more people
        std::cout << "Add more people? (y/n): ";
        bool exit1 = false;

        while (!exit1) {  // Corrected loop condition
            std::cin >> continueResponse;

            if (continueResponse == 'n') {
                exit = true;
                exit1 = true;
            } else if (continueResponse == 'y') {
                exit = false;
                exit1 = true;
            } else {
                std::cout << "Please answer y or n: ";
            }
        }
    }

    // Save back to CSV
    FileManager::saveToFile(runtimePeople, DATA_FILE);
    std::cout << "Data saved to " << DATA_FILE << "\n";

    return 0;
}
