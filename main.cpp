#include "BinaryTree.h"

int main() {
    BinaryTree dataBase;
    Node* root = nullptr;
    root = dataBase.insert(root, 50, "Red Light");
    root = dataBase.insert(root, 70, "Speeding");
    root = dataBase.insert(root, 70, "Parking in a fenced area");
    root = dataBase.insert(root, 60, "Parking in a fenced area");
    root = dataBase.insert(root, 90, "Talking on the phone while driving");
    
    dataBase.print(root);

    //dataBase.printByNumber(root, 70);

    //dataBase.printByRange(root, 50, 70);
    return 0;
}
