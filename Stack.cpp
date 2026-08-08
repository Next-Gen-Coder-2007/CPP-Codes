#include <iostream>
using namespace std;

class StackArray {
    private:
        int size;
        int top;
        int *S;
    public:
        StackArray(int size) {
            this->size = size;
            top = -1;
            S = new int[this->size];
        }
        void Display() {
            cout << "Displaying Stack:\n";
            for(int i = top; i >= 0; i--){
                cout << S[i] << "\n";
            }
        }
        void Push(int x){
            if(top == size-1){
                cout << "Stack overflow\n";
            }
            else{
                top++;
                S[top] = x;
            }
        }
        int Pop(){
            int x = -1;
            if(top == -1){
                cout << "Stack underflow\n";
            }
            else{
                x = S[top--];
            }
            return x;
        }
        int Peek(int index){
            int x = -1;
            if(top-index+1 < 0){
                cout << "Invalid Index\n";
            }
            x = S[top-index + 1];
            return x;
        }
        int isEmpty(){
            if(top == -1){
                return 1;
            }
            return 0;
        }
        int isFull(){
            if(top == size-1){
                return 1;
            }
            return 0;
        }
        int Top(){
            if(!isEmpty()){
                return S[top];
            }
            return -1;
        }
        ~StackArray(){
            delete[] S;
        }
};

class Node{
    public:
        int data;
        Node* next;
};

class StackLinkedList {
    private:
        Node* top;
    public:
        StackLinkedList(){
            top = nullptr;
        }
        void Push(int x){
            Node* t = new Node;
            if(t == nullptr){
                cout << "Stack is Full\n";
            }
            else{
                t->data = x;
                t->next = top;
                top = t;
            }
        }
        int Pop(){
            int x = -1;
            if(top == nullptr){
                cout << "Stack is Empty\n";
            }
            else{
                x = top->data;
                Node* t = top;
                top = top->next;
                delete t;
            }
            return x;
        }
        void Display(){
            Node* p = top;
            cout << "Displaying Stack:\n";
            while(p != nullptr){
                cout << p->data << endl;
                p = p->next;
            }
        }
};

int main() {
    // StackArray s(5); 
    StackLinkedList s;

    s.Push(1);
    s.Push(2);
    s.Push(5);
    s.Push(3);

    s.Display();

    s.Pop();
    s.Display();
    // cout << s.Peek(2);

    return 0;
}