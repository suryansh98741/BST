#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* t = new Node;
    t->data = val;
    t->left = t->right = NULL;
    return t;
}

Node* insert(Node* root, int val) {
    if(root == NULL) return newNode(val);
    if(val < root->data) root->left = insert(root->left, val);
    else if(val > root->data) root->right = insert(root->right, val);
    return root;
}

// (a) Search Recursive
Node* searchRec(Node* root, int key) {
    if(root == NULL || root->data == key) return root;
    if(key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// (a) Search Non-Recursive
Node* searchNonRec(Node* root, int key) {
    while(root != NULL) {
        if(key == root->data) return root;
        else if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// (b) Maximum element
Node* maxNode(Node* root) {
    while(root && root->right) root = root->right;
    return root;
}

// (c) Minimum element
Node* minNode(Node* root) {
    while(root && root->left) root = root->left;
    return root;
}

// (d) In-order successor
Node* inorderSuccessor(Node* root, int key) {
    Node* curr = searchRec(root, key);
    if(curr == NULL) return NULL;

    if(curr->right) return minNode(curr->right);

    Node* succ = NULL;
    while(root) {
        if(key < root->data) {
            succ = root;
            root = root->left;
        } else if(key > root->data)
            root = root->right;
        else break;
    }
    return succ;
}

// (e) In-order predecessor
Node* inorderPredecessor(Node* root, int key) {
    Node* curr = searchRec(root, key);
    if(curr == NULL) return NULL;

    if(curr->left) return maxNode(curr->left);

    Node* pred = NULL;
    while(root) {
        if(key > root->data) {
            pred = root;
            root = root->right;
        } else if(key < root->data)
            root = root->left;
        else break;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Max: " << maxNode(root)->data << endl;
    cout << "Min: " << minNode(root)->data << endl;
}

