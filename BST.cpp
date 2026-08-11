#include <iostream>
using namespace std;

class Node{
    public:
        Node* leftChild;
        Node* rightChild;
        int data;

        Node(int val){
            this->leftChild = this->rightChild = nullptr;
            this->data = val;
        }
};

class BST{
    private:
        Node* root;
    public:
        BST(){
            root = nullptr;
        }
        void Insert(int key){
            Node* t = root;
            Node* r = nullptr;
            Node* p;
            if(root == nullptr){
                p = new Node(key);
                root = p;
                return;
            }
            while(t != nullptr){
                r = t;
                if(key < t->data){
                    t = t->leftChild;
                }else if(key > t->data){
                    t = t->rightChild;
                }else{
                    return;
                }
            }
            p = new Node(key);
            if(key < r->data){
                r->leftChild = p;
            }else{
                r->rightChild = p;
            }
        }

        int Height(Node* t){
            if(t == nullptr){
                return 0;
            }
            return Height(t->leftChild) > Height(t->rightChild) ? Height(t->leftChild) + 1  : Height(t->rightChild) + 1;
        }

        Node* InorderPredecessor(Node* t){
            while(t && t->rightChild != nullptr){
                t = t->rightChild;
            }
            return t;
        }

        Node* InorderSuccessor(Node* t){
            while(t && t->leftChild != nullptr){
                t = t->leftChild;
            }
            return t;
        }

        void Inorder(Node* t){
            if(t){
                Inorder(t->leftChild);
                cout << t->data << " ";
                Inorder(t->rightChild);
            }
        }

        Node* Search(int key){
            Node* t = root;
            while(t != nullptr){
                if(key == t->data){
                    return t;
                }else if(key < t->data){
                    t = t->leftChild;
                }else{
                    t = t->rightChild;
                }
            }
            return nullptr;
        }

        Node* RInsert(int key, Node* t){
            if(t == nullptr){
                Node* a = new Node(key);
                return a;
            }
            if(key < t->data){
                t->leftChild = RInsert(key, t->leftChild);
            }else if(key > t->data){
                t->rightChild = RInsert(key, t->rightChild);
            }
            return t;
        }

        Node* Delete(Node* t, int key){
            if(t == nullptr){
                return nullptr;
            }

            if(key < t->data){
                t->leftChild = Delete(t->leftChild, key);
            }
            else if(key > t->data){
                t->rightChild = Delete(t->rightChild, key);
            }
            else{
                if(t->leftChild == nullptr && t->rightChild == nullptr){
                    delete t;
                    return nullptr;
                }

                if(t->leftChild == nullptr){
                    Node* temp = t->rightChild;
                    delete t;
                    return temp;
                }

                if(t->rightChild == nullptr){
                    Node* temp = t->leftChild;
                    delete t;
                    return temp;
                }

                if(Height(t->leftChild) > Height(t->rightChild)){
                    Node* s = InorderPredecessor(t->leftChild);
                    t->data = s->data;
                    t->leftChild = Delete(t->leftChild, s->data);
                }
                else{
                    Node* s = InorderSuccessor(t->rightChild);
                    t->data = s->data;
                    t->rightChild = Delete(t->rightChild, s->data);
                }
            }
            return t;
        }

        void RInsert(int key){
            root = RInsert(key, root);
        }

        void Delete(int key){
            Delete(root, key);
        }

        void Inorder(){
            Inorder(root);
        }
};

int main(){
    BST b;
    b.Insert(30);
    b.Insert(20);
    b.Insert(10);
    b.Insert(40);
    b.Insert(50);
    b.RInsert(80);

    b.Inorder();

    cout << endl;

    cout << b.Search(30)->data << endl;

    b.Delete(80);

    b.Inorder();
}