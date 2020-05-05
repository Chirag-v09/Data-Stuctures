#include<iostream>
#include<queue>

using namespace std;

class node
{
public:
    node *lchild;
    int data;
    node *rchild;
};

class tree
{
public:
    node *root;
    void CreateTree();
    void preorder(node *p);
    void Insert(node *p, int value);
};

void tree::CreateTree()
{
    node *t, *p;
    int x;
    queue <node*> q;

    root = new node;
    cout << "Enter root element:- ";
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.push(root);

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter Lchild of " << p->data << ":- ";
        cin >> x;
        if(x != -1)
        {
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        cout << "Enter Rchild of " << p->data << ":- ";
        cin >> x;
        if(x != -1)
        {
            t = new node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
}

void tree::Insert(node *p, int value)
{
    node *r = NULL, *q;
    while(p)
    {
        r = p;
        if(value == p->data)
            return;
        if(value > p->data)
            p = p->rchild;
        else
            p = p->lchild;
    }
    q = new node;
    q->data = value;
    q->lchild = q->rchild = NULL;
    if(value > r->data)
        r->rchild = q;
    else
        r->lchild = q;
}

void tree::preorder(node *p)
{
    if(p)
    {
        cout << p->data;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
    tree t;

    t.CreateTree();
    t.Insert(t.root, 5);
    cout << "Preorder:- "; t.preorder(t.root); cout << endl;

    return 0;
}
