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
        f = 0;
        r = 0;
        q = new int[size];
    }

    void enqueue(int num)
    {
        if((r+1)%size == f)
            cout << "Queue is FULL!" << endl;
        else
        {
            r = (r+1)%size;
            q[r] = num;
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
            f = (f+1)%size;
            x = q[f];
            return x;
        }
    }

    void display()
    {
        cout << "Elements:" << endl;
        int i = f+1;
        do{
            cout << q[i] << endl;
            i = (i+1)%size;
        }while(i != (r+1)%size);
    }
};

int main()
{
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Element Deleted is:- " << q.dequeue() << endl;
    q.display();

    return 0;
}
