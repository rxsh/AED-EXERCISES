#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////

struct CBinNode
{
    CBinNode(int _v)
    {
        value = _v;
        nodes[0] = nodes[1] = 0;
    }
    int value;
    CBinNode* nodes[2];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////

class CBinTree
{
public:
    CBinTree();
    ~CBinTree();
    bool Insert(int x);
    bool Remove(int x);
    void Print();
    void PHojas();
    void Hojas(CBinNode* x);
    void Ramas(CBinNode* x);
    void Hijos(CBinNode* x);
    void Hermanos(CBinNode* x);
private:
    bool Find(int x, CBinNode**& p);
    CBinNode** Rep(CBinNode** p);
    void InOrder(CBinNode* x);
    CBinNode* root;
    bool brep;
};

CBinTree::CBinTree()
{
    root = 0;
    brep = 0;
}

CBinTree::~CBinTree()
{
}

bool CBinTree::Find(int x, CBinNode**& p)
{
    for (p = &root;
        *p && (*p)->value != x;
        p = &((*p)->nodes[(*p)->value < x]));
    return *p != 0;
}

bool CBinTree::Insert(int x)
{
    CBinNode** p;
    if (Find(x, p)) return 0;
    *p = new CBinNode(x);
    return 1;
}

bool CBinTree::Remove(int x)
{
    CBinNode** p;
    if (!Find(x, p)) return 0;

    if ((*p)->nodes[0] && (*p)->nodes[1]) //case 2
    {
        CBinNode** q = Rep(p);
        (*p)->value = (*q)->value;
        p = q;
    }
    // case 0 or case 1
    CBinNode* t = *p;
    *p = (*p)->nodes[(*p)->nodes[1] != 0];
    delete t;
    return 1;
}

CBinNode** CBinTree::Rep(CBinNode** p)
{
    CBinNode** q = p;
    for (q = &((*q)->nodes[!brep]); *q; q = &((*q)->nodes[brep]));
    brep = !brep;
    return q;
}

void CBinTree::InOrder(CBinNode* x)
{
    if (!x) return;
    InOrder(x->nodes[0]);
    cout << x->value << " ";
    InOrder(x->nodes[1]);
}

void CBinTree::Print()
{
    //InOrder(root);
    //Ramitas(root);
    Hojas(root);
    //Hijos(root);
    //Hermanos(root);
}

void CBinTree::Hojas(CBinNode* x)
{
    if (!x) return;
    Hojas(x->nodes[0]);
    if(!(x->nodes[0]) && !(x->nodes[1]))
        cout << x->value << " ";
    Hojas(x->nodes[1]);
}

void CBinTree::Ramas(CBinNode* x) {
    if (!x) return;
    Ramas(x->nodes[0]);
    if ((x->nodes[0]) || (x->nodes[1]))
        cout << x->value << " ";
    Ramas(x->nodes[1]);
}

void CBinTree::Hijos(CBinNode* x) {
    if (!x) return;
    Hijos(x->nodes[0]);
    if (x->nodes[0] && !(x->nodes[1])) {
        cout << "( " << x->value << ", " << x->nodes[0]->value << " ) ";
    }
    else if ((x->nodes[0]) && (x->nodes[1])) {
        cout << "( " << x->value << ", " << x->nodes[0]->value << " y " << x->nodes[1]->value << " ) ";
    }
    else if (!(x->nodes[0]) && x->nodes[1]) {
        cout << "( " << x->value << ", " << x->nodes[1]->value << " ) ";
    }
    Hijos(x->nodes[1]);
}

void CBinTree::Hermanos(CBinNode* x) {
    if (!x) return;
    Hermanos(x->nodes[0]);
    
    if ((x->nodes[0]) && (x->nodes[1])) {
        cout << "( "<< x->nodes[0]->value << " , " << x->nodes[1]->value << " ) ";
    }
    Hermanos(x->nodes[1]);
}

int main()
{
    CBinTree t;
    t.Insert(8); t.Insert(4); t.Insert(11); t.Insert(2); t.Insert(6); t.Insert(9); t.Insert(13); t.Insert(1); t.Insert(3); t.Insert(5); t.Insert(7); t.Insert(10); t.Insert(12);

    t.Print();
    cout<< endl;
}
