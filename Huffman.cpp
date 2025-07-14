#include "Huffman.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include "Exceptions.h"

using namespace std;
using namespace MyRuntimeExceptions;

void calculateStatistics(const vector<pair<char, double>>& data,
    const unordered_map<char, string>& codeMap,
    char mode,
    int fixedLength) {
    double total = 0;
    double entropy = 0;

    cout << fixed << setprecision(4);
    cout << "\nChar  | Weight     | Huffman Code   | Length   | ";
    if (mode == 'F' || mode == 'f') cout << "Bits Used   | Efficiency [%]";
    cout << "\n" << string(80, '-') << "\n";

    for (const auto& pair : data) {
        char ch = pair.first;
        double weight = pair.second;

        if (codeMap.find(ch) == codeMap.end())
            throw HuffmanCodeException("No Huffman code found for character: " + string(1, ch));

        const string& code = codeMap.at(ch);
        int length = code.length();
        double bitsUsed = weight * length;
        total += bitsUsed;

        if ((mode == 'P' || mode == 'p') && weight > 0)
            entropy += weight * log2(1.0 / weight);

        cout << " " << ch << "    | "
            << setw(10) << weight << " | "
            << setw(15) << code << " | "
            << setw(8) << length;

        if (mode == 'F' || mode == 'f') {
            double efficiency = 100.0 * (1.0 - ((double)length / fixedLength));
            cout << " | " << setw(10) << bitsUsed
                << " | " << setw(6) << setprecision(2) << efficiency << "\n";
        }

        cout << "\n";
    }

    if (mode == 'F' || mode == 'f') {
        double totalWeights = 0;
        for (const auto& p : data) totalWeights += p.second;
        double fixedBits = totalWeights * fixedLength;
        cout << "\nTotal Huffman bits: " << total;
        cout << "\nTotal bits with fixed length (" << fixedLength << " bits): " << fixedBits;
        cout << "\nOverall compression efficiency: " << setprecision(2)
            << 100.0 * (1.0 - total / fixedBits) << " %\n";
    }
    else {
        cout << "\nAverage code length: " << total << " bits";
        cout << "\nSource entropy: " << entropy << " bits";
        cout << "\nCoding efficiency: " << setprecision(2)
            << 100.0 * (1 - ((total - entropy) / total)) << " %\n";
    }
}

Node* buildHuffmanTree(const unordered_map<char, double>& weightMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (const auto& p : weightMap)
        pq.push(new Node(p.first, p.second));

    if (pq.empty())
        throw HuffmanBuildException("Empty queue – no input data.");

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* newNode = new Node('\0', left->weight + right->weight);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    return pq.top();
}

void buildCodes(Node* root, const string& code, unordered_map<char, string>& codeMap) {
    if (!root) return;
    if (!root->left && !root->right) {
        if (codeMap.count(root->character))
            throw HuffmanCodeException("Duplicate code for character: " + string(1, root->character));
        codeMap[root->character] = code;
    }
    buildCodes(root->left, code + "0", codeMap);
    buildCodes(root->right, code + "1", codeMap);
}
