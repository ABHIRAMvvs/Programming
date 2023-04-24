#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    char color;
    Node* left;
    Node* right;
    Node(int value) {
        val = value;
        color = 'R';
        left = nullptr;
        right = nullptr;
    }
};

class RedBlackTree {
    Node* root;
    // helper function to create new node as per rules of red black tree
    Node* createNode(int val) {
        Node* newNode = new Node(val);
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    void LLRotation(Node* &root) {
        Node* temp = root->left;
        root->left = temp->right;
        temp->right = root;
        root = temp;
    }
    void RRRotation(Node* &root) {
        Node* temp = root->right;
        root->right = temp->left;
        temp->left = root;
        root = temp;
    }
    void LRRotation(Node* &root) {
        RRRotation(root->left);
        LLRotation(root);
    }
    void RLRotation(Node* &root) {
        LLRotation(root->right);
        RRRotation(root);
    }
    // helper function to insert new node and keep color at appropriate position
    void insert(Node* &root, int val) {
        if (root == nullptr) {
            root = createNode(val);
            if (root == nullptr) {
                cout << "Error: Unable to allocate memory!!" << endl;
                return;
            }
            else {
                root->color = 'B';
                return;
            }
        }
        else if (val < root->val) {
            insert(root->left, val);
            if (root->left != nullptr && root->left->color == 'R' && root->color == 'R') {
                if (root->left->left != nullptr && root->left->left->color == 'R') {
                    root->left->color = 'B';
                    root->color = 'R';
                    LLRotation(root);
                }
                else if (root->left->right != nullptr && root->left->right->color == 'R') {
                    root->left->right->color = 'B';
                    root->color = 'R';
                    LRRotation(root);
                }
            }
        }
        else {
            insert(root->right, val);
            if (root->right != nullptr && root->right->color == 'R' && root->color == 'R') {
                if (root->right->right != nullptr && root->right->right->color == 'R') {
                    root->right->color = 'B';
                    root->color = 'R';
                    RRRotation(root);
                }
                else if (root->right->left != nullptr && root->right->left->color == 'R') {
                    root->right->left->color = 'B';
                    root->color = 'R';
                    RLRotation(root);
                }
            }
        }
    }
    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->val << " ";
            inorder(root->right);
        }
    }
    // void levelorder(Node* root) {
    //     if (root == nullptr) {
    //         return;
    //     }
    //     queue<Node*> q;
    //     q.push(root);
    //     while (!q.empty()) {
    //         int n = q.size();
    //         for (int i = 0; i < n; i++) {
    //             Node* temp = q.front();
    //             q.pop();
    //             cout << temp->val << " ";
    //             if (temp->left != nullptr) {
    //                 q.push(temp->left);
    //             }
    //             if (temp->right != nullptr) {
    //                 q.push(temp->right);
    //             }
    //         }
    //     }
    // }
    void printLevelOrder() {
        if (root == NULL) {
            return;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node *node = q.front();
                q.pop();
                cout << node->value << " ";
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            cout << endl;
        }
    }
public:
    RedBlackTree() {
        root = nullptr;
    }
    void insert(int val) {
        insert(root, val);
    }
    void inorder() {
        inorder(root);
    }
    void printLevelOrder() {
        printLevelOrder(root);
    }
};

int main() {
    RedBlackTree rbt;
    int n;
    cout << "Enter number of nodes in the red black tree: ";
    cin >> n;
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        rbt.insert(val);
    }
    cout << "Values of nodes in ascending order: ";
    rbt.inorder();
    cout << "\nValues of nodes at each level: ";
    rbt.printLevelOrder();
    cout << endl;
    return 0;
}
