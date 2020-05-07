#include<iostream>

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
    node *root = NULL;
    node* Insert(node *p, int value);
    node* Delete(node *p, int value);
    int height(node *p);
    node* Inpre(node *p);
    node* Insuc(node *p);
    void preorder(node *p);
};

node* tree::Insert(node *p, int value)
{
    node *t = new node;
    if(p == NULL)
    {
        t->data = value;
        t->rchild = t->lchild = NULL;

        return t;
    }
    if(value > p->data)
        p->rchild = Insert(p->rchild, value);
    else if(value < p->data)
        p->lchild = Insert(p->lchild, value);

    return p;
}

int tree::height(node *p)
{
    if(p == NULL)
        return 0;
    int x, y;
    x = height(p->lchild);
    y = height(p->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

node* tree::Inpre(node *p)
{
    while(p && p->rchild)
        p = p->rchild;

    return p;
}

node* tree::Insuc(node *p)
{
    while(p && p->lchild)
        p = p->lchild;

    return p;
}

node* tree::Delete(node *p, int key)
{
    node *q;
    if(p == NULL)
    {
        return NULL;
    }

    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p == root)
            root = NULL;
        delete p;
        return NULL;
    }

    if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild, key);
    else
    {
        if(height(p->lchild) > height(p->rchild))
        {
            q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = Insuc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
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

    t.root = t.Insert(t.root, 20);
    t.Insert(t.root, 10);
    t.Insert(t.root, 25);
    t.Insert(t.root, 30);
    t.Insert(t.root, 21);
    cout << "Preorder:- "; t.preorder(t.root); cout << endl;
    t.Delete(t.root, 20);
    cout << "Preorder:- "; t.preorder(t.root); cout << endl;

    return 0;
}
