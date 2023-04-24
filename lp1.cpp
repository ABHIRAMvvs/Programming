#include <iostream>
#include  <queue>
using namespace std;

enum Color {RED, BLACK};

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
};

class RedBlackTree {
private:
    Node* root;

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != NULL)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == NULL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != NULL)
            y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == NULL)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node* z) {
        while (z != root && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;
                if (y != NULL && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else {
                Node* y = z->parent->parent->left;
                if (y != NULL && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void inorderTraversal(Node* node) {
        if (node == NULL)
            return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void levelOrderTraversal(Node* node) {
        if (node == NULL)
            return;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            int level_size = q.size();
            for (int i = 0; i < level_size; i++) {
                Node* current = q.front();
                q.pop();
                cout << current->data << " ";
                if (current->left != NULL)
                   

            q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
        }
    }
}

public:
RedBlackTree() {
root = NULL;
}
void insert(int data) {
    Node* z = new Node;
    z->data = data;
    z->color = RED;
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;
    Node* y = NULL;
    Node* x = root;
    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (y == NULL)
        root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;
    fixInsert(z);
}

void printInorderTraversal() {
    inorderTraversal(root);
    cout << endl;
}

void printLevelOrderTraversal() {
    levelOrderTraversal(root);
    cout << endl;
}

};

int main() {
RedBlackTree tree;
int n;
cout << "Enter number of nodes in the red-black tree: ";
cin >> n;
cout << "Enter the values: ";
for (int i = 0; i < n; i++) {
int value;
cin >> value;
tree.insert(value);
}
cout << "Values of nodes in ascending order:" << endl;
tree.printInorderTraversal();
cout << "Values of nodes at each level:" << endl;
tree.printLevelOrderTraversal();
return 0;
}