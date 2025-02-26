#include "../include/FileManager.h"

// Load people from file
std::vector<Person> FileManager::loadFromFile(const std::string& filename) {
    std::vector<Person> people;
    std::ifstream inFile(filename);

    if (!inFile) {
        std::cerr << "Warning: Could not open file for reading: " << filename << std::endl;
        return people;  // Return empty if the file doesn't exist
    }

    std::string line;
    while (std::getline(inFile, line)) {
        if (!line.empty()) {  // Ensure we're not reading empty lines
            people.push_back(Person::fromCSV(line));
        }
    }

    inFile.close();
    return people;
}

// Save to file with duplicate prevention
void FileManager::saveToFile(const std::vector<Person>& people, const std::string& filename) {
    std::string tempFilename = filename + ".temp";  // Temporary file to avoid losing data already stored
    std::ofstream tempFile(tempFilename);

    if (!tempFile) {
        std::cerr << "Error: Could not create temporary file for writing: " << tempFilename << std::endl;
        return;
    }

    // Step 1: Load existing people from the file
    std::vector<Person> existingPeople = loadFromFile(filename);

    // Step 2: Copy existing people into a set for fast duplicate checking
    std::set<std::string> existingNames;
    for (const auto& person : existingPeople) {
        existingNames.insert(person.getName());
    }


    for (const auto& person : people) {
        if (existingNames.find(person.getName()) == existingNames.end()) {  // If not a duplicate
            existingPeople.push_back(person);
            existingNames.insert(person.getName());  // Mark as seen
        } else { //if it is a duplicate
            std::cout << "Skipping duplicate: " << person.getName() << std::endl;
        }
    }

    // Step 4: Write all people back to the temp file
    for (const auto& person : existingPeople) { 
        tempFile << person.toCSV() << "\n";
    }

    tempFile.close();  // Close the temp file to finalize writing

    // Step 5: Replace the original file with the new one
    if (std::remove(filename.c_str()) != 0 && std::ifstream(filename)) {  // Ensure old file exists before removing
        std::cerr << "Error: Could not delete old file: " << filename << std::endl;
        return;
    }

    if (std::rename(tempFilename.c_str(), filename.c_str()) != 0) {
        std::cerr << "Error: Could not rename temp file to: " << filename << std::endl;
        return;
    }

    std::cout << "File successfully saved: " << filename << std::endl;
}


