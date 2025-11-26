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

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* searchNonRecursive(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
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

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    Node* result1 = searchRecursive(root, key);
    Node* result2 = searchNonRecursive(root, key);

    if (result1 != nullptr)
        cout << "Found (Recursive)\n";
    else
        cout << "Not Found (Recursive)\n";

    if (result2 != nullptr)
        cout << "Found (Non-Recursive)\n";
    else
        cout << "Not Found (Non-Recursive)\n";

    return 0;
}
