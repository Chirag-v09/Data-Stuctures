#include<iostream>
#include<stack>

using namespace std;

class node
{
public:
    node *lchild;
    int data;
    int height;
    node *rchild;
};

class tree
{
public:
    node *root = NULL;
    node* rinsert(node *p, int key);
    int NodeHeight(node *p);
    int BalanceFactor(node *p);
    node* LLRotation(node *p);
    node* LRRotation(node *p);
    node* RRRotation(node *p);
    node* RLRotation(node *p);
    void preorder(node *p);
};

int tree::NodeHeight(node *p)
{
    int hl, hr;
    hl = p && p->lchild? p->lchild->height : 0;
    hr = p && p->rchild? p->rchild->height : 0;
    if(hl > hr)
        return hl+1;
    else
        return hr+1;
}

int tree::BalanceFactor(node *p)
{
    int hl, hr;
    hl = p && p->lchild? p->lchild->height : 0;
    hr = p && p->rchild? p->rchild->height : 0;

    return hl-hr;
}

node* tree::LLRotation(node *p)
{
    node *pl = p->lchild;
    node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(p == root)
        root = pl;

    return pl;
}

node* tree::LRRotation(node *p)
{
    node *pl = p->lchild;
    node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(p == root)
        root = plr;

    return plr;
}

node* tree::RRRotation(node *p)
{
    return NULL;
}

node* tree::RLRotation(node *p)
{
    return NULL;
}

node* tree::rinsert(node *p, int key)
{
    if(p == NULL)
    {
        node *t = new node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        t->height = 1;

        return t;
    }

    if(p->data > key)
        p->lchild = rinsert(p->lchild, key);
    else if(p->data < key)
        p->rchild = rinsert(p->rchild, key);

    p->height = NodeHeight(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
            return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);

    return p;
}

void tree::preorder(node *p)
{
    stack <node*> s;
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
    t.root = t.rinsert(t.root, 10);
    t.rinsert(t.root, 5);
    t.rinsert(t.root, 7);
    cout << "Preorder:- ";
    t.preorder(t.root);
}
