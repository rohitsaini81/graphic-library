//
// Created by rohit on 9/2/25.
//


#include <string>
#include <fstream>
#include <iostream>

#include "../variables.h"

std::string load_file(const std::string path) {
std::ifstream file(root_path+path);
    std::string contents;
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + path);
    }
    int length = 0;
    file.seekg(0, std::ios::end);
    length = file.tellg();
    contents.resize(length);
    file.seekg(0, std::ios::beg);
    file.read(&contents[0], length);
    file.close();
// std::cout << contents;
    return contents;

}
