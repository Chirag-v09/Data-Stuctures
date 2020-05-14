#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class node
{
public:
    node *lchild;
    int data;
    node*rchild;
};

class tree
{
public:
    node *root;
    void create(int a[], int n);
    void preorder(node *p);
};

void tree::create(int a[], int n)
{
    node *t, *p;
    int i = 0;
    stack<node*> s;

    t = new node;
    t->data = INT_MAX;
    t->lchild = t->rchild = NULL;
    s.push(t);

    root = new node;
    root->data = a[i++];
    root->lchild = root->rchild = NULL;
    p = root;

    while(i < n)
    {
        if(a[i] < p->data)
        {
            t = new node;
            t->data = a[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            s.push(p);
            p = t;
        }
        else if(a[i] > p->data && a[i] < s.top()->data)
        {
            t = new node;
            t->data = a[i++];
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            p = t;
        }
        else
        {
            p = s.top();
            s.pop();
        }
        cout << "h";
    }
}

void tree::preorder(node *p)
{
    stack<node*> s;
    while(p || !s.empty())
    {
        if(p)
        {
            cout << p->data;
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}

int main()
{
    tree t;
    int a[] = {30, 20, 10, 15, 25, 40, 50, 45};

    t.create(a, 8);
    cout << endl << "Preorder:- ";
    t.preorder(t.root);

    return 0;
}
