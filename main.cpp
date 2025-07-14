#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <cmath>
#include "Node.h"
#include "Huffman.h"
#include "Tree.h"
#include "Exceptions.h"

using namespace std;
using namespace MyRuntimeExceptions;

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    try {
        string filename;
        char mode;

        cout << "Enter the name of the data file (e.g data.txt): ";
        cin >> filename;
        cout << "Are the values (F)requencies or (P)robabilities? [F/P]: ";
        cin >> mode;

        // Validate mode
        if (!(mode == 'F' || mode == 'f' || mode == 'P' || mode == 'p')) {
            throw invalid_argument("Invalid mode. Please enter only 'F' or 'P'.");
        }

        ifstream file;
        openIFileStream(filename, file);

        vector<pair<char, double>> data;
        unordered_map<char, double> weightMap;
        char character;
        double value;

        while (file >> character >> value) {
            if (!isalpha(character)) {
                throw runtime_error("Invalid character in file: " + string(1, character));
            }
            if (value <= 0) {
                throw runtime_error("Value must be positive: " + to_string(value));
            }

            bool isInteger = floor(value) == value;

            if ((mode == 'F' || mode == 'f') && !isInteger) {
                throw invalid_argument("In 'F' (frequency) mode, values must be integers. Error: " + to_string(value));
            }

            if ((mode == 'P' || mode == 'p') && isInteger) {
                throw invalid_argument("In 'P' (probability) mode, values must be fractional. Error: " + to_string(value));
            }

            data.push_back({ character, value });
            weightMap[character] = value;
        }
        file.close();

        if (data.empty()) {
            throw runtime_error("The file contains no input data.");
        }

        Node* root = buildHuffmanTree(weightMap);

        unordered_map<char, string> codeMap;
        buildCodes(root, "", codeMap);

        calculateStatistics(data, codeMap, mode, 4);

        cout << "\nHUFFMAN TREE STRUCTURE:\n";
        printTree(root);
    }
    catch (const FileOpenException& e) {
        cerr << "File open error: " << e.what() << endl;
        return 1;
    }
    catch (const invalid_argument& e) {
        cerr << "Input error: " << e.what() << endl;
        return 1;
    }
    catch (const runtime_error& e) {
        cerr << "Runtime error: " << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "An unexpected error occurred." << endl;
        return 1;
    }

    return 0;
}
