#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

class Node {
    public:
        Node* lchild;
        Node* rchild;
        int data;
        int height;

        Node(int val) {
            lchild = rchild = nullptr;
            data = val;
            height = 1;
        }
};

class AVL{
    public:
        Node* root;

        AVL(){
            root = nullptr;
        }

        int Height(Node* t){
            int hl, hr;
            hl = t && t->lchild ? t->lchild->height : 0;
            hr = t && t->rchild ? t->rchild->height : 0;
            return hl > hr ? hl + 1 : hr + 1;
        }

        int BalanceFactor(Node* t){
            int hl, hr;
            hl = t && t->lchild ? t->lchild->height : 0;
            hr = t && t->rchild ? t->rchild->height : 0;
            return hl - hr;
        }

        Node* LLRotation(Node* t){
            Node* tl = t->lchild;
            Node* tlr = tl->rchild;

            tl->rchild = t;
            t->lchild = tlr;

            t->height = Height(t);
            tl->height = Height(tl);

            if(t == root){
                root = tl;
            }
            return tl;
        }

        Node* RRRotation(Node* t){
            Node* tr = t->rchild;
            Node* trl = tr->lchild;

            tr->lchild = t;
            t->rchild = trl;

            t->height = Height(t);
            tr->height = Height(tr);

            if(t == root){
                root = tr;
            }

            return tr;
        }

        Node* LRRotation(Node* t){
            Node* tl = t->lchild;
            Node* tlr = tl->rchild;

            tl->rchild = tlr->lchild;
            tlr->lchild = tl;

            tl->height = Height(tl);
            tlr->height = Height(tlr);

            t->lchild = tlr->rchild;
            tlr->rchild = t;

            t->height = Height(t);
            tlr->height = Height(tlr);

            if(t == root){
                root = tlr;
            }

            return tlr;
        }

        Node* RLRotation(Node* t){
            Node* tr = t->rchild;
            Node* trl = tr->lchild;

            tr->lchild = trl->rchild;
            trl->rchild = tr;

            tr->height = Height(tr);
            trl->height = Height(trl);

            t->rchild = trl->lchild;
            trl->lchild = t;

            t->height = Height(t);
            trl->height = Height(trl);

            if(t == root){
                root = trl;
            }

            return trl;
        }

        Node* Insert(int key, Node* t){
            if(t == nullptr){
                Node* a = new Node(key);
                return a;
            }
            if(key < t->data){
                t->lchild = Insert(key, t->lchild);
            }else if(key > t->data){
                t->rchild = Insert(key, t->rchild);
            }
            t->height = Height(t);

            if(BalanceFactor(t) == 2 && BalanceFactor(t->lchild) == 1){
                return LLRotation(t);
            }else if(BalanceFactor(t) == 2 && BalanceFactor(t->lchild) == -1){
                return LRRotation(t);
            }else if(BalanceFactor(t) == -2 && BalanceFactor(t->rchild) == -1){
                return RRRotation(t);
            }else if(BalanceFactor(t) == -2 && BalanceFactor(t->rchild) == 1){
                return RLRotation(t);
            }

            return t;
        }

        void Insert(int key){
            root = Insert(key, root);
        };

};

int main() {
    AVL a;

    a.Insert(30);
    a.Insert(20);
    a.Insert(10);
    a.Insert(40);
    a.Insert(50);
    a.Insert(25);
    a.Insert(28);

    return 0;
}