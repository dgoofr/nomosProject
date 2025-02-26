#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>      
#include <cstdio>  
#include "../include/Person.h"

class FileManager {
public:
    static void saveToFile(const std::vector<Person>& people, const std::string& filename);
    static std::vector<Person> loadFromFile(const std::string& filename);
};

#endif
