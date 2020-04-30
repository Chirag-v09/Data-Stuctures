#include<iostream>

using namespace std;

class Queue
{
    int size;
    int f;
    int r;
    int *q;
public:
    Queue(int s)
    {
        size = s;
        f = -1;
        r = -1;
        q = new int[size];
    }

    void enqueue(int num)
    {
        if(r == size-1)
            cout << "Queue is FULL!" << endl;
        else
        {
            q[++r] = num;
        }
    }

    int dequeue()
    {
        if(r == f)
        {
            // cout << "Queue is Empty";
            return -1;
        }
        else
        {
            int x;
            x = q[++f];
            return x;
        }
    }

    void display()
    {
        cout << "Elements:" << endl;
        for(int i = f+1; i <= r; i++)
            cout << q[i] << endl;
    }
};

int main()
{
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Element Deleted is:- " << q.dequeue() << endl;
    q.display();

    return 0;
}
