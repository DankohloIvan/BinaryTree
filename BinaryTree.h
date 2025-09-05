#pragma once

#include <iostream>

class Violation {
public:
    const char* info;
    Violation* next;

    Violation(const char* i) : info(i), next(nullptr) {}
};


class Node {
public:
    int number;
    Violation* violations;
    Node* left; 
    Node* right; 

    Node(int n, const char* firstViolation)
        : number(n), violations(new Violation(firstViolation)), left(nullptr), right(nullptr) {
    }

    void addViolation(const char* violation) {
        Violation* newViolation = new Violation(violation);
        newViolation->next = violations;
        violations = newViolation;
    }

    void printViolations(Violation* head) {
        Violation* violation = head;
        while (violation) {
            std::cout << violation->info;
            if (violation->next) {
                std::cout << ", ";
            }
            violation = violation->next;
        }
        std::cout << std::endl;
    }
};


class BinaryTree {
public:
    Node* insert(Node* root, int number, const char* violation);
    void print(Node* root);
    void printByNumber(Node* root, int number);
    void printByRange(Node* root, int low, int high);
};