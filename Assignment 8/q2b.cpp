#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);
    return root;
}

Node* findMaxRecursive(Node* root) {
    if (root == nullptr || root->right == nullptr)
        return root;
    return findMaxRecursive(root->right);
}

Node* findMaxNonRecursive(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}

int main() {
    Node* root = nullptr;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    Node* maxR = findMaxRecursive(root);
    Node* maxNR = findMaxNonRecursive(root);

    cout << "Maximum (Recursive): " << maxR->data << endl;
    cout << "Maximum (Non-Recursive): " << maxNR->data << endl;

    return 0;
}
