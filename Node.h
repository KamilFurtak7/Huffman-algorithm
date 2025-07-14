#ifndef NODE_H
#define NODE_H

// Structure representing a node in the Huffman tree
struct Node {
    char character;        // The character (character)
    double weight;      // Weight (frequency or probability)
    Node* left;         // Pointer to the left child
    Node* right;        // Pointer to the right child

    Node(char s, double w) : character(s), weight(w), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->weight > b->weight;
    }
};

#endif
