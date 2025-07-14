#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include "Node.h"

using namespace std;

/**
 * Computes and prints Huffman coding statistics.
 * @param data Vector of <character, weight> pairs (frequency or probability)
 * @param codeMap Map assigning each character its binary Huffman code
 * @param mode Mode of operation: 'F' for frequency, 'P' for probability
 * @param fixedLength Fixed-length code size (used to evaluate efficiency)
 */
void calculateStatistics(
    const vector<pair<char, double>>& data,
    const unordered_map<char, string>& codeMap,
    char mode,
    int fixedLength);

/**
 * Builds a Huffman tree from a map of weights.
 * @param weightMap Map of characters and their weights (frequency or probability)
 * @return Pointer to the root node of the created Huffman tree
 */
Node* buildHuffmanTree(const unordered_map<char, double>& weightMap);

/**
 * Recursively generates Huffman codes for each character.
 * @param root Pointer to the current node of the tree
 * @param code Currently built binary prefix
 * @param codeMap Map where the final character codes will be stored
 */
void buildCodes(Node* root, const string& code, unordered_map<char, string>& codeMap);

#endif // HUFFMAN_H
