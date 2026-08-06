#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *prev;
    Node<T> *next;

    Node(T n)
    {
        data = n;
        prev = nullptr;
        next = nullptr;
    }

    ~Node() {}
};

template <typename T>
class DoublyLinkedList
{
private:
    Node<T> *head;
    int length;

    void DispRec(Node<T> *temp)
    {
        if (temp != nullptr)
        {
            cout << temp->data << " ";
            DispRec(temp->next);
        }
    }

public:
    DoublyLinkedList()
    {
        head = nullptr;
        length = 0;
    }

    void Add(T n)
    {
        Node<T> *newNode = new Node<T>(n);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = newNode;
            newNode->prev = temp;
        }

        length++;
    }

    void Display()
    {
        DispRec(head);
    }

    void DisplayReverse()
    {
        if (head == nullptr)
            return;

        Node<T> *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
    }

    int Length()
    {
        return length;
    }

    T Sum()
    {
        T sum = 0;
        Node<T> *temp = head;

        while (temp != nullptr)
        {
            sum += temp->data;
            temp = temp->next;
        }

        return sum;
    }

    T Max()
    {
        Node<T> *temp = head;
        T mx = temp->data;

        while (temp != nullptr)
        {
            if (temp->data > mx)
                mx = temp->data;
            temp = temp->next;
        }

        return mx;
    }

    int Search(T key)
    {
        Node<T> *temp = head;
        int pos = 1;

        while (temp != nullptr)
        {
            if (temp->data == key)
                return pos;
            temp = temp->next;
            pos++;
        }

        return -1;
    }

    void Insert(int index, T key)
    {
        if (index < 0 || index > length)
            return;

        Node<T> *newNode = new Node<T>(key);

        if (index == 0)
        {
            newNode->next = head;

            if (head != nullptr)
                head->prev = newNode;

            head = newNode;
        }
        else
        {
            Node<T> *temp = head;

            for (int i = 0; i < index - 1; i++)
                temp = temp->next;

            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != nullptr)
                temp->next->prev = newNode;

            temp->next = newNode;
        }

        length++;
    }

    T Delete(int index)
    {
        if (index < 0 || index >= length)
            return INT32_MIN;

        Node<T> *temp = head;

        if (index == 0)
        {
            head = head->next;

            if (head != nullptr)
                head->prev = nullptr;
        }
        else
        {
            for (int i = 0; i < index; i++)
                temp = temp->next;

            temp->prev->next = temp->next;

            if (temp->next != nullptr)
                temp->next->prev = temp->prev;
        }

        T x = temp->data;
        delete temp;
        length--;

        return x;
    }

    bool isSorted()
    {
        Node<T> *temp = head;

        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->data > temp->next->data)
                return false;
            temp = temp->next;
        }

        return true;
    }

    void RemoveDuplicates()
    {
        Node<T> *temp = head;

        while (temp != nullptr && temp->next != nullptr)
        {
            if (temp->data == temp->next->data)
            {
                Node<T> *q = temp->next;

                temp->next = q->next;

                if (q->next != nullptr)
                    q->next->prev = temp;

                delete q;
                length--;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    void Reverse()
    {
        Node<T> *temp = head;
        Node<T> *p = nullptr;

        while (temp != nullptr)
        {
            p = temp->prev;
            temp->prev = temp->next;
            temp->next = p;
            temp = temp->prev;
        }

        if (p != nullptr)
            head = p->prev;
    }

    ~DoublyLinkedList()
    {
        Node<T> *temp = head;

        while (temp != nullptr)
        {
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main()
{
    DoublyLinkedList<int> dll;

    dll.Add(1);
    dll.Add(2);
    dll.Add(2);
    dll.Add(3);
    dll.Add(3);
    dll.Add(3);

    dll.Display();

    cout << "\nLength: " << dll.Length();
    cout << "\nSum: " << dll.Sum();
    cout << "\nMax: " << dll.Max();
    cout << "\nSearch 2: " << dll.Search(2);

    dll.Insert(6, 4);

    cout << "\nAfter Insert:\n";
    dll.Display();

    cout << "\nDeleted: " << dll.Delete(3) << endl;

    dll.Display();

    cout << "\nSorted: " << (dll.isSorted() ? "Yes" : "No") << endl;

    dll.RemoveDuplicates();

    cout << "After Removing Duplicates:\n";
    dll.Display();

    cout << "\nReverse Display:\n";
    dll.DisplayReverse();

    dll.Reverse();

    cout << "\nAfter Reversing:\n";
    dll.Display();

    return 0;
}