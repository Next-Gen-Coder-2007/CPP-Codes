#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node<T> *next;
        Node(int n){
            this->data = n;
            this->next = nullptr;
        }
        ~Node(){}
};

template <typename T>
class LinkedList {
    private:
        Node<T> *head;
        int length;
        void DispRec(Node<T> *temp){
            if(temp != nullptr){
                cout << temp->data << " ";
                DispRec(temp->next);
            }
        }
    public:
        LinkedList(){
            head = nullptr;
            length = 0;
        }
        void Add(int n){
            Node<T> *newNode = new Node<T>(n);
            if(head == nullptr){
                head = newNode;
            } else{
                Node<T> *temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            length++;
        }
        void Display(){
            DispRec(this->head);
        }
        T Length(){
            return length;
        }
        T Sum(){
            Node<T> *temp = head;
            T sum = 0;
            while(temp != nullptr){
                sum += temp->data;
                temp = temp->next;
            }
            return sum;
        }
        T Max(){
            Node<T> *temp = head;
            T mx = temp->data;
            while(temp != nullptr){
                mx = max(mx, temp->data);
                temp = temp->next;
            }
            return mx;
        }
        T Search(T key){
            Node<T> *temp = head;
            int i = 0;
            while(temp != nullptr){
                i++;
                if(key == temp->data) return i;
                temp = temp->next;
            }
            return -1;
        }
        void Insert(int index, T key){
            if(index < 0 || index > length) return;
            Node<T> *temp = new Node<T>(key);
            if(index == 0){
                temp->next = head;
                head = temp;
            } else{
                Node<T> *p = head;
                for(int i = 0; i < index -1; i++){
                    p = p->next;
                }
                temp->next = p->next;
                p->next = temp;
            }
        }
        T Delete(int index){
            if(index < 0 || index > length) return INT32_MIN;
            Node<T> *temp = head;
            if(index == 0){
                head = temp->next;
            } else{
                for(int i = 0; i < index-1; i++){
                    temp = temp->next;
                }
                Node<T> *p = temp;
                temp = temp->next;
                p->next = temp->next;
            }
            length--;
            return temp->data;
        }
        bool isSorted(){
            Node<T> *temp = head;
            while(temp->next != nullptr){
                if(temp->data > temp->next->data) return false;
                temp = temp->next;
            }
            return true;
        }
        void RemoveDuplicates(){
            Node<T> *temp = head;
            Node<T> *q = temp->next;
            while(q != nullptr){
                if(temp->data != q->data){
                    temp = q;
                    q = q->next;
                } else{
                    temp->next = q->next;
                    q = temp->next;
                }
            }
        }
        void Reverse(){
            Node<T> *x = head;
            Node<T> *y = nullptr;
            Node<T> *z = nullptr;
            while(x != nullptr){
                z = y;
                y = x;
                x = x->next;
                y->next = z;
            }
            head = y;
        }
        ~LinkedList(){
            Node<T> *temp = head;
            while(temp != nullptr){
                Node<T> *next = temp->next;
                delete temp;
                temp = next;
            }
        }
};

int main(){
    LinkedList<int> ll;

    ll.Add(1);
    ll.Add(2);
    ll.Add(2);
    ll.Add(3);
    ll.Add(3);
    ll.Add(3);

    ll.Display();

    cout << "\nLength of the Linked List: " << ll.Length();
    cout << "\nSum of all the Nodes: " << ll.Sum();
    cout << "\nMaximum Element in LL: " << ll.Max();
    cout << "\nSearching 2 and Found in: " << ll.Search(2) << " Position\n";
    
    ll.Insert(6, 4);

    ll.Display();

    cout << "\nDeleting the element: " << ll.Delete(3) << endl;

    ll.Display();

    cout << "\nArray Sorted or not ?: " << (ll.isSorted() ? "Yes" : "No") << endl;

    ll.RemoveDuplicates();
    ll.Display();

    cout << endl;

    ll.Reverse();
    ll.Display();
    return 0;
}