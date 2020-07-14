#include <iostream>
#include <climits>
using namespace std;

// Data structure to store a Binary Search Tree node
struct Node {
    int data;
    Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}

// Function to perform in-order traversal of the tree
void inorder(Node* root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Recursive function to insert an key into BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node an return it
    if (root == nullptr)
        return newNode(key);

    // if given key is less than the root node, recur for left subtree
    if (key < root->data)
        root->left = insert(root->left, key);

    // if given key is more than the root node, recur for right subtree
    else
        root->right = insert(root->right, key);

    return root;
}

// Recursive function to fix a binary tree that is only one swap
// away from becoming a BST. Here, prev is previous processed node in
// in-order traversal and x, y stores node to be swapped (if any)
void correctBST(Node* root, Node* &x, Node* &y, Node* &prev)
{
    // base case
    if(root == nullptr)
        return;

    // recur for left subtree
    correctBST(root->left, x, y, prev);

    // if current node is less than the previous node
    if (root->data < prev->data)
    {
        // if this is first occurrence, update x and y to previous node
        // and current node respectively
        if (x == nullptr)
            x = prev;

        // if this is second occurrence, update y to current node
        y = root;

    }

    // update previous node and recur for right subtree
    prev = root;
    correctBST(root->right, x, y, prev);
}

// Fix given binary tree that is only one swap away from becoming a BST
void correctBST(Node* root)
{
    // x and y stores node to be swapped
    Node *x = nullptr, *y = nullptr;

    // stores previous processed node in in-order traversal
    // initialize it by minus infinity
    Node *prev = newNode(INT_MIN);

    // fix the binary tree
    correctBST(root, x, y, prev);

    // swap the nodes
    if (x && y)
        swap(x->data, y->data);
}

// main function
int main()
{
    Node* root = nullptr;
	/* Construct below BST
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
	*/

    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
    int n = sizeof(keys)/sizeof(keys[0]);

    for (int key : keys)
        root = insert(root, key);

    // swap any two nodes values
    swap(root->left->data, root->right->right->data);

    // fix the BST
    correctBST(root);

    // print the BST after fixing it
    inorder(root);

    return 0;
}