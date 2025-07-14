#include <iostream>
#include <iomanip>
#include "Tree.h"

using namespace std;

void printTree(Node* root, string prefix, bool isLast) {
    if (!root) return;

    cout << prefix;
    cout << (isLast ? "|___ " : "|--- ");

    cout << fixed << setprecision(2);
    if (root->character != '\0')
        cout << root->character << " (" << root->weight << ")\n";
    else
        cout << "* (" << root->weight << ")\n";

    string newPrefix = prefix + (isLast ? "    " : "|   ");

    bool hasLeft = root->left != nullptr;
    bool hasRight = root->right != nullptr;

    if (hasLeft || hasRight) {
        if (hasLeft)
            printTree(root->left, newPrefix, !hasRight);
        if (hasRight)
            printTree(root->right, newPrefix, true);
    }
}
