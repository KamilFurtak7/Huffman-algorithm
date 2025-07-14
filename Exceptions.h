#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <fstream>
#include <string>

namespace MyRuntimeExceptions {

    // Custom exception for file open errors
    class FileOpenException : public std::runtime_error {
    public:
        FileOpenException();
        FileOpenException(std::string msg);
    };

    // Custom exception for errors during Huffman tree construction
    class HuffmanBuildException : public std::runtime_error {
    public:
        HuffmanBuildException(std::string msg);
    };

    // Custom exception for code generation errors
    class HuffmanCodeException : public std::runtime_error {
    public:
        HuffmanCodeException(std::string msg);
    };

    // Helper function for opening input file streams with error handling
    void openIFileStream(std::string filename, std::ifstream& in);
}

#endif
