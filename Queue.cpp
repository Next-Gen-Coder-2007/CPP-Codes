#include <iostream>
#include <stack>
using namespace std;

class QueueArray
{
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    QueueArray(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void Enqueue(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue Full\n";
        }
        else
        {
            rear++;
            Q[rear] = x;
        }
    }
    int Dequeue()
    {
        int x = -1;
        if (front == rear)
        {
            cout << "Queue is Empty\n";
        }
        else
        {
            x = Q[front++];
        }
        return x;
    }
    void Display()
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << Q[i] << "\n";
        }
    }
    ~QueueArray()
    {
        delete[] Q;
    }
};

class Node
{
public:
    int data;
    Node *next;
};

class QueueLinkedList
{
private:
    Node *front;
    Node *rear;

public:
    QueueLinkedList()
    {
        front = rear = nullptr;
    }
    void Enqueue(int x)
    {
        Node *t = new Node;
        if (t == nullptr)
        {
            cout << "Queue Overflow" << endl;
        }
        else
        {
            t->data = x;
            t->next = nullptr;
            if (front == nullptr)
            {
                front = t;
                rear = t;
            }
            else
            {
                rear->next = t;
                rear = t;
            }
        }
    }
    int Dequeue()
    {
        int x = -1;
        Node *p;
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
        }
        else
        {
            p = front;
            front = front->next;
            x = p->data;
            delete p;
        }
        return x;
    }
    bool isEmpty()
    {
        if (front == nullptr)
        {
            return true;
        }
        return false;
    }
    void Display()
    {
        Node *p = front;
        while (p)
        {
            cout << p->data << flush;
            p = p->next;
            if (p != nullptr)
            {
                cout << " <- " << flush;
            }
        }
        cout << endl;
    }
    ~QueueLinkedList() {}
};

class QueueStack
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    QueueStack() {}

    void Enqueue(int x)
    {
        s1.push(x);
    }

    int Dequeue()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (s2.empty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }

        int x = s2.top();
        s2.pop();
        return x;
    }

    bool isEmpty()
    {
        return s1.empty() && s2.empty();
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        stack<int> tempS2 = s2;
        stack<int> tempS1 = s1;
        stack<int> reverseS1;

        while (!tempS1.empty())
        {
            reverseS1.push(tempS1.top());
            tempS1.pop();
        }

        while (!tempS2.empty())
        {
            cout << tempS2.top() << " ";
            tempS2.pop();
        }

        while (!reverseS1.empty())
        {
            cout << reverseS1.top() << " ";
            reverseS1.pop();
        }

        cout << endl;
    }
};

int main()
{
    QueueStack q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(40);

    q.Display();

    cout << q.Dequeue() << endl;
    q.Display();

    return 0;
}