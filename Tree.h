#ifndef TREE_H
#define TREE_H

#include <string>
#include "Node.h"

using namespace std;

/**
 * Recursively prints the structure of the Huffman tree in a visual format.
 * @param root Pointer to the root (current node)
 * @param prefix String used for indentation formatting
 * @param isLast Flag indicating if the node is the last child
 */
void printTree(Node* root, string prefix = "", bool isLast = true);

#endif