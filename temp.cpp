#include <iostream>
using namespace std;

struct Node
{
    Node * left;
    Node * right;
    int value;

    Node():left(0),right(0){}

    ~Node()
    {
        if (left) delete left;
        if (right) delete right;
    }
};

void Print (Node * x, int & id)
{
    if (!x) return;

    Print (x->left,id);

    id++;
    cout << id << ' ' << x->value << endl;

    Print (x->right,id);
}

int main()
{
    Node * root=new Node;
    root->value=10;

    root->left=new Node;
    root->left->value=20;

    root->left->left=new Node;
    root->left->left->value=30;

    root->right=new Node;
    root->right->value=40;

    root->right->left=new Node;
    root->right->left->value=50;

    int id=0;

    Print(root,id);

    delete root;

    cin.get();
    return 0;
}