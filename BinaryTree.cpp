#include "BinaryTree.h"

Node* BinaryTree::insert(Node* root, int number, const char* violation)
{
    if (!root) {
        return new Node(number, violation);
    }

    if (number == root->number) {
        root->addViolation(violation);
    }
    else if (number < root->number) {
        root->left = insert(root->left, number, violation);
    }
    else {
        root->right = insert(root->right, number, violation);
    }

    return root;
}

void BinaryTree::print(Node* root)
{
    if (!root) {
        return;
    }

    print(root->left);

    std::cout << "Car " << root->number << ": ";
    root->printViolations(root->violations);

    print(root->right);
}

void BinaryTree::printByNumber(Node* root, int number) {
    if (!root) {
        return;
    }

    if (number < root->number) {
        printByNumber(root->left, number);
    }
    else if (number > root->number) {
        printByNumber(root->right, number);
    }
    else {
        std::cout << "Car " << root->number << ":\n";
        root->printViolations(root->violations);
    }
}

void BinaryTree::printByRange(Node* root, int low, int high)
{
    if (!root) {
        return;
    }

    if (low < root->number) {
        printByRange(root->left, low, high);
    }

    if (root->number >= low && root->number <= high) {
        std::cout << "Car " << root->number << ":\n";
        root->printViolations(root->violations);
    }

    if (high > root->number) {
        printByRange(root->right, low, high);
    }
}
