#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int v) {
    Node* t = new Node;
    t->data = v;
    t->left = t->right = NULL;
    return t;
}

Node* insert(Node* root, int v) {
    if(root == NULL) return newNode(v);
    if(v < root->data) root->left = insert(root->left, v);
    else if(v > root->data) root->right = insert(root->right, v);
    return root;
}

Node* minNode(Node* r) {
    while(r->left) r = r->left;
    return r;
}

Node* deleteNode(Node* root, int key) {
    if(root == NULL) return NULL;

    if(key < root->data) root->left = deleteNode(root->left, key);
    else if(key > root->data) root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL) {
            Node* t = root->right;
            delete root;
            return t;
        }
        else if(root->right == NULL) {
            Node* t = root->left;
            delete root;
            return t;
        }
        Node* succ = minNode(root->right);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if(root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if(root == NULL) return 0;
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    root = deleteNode(root, 30);

    cout << "After deletion, Max Depth: " << maxDepth(root) << endl;
}

