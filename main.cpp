#include <iostream>

struct Violation {
    const char* info;
    Violation* next;
    Violation(const char*  i) : info(i), next(nullptr) {}
};

struct Node {
    int carNumber;
    Violation* violations;
    Node* left;
    Node* right;
    Node(int num, const char* v) : carNumber(num), violations(new Violation(v)), left(nullptr), right(nullptr) {}
};

void addViolation(Violation*& head, const char* info) {
    Violation* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new Violation(info);
}

Node* insert(Node* root, int carNumber, const char* violation) {
    if (!root) {
        return new Node(carNumber, violation);
    }
    if (carNumber < root->carNumber) {
        root->left = insert(root->left, carNumber, violation);
    }
    else if (carNumber > root->carNumber){
        root->right = insert(root->right, carNumber, violation); 
    }
    else {
        addViolation(root->violations, violation);
    }
    return root;
}

void printViolations(Violation* head) {
    while (head) {
        std::cout << "\t" << head->info << std::endl;
        head = head->next;
    }
}

void printAll(Node* root) {
    if (!root) {
        return;
    }
    printAll(root->left);
    std::cout << "Car " << root->carNumber << ":\n";
    printViolations(root->violations);
    printAll(root->right);
}

void printByNumber(Node* root, int carNumber) {
    if (!root) {
        return;
    }
    if (carNumber < root->carNumber) {
        printByNumber(root->left, carNumber);
    } 
    else if (carNumber > root->carNumber) {
        printByNumber(root->right, carNumber);
    }
    else {
        std::cout << "Car " << root->carNumber << ":\n";
        printViolations(root->violations);
    }
}

void printByRange(Node* root, int low, int high) {
    if (!root) {
        return ;
    }
    if (low < root->carNumber) {
        printByRange(root->left, low, high);
    }
    if (root->carNumber >= low && root->carNumber <= high) {
        std::cout << "Car " << root->carNumber << ":\n";
        printViolations(root->violations);
    }
    if (high > root->carNumber) {
        printByRange(root->right, low, high);
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 1455, "Speeding");
    root = insert(root, 8888, "Using phone while driving");
    root = insert(root, 2142, "parking at a pedestrian crossing");
    root = insert(root, 5858, "Red Light");

    std::cout << "Database:\n";
    printAll(root);

    std::cout << "\nSearch by number (2142):\n";
    printByNumber(root, 2142);

    std::cout << "\nSearch by range (1000-5000):\n";
    printByRange(root, 1000, 5858);

    return 0;
}
