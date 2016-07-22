#include "shader.hpp"

#include <fstream>
// TODO: Include OpenGL things

std::string readFile(const char *filePath) {
    std::ifstream infile(filePath);
    std::string fileContents((std::istreambuf_iterator<char>(infile)),
                             (std::istreambuf_iterator<char>()));
    return fileContents;
}

// TODO: OpenGL things
