#include "Exceptions.h"

using namespace MyRuntimeExceptions;

FileOpenException::FileOpenException()
    : std::runtime_error("Unable to open file") {}

FileOpenException::FileOpenException(std::string msg)
    : std::runtime_error(msg) {}

HuffmanBuildException::HuffmanBuildException(std::string msg)
    : std::runtime_error(msg) {}

HuffmanCodeException::HuffmanCodeException(std::string msg)
    : std::runtime_error(msg) {}

void MyRuntimeExceptions::openIFileStream(std::string filename, std::ifstream& in) {
    in.open(filename);
    if (!in.is_open()) {
        throw FileOpenException("Unable to open file: " + filename);
    }
}
