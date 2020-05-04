#include<iostream>
#include<queue>
#include<stack>

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
    void Ipreorder(node *p);
    void inorder(node *p);
    void Iinorder(node *p);
    void postorder(node *p);
    void Ipostorder(node *p);
    void postOrderIterative(node *root);
    void levelorder(node *p);
    void levelorder2(node *p);
    int height(node *p);
    int count(node *p);
};

void tree::CreateTree()
{
    node *t, *p;
    queue <node*> q;
    int x;

    root = new node;
    cout << "Enter root node:- ";
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

void tree::preorder(node *p)
{
    if(p)
    {
        cout << p->data;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void tree::inorder(node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout << p->data;
        inorder(p->rchild);
    }
}

void tree::postorder(node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data;
    }
}

void tree::Ipreorder(node *p)
{
    if(root == NULL)
        return;

    stack <node*>s;

    while(p != NULL || !s.empty())
    {
        if(p != NULL)
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

void tree::Iinorder(node *p)
{
    stack <node*> s;

    while(p != NULL || !s.empty())
    {
        if(p != NULL)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            s.pop();
            cout << p->data;
            p = p->rchild;
        }
    }
}

void tree::Ipostorder(node *p)
{
    stack <node*> s;

    while(p != NULL || !s.empty())
    {
        if(p != NULL)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            s.pop();
            cout << p->data;
            p = p->rchild;
        }
    }
}

void tree::postOrderIterative(node* root)
{
    if (root == NULL)
        return;

    // Create two stacks
    stack<node *> s1, s2;

    // push root to first stack
    s1.push(root);
    node* n;

    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        n = s1.top();
        s1.pop();
        s2.push(n);

        // Push left and right children
        // of removed item to s1
        if (n->lchild)
            s1.push(n->lchild);
        if (n->rchild)
            s1.push(n->rchild);
    }

    // Print all elements of second stack
    while (!s2.empty()) {
        n = s2.top();
        s2.pop();
        cout << n->data << " ";
    }
}

void tree::levelorder(node *p)
{
    queue <node*> q;

    q.push(p);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        cout << p->data;
        if(p->lchild)
            q.push(p->lchild);
        if(p->rchild)
            q.push(p->rchild);
    }
}


void tree::levelorder2(node *p)
{
    queue <node*> q;

    cout << p->data;
    q.push(p);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p->lchild)
        {
            cout << p->lchild->data;
            q.push(p->lchild);
        }
        if(p->rchild)
        {
            cout << p->rchild->data;
            q.push(p->rchild);
        }
    }
}

int tree::height(node *p)
{
    int x, y;
    if(p)
    {
        x = height(p->lchild);
        y = height(p->rchild);
        if(x > y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

int count(node *p)
{
    if(p)
    {
        return count(p->lchild) + count(p->rchild) + 1;
    }
    return 0;
}

int Sum(node *p)
{
    if(p)
    {
        return Sum(p->lchild) + Sum(p->rchild) + p->data;
    }
    return 0;
}

int main()
{
    tree t;

    t.CreateTree();
    cout << "Preorder:- "; t.Ipreorder(t.root); cout << endl;
    cout << "Inorder:- "; t.Iinorder(t.root); cout << endl;
    cout << "Postorder:- "; t.Ipostorder(t.root); cout << endl;
    cout << "Levelorder:- "; t.levelorder2(t.root); cout << endl;
    cout << "Postorder:- "; t.postOrderIterative(t.root); cout << endl;
    cout << "Height:- " << t.height(t.root) << endl;
    cout << "Count:- " << count(t.root) << endl;
    cout << "Sum:- " << Sum(t.root) << endl;

    return 0;
}
