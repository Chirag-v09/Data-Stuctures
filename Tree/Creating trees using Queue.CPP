#include<iostream>

using namespace std;

class node
{
public:
    node *lchild;
    int data;
    node *rchild;
};

class Stack
{
    node *data;
    Stack *next;
public:

    void push(node* value);
    node* pop();
    int isEmpty();
}*top = NULL;

void Stack::push(node *value)
{
    Stack *t = new Stack;
    if(t == NULL)
    {
        cout << "Stack is FULL!" << endl;
        return;
    }
    t->data = value;
    t->next = top;
    top = t;
}

node* Stack::pop()
{
    if(top == NULL)
    {
        return NULL;
    }
    Stack *t = top;
    node* x = t->data;
    top = top->next;
    delete t;
    return x;
}

int Stack::isEmpty()
{
    if(top == NULL)
        return 1;
    return 0;
}


class Queue
{
    node *data;
    Queue *next;
public:
    void enqueue(node *num);
    node* dequeue();
    int isEmpty();
}*first = NULL, *Rear = NULL;

int Queue::isEmpty()
{
    return first == NULL;
}

void Queue::enqueue(node *num)
{
    Queue *t = new Queue;
    if(t == NULL)
    {
        cout << "Queue is FULL!" << endl;
        return ;
    }
    t->data = num;
    t->next = NULL;

    if(first == NULL)
    {
        first = Rear = t;
    }
    else
    {
        Rear->next = t;
        Rear = t;
    }
}

node* Queue::dequeue()
{
    if(first == NULL)
    {
        return NULL;
    }
    else
    {
        Queue *t = first;
        first = first->next;
        node *x = t->data;
        delete t;
        return x;
    }
}


class tree
{
public:
    node *root;
    tree(){root = NULL;}
    void CreateTree();
    void preorder(node *p);
    void Ipreorder(node *p);
    void inorder(node *p);
    void Iinorder(node *p);
    void postorder(node *p);
    void Ipostorder(node *p);
    void levelorder(node *p);
    void height(node *p);
    int count(node *p);
    int count2(node *p);
    int Sum(node *p);
    int height(node *p);
};

void tree::CreateTree()
{
    node *t, *p;
    Queue q;
    int x;

    root = new node;
    cout << "Enter value of Root:- ";
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter value of Lchild of " << p->data << ":- ";
        cin >> x;
        if(x != -1)
        {
            t = new node;
            t->data = x;
            t->rchild = t->lchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter value of Rchild of " << p->data << ":- ";
        cin >> x;
        if(x != -1)
        {
            t = new node;
            t->data = x;
            t->rchild = t->lchild = NULL;
            p->rchild = t;
            q.enqueue(t);
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

void tree::Ipreorder(node *p)
{
    Stack s;

    while(p != NULL || !s.isEmpty())
    {
        if(p != NULL)
        {
            cout << p->data;
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.pop();
            p = p->rchild;
        }
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

void tree::Iinorder(node *p)
{
    Stack s;

    while(p != NULL || !s.isEmpty())
    {
        if(p != NULL)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.pop();
            cout << p->data;
            p = p->rchild;
        }
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

void tree::Ipostorder(node *p) // having error
{
    Stack s;
    node *temp;

    while(p != NULL || !s.isEmpty())
    {
        if(p != NULL)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            temp = s.pop();
            if(temp > 0)
            {
                // temp = temp * (node*)-1;
                s.push(temp);
                p = (temp->rchild);
            }
            else
            {
                cout << (temp->data);
                p = NULL;
            }
        }
    }
}

void tree::levelorder(node *p)
{
    Queue q;

    cout << p->data;
    q.enqueue(p);
    while(!q.isEmpty())
    {
        p = q.dequeue();
        if(p->lchild)
        {
            cout << p->lchild->data;
            q.enqueue(p->lchild);
        }
        if(p->rchild)
        {
            cout << p->rchild->data;
            q.enqueue(p->rchild);
        }
    }
}

int tree::count(node *p)
{
    int x, y;
    if(p)
    {
        x = count(p->lchild);
        y = count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int tree::count2(node *p)
{
    int x, y;
    if(p)
    {
        x = count2(p->lchild);
        y = count2(p->rchild);
        if(p->lchild && p->rchild)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int tree::Sum(node *p)
{
    int x, y;
    if(p)
    {
        x = Sum(p->lchild);
        y = Sum(p->rchild);
        return x+y+p->data;
    }
    return 0;
}

int tree::height(node *p)
{
    int x, y;
    if(p)
    {
        x = height(p->lchild);
        y = height(p->rchild);

        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

int main()
{
    tree t;
    t.CreateTree();
    cout << "Preorder: "; t.Ipreorder(t.root); cout << endl;
    cout << "Inorder: "; t.Iinorder(t.root); cout << endl;
    cout << "Postorder: "; t.postorder(t.root); cout << endl;
    cout << "Levelorder: "; t.levelorder(t.root); cout << endl;
    cout << "Count:- " << t.count(t.root) << endl;
    cout << "Count:- " << t.count2(t.root) << endl;
    cout << "Count:- " << t.count3(t.root) << endl;
    cout << "Count:- " << t.count4(t.root) << endl;

    return 0;
}
