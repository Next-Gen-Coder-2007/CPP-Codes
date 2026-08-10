#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        Node* left;
        Node* right;
        int data;

        Node(int value) {
            data = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinaryTree {
private:
    Node* root;
public:
    BinaryTree() {
        root = nullptr;
    }

    void create(int arr[], int n) {
        if (n == 0 || arr[0] == -1) {
            root = nullptr;
            return;
        }

        root = new Node(arr[0]);

        queue<Node*> q;
        q.push(root);

        int i = 1;

        while (i < n) {
            Node* current = q.front();
            q.pop();

            if (i < n && arr[i] != -1) {
                current->left = new Node(arr[i]);
                q.push(current->left);
            }
            i++;

            if (i < n && arr[i] != -1) {
                current->right = new Node(arr[i]);
                q.push(current->right);
            }
            i++;
        }
    }

    void preorder(Node* p) {
        if(p == nullptr)
            return;

        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }

    void inorder(Node* p) {
        if (p == nullptr)
            return;

        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }

    void postorder(Node* p) {
        if (p == nullptr)
            return;

        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }

    void levelorder() {
        if (root == nullptr)
            return;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }
    }

    void preorder() {
        preorder(root);
    }

    void inorder() {
        inorder(root);
    }

    void postorder() {
        postorder(root);
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    BinaryTree tree;

    tree.create(arr, n);

    cout << "Preorder: ";
    tree.preorder();
    cout << endl;

    cout << "Inorder: ";
    tree.inorder();
    cout << endl;

    cout << "Postorder: ";
    tree.postorder();
    cout << endl;

    cout << "Levelorder: ";
    tree.levelorder();
    cout << endl;

    return 0;
}