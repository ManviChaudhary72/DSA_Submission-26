
#include<iostream>
using namespace std;

class Node {
public:
    int val;
    int height;
    Node* left;
    Node* right;

    Node(int val) {  
        this->val = val;
        height = 0;
        left = nullptr;
        right = nullptr;
    }
};

// Get height of a node
int getHeight(Node* node) {
    if (node == nullptr)
        return -1;

    return node->height;
}

// Calculate balance factor
int getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;

    return getHeight(node->left) -
           getHeight(node->right);
}

// Right rotation
Node* rightRotate(Node* r) {
    Node* y = r->left;
    Node* temp = y->right;

    y->right = r;
    r->left = temp;

    r->height = 1 + max(getHeight(r->left),
                        getHeight(r->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

// Left rotation
Node* leftRotate(Node* r) {
    Node* y = r->right;
    Node* temp = y->left;

    y->left = r;
    r->right = temp;

    r->height = 1 + max(getHeight(r->left),
                        getHeight(r->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

// AVL insertion
Node* insert(Node* root, int value) {
    // Normal BST insertion
    if (root == nullptr)
        return new Node(value);

    if (value < root->val)
        root->left = insert(root->left, value);

    else if (value > root->val)
        root->right = insert(root->right, value);

    else
        return root;  // Duplicate values not allowed

    // Update height
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    // Find balance factor
    int bf = getBalanceFactor(root);

    // LL Case
    if (bf > 1 && value < root->left->val)
        return rightRotate(root);

    // RR Case
    if (bf < -1 && value > root->right->val)
        return leftRotate(root);

    // LR Case
    if (bf > 1 && value > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (bf < -1 && value < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Create AVL tree
void createBT(Node*& root) {
    cout << "Enter the no. of nodes to insert: ";
    int n;
    cin >> n;

    int value;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;

        root = insert(root, value);
    }
}


// Inorder display
void display(Node* root) {
    if (root == nullptr)
        return;

    display(root->left);
    cout << root->val << " ";
    display(root->right);
}

int main() {
    Node* root = new Node(10);

    createBT(root);

    cout << "\nInorder traversal: ";
    display(root);

   

    return 0;
}
