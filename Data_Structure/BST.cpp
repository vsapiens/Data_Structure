#include <iostream>
using namespace std;
#include "NodeT.h"
#include <stack>

class BST
{
  public:
    BST();
    ~BST();
    void add(int data);
    bool search(int data);
    void remove(int data);

    //Tarea 1
    int height();
    void ancestors();
    int whatLevelamI();
    void print(int c);

    //Tarea 2
    int maxWidth();
    NodeT nearstRelative();
    BST(BST &tree);
    bool operator==(BST tree);
    void mirror();

  private:
    NodeT *root;
    int howManyChildren(NodeT *r);
    int pred(NodeT *r);
    int succ(NodeT *r);
    void preOrder(NodeT *r);
    void inOrder(NodeT *r);
    void postOrder(NodeT *r);
    void libera(NodeT *r);
    int height_aux(NodeT *r);
    void print_Level(NodeT *r, int a);
    void LevelbyLevel(NodeT *r);
};

BST::BST()
{
    root = nullptr;
}
void BST::libera(NodeT *r)
{
    if (r != nullptr)
    {
        libera(r->getLeft());
        libera(r->getRight());
        delete r;
    }
}
BST::~BST()
{
    libera(root);
}
bool BST::search(int data)
{
    NodeT *curr = root;
    while (curr != nullptr)
    {
        if (curr->getData() == data)
        {
            return true;
        }
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    return false;
}

void BST::add(int data)
{
    NodeT *curr = root;
    NodeT *father = nullptr;
    while (curr != nullptr)
    {
        if (curr->getData() == data)
            return;

        father = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    if (father == nullptr)
        root = new NodeT(data);
    else
    {
        if (father->getData() > data)
            father->setLeft(new NodeT(data));

        else
        {
            father->setRight(new NodeT(data));
        }
    }
}

int BST::howManyChildren(NodeT *r)
{
    int cant = 0;
    if (r->getLeft() != nullptr)
        cant++;

    if (r->getRight() != nullptr)
        cant++;

    return cant;
}

int BST::succ(NodeT *r)
{

    NodeT *aux = r->getRight();
    while (aux->getLeft() != nullptr)
        aux = aux->getLeft();

    return aux->getData();
}
int BST::pred(NodeT *r)
{

    NodeT *aux = r->getLeft();
    while (aux->getRight() != nullptr)
        aux = aux->getRight();

    return aux->getData();
}
void BST::remove(int data)
{
    NodeT *curr = root;
    NodeT *father = nullptr;

    while (curr != nullptr && curr->getData() != data)
    {
        father = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    if (curr == nullptr)
        return;
    int ch = howManyChildren(curr);

    switch (ch)
    {
    case 0:
        if (father == nullptr)
        {
            root = nullptr;
        }
        else
        {
            if (father->getData() > data)
            {
                father->setLeft(nullptr);
            }
            else
            {
                father->setRight(nullptr);
            }
        }
        delete curr;
        break;

    case 1:
        if (father == nullptr)
        {
            if (curr->getLeft() != nullptr)
            {
                root = curr->getLeft();
            }
            else
            {
                root = curr->getRight();
            }
        }
        else
        {
            if (father->getData() > data)
            {
                if (curr->getLeft() != nullptr)
                {
                    father->setLeft(curr->getLeft());
                }
                else
                {
                    father->setLeft(curr->getRight());
                }
            }
            else
            {
                if (curr->getLeft() != nullptr)
                {
                    father->setLeft(curr->getLeft());
                    //father->setRight(curr->getLeft());
                }
                else
                {
                    father->setRight(curr->getRight());
                }
            }
        }
        break;

    case 2:
        int x = pred(curr);
        remove(x);
        curr->setData(x);
        break;
    }
}

int BST::height_aux(NodeT *r)
{
    NodeT *curr = r;
    int H_right, H_left;
    if (curr == nullptr)
        return 0;

    H_left = height_aux(curr->getLeft());
    H_right = height_aux(curr->getRight());

    return (H_right > H_left)
               ? H_right + 1
               : H_left + 1;
}

int BST::height()
{
    return height_aux(root);
}

void BST::preOrder(NodeT *r)
{
    if (r != nullptr)
    {
        cout << r->getData() << " ";
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}

void BST::inOrder(NodeT *r)
{
    if (r != nullptr)
    {
        inOrder(r->getLeft());
        cout << r->getData() << " ";
        inOrder(r->getRight());
    }
}
void BST::postOrder(NodeT *r)
{
    if (r != nullptr)
    {
        postOrder(r->getLeft());
        postOrder(r->getRight());
        cout << r->getData() << " ";
    }
}
void BST::print_Level(NodeT *r, int a)
{
    NodeT *curr = r;
    if (curr == nullptr)
        return;
    if (a == 1)
        cout << curr->getData() << " ";
    else if (a > 1)
    {
        print_Level(curr->getLeft(), a - 1);
        print_Level(curr->getRight(), a - 1);
    }
}
void BST::LevelbyLevel(NodeT *r)
{
    NodeT *curr = r;
    int iHeight = height_aux(r);
    for (int i = 1; i <= iHeight; i++)
        print_Level(curr, i);

    cout << endl;
    ;
}
void BST::print(int c)
{
    // 1- PreOrder
    // 2- InOrder
    // 3- PostOrder
    // 4- LevelbyLevel
    switch (c)
    {
    case 1:
        preOrder(root);

        break;
    case 2:
        inOrder(root);
        break;
    case 3:
        postOrder(root);
        break;
    case 4:
        LevelbyLevel(root);
        break;
    }
}

void BST::ancestors()
{
}
int BST::whatLevelamI()
{
    if (root == nullptr)
        return -1;
}

int main()
{
    BST miArbol;
    miArbol.add(12);
    miArbol.add(100);
    miArbol.add(50);
    miArbol.add(1);
    miArbol.add(65);
    miArbol.print(1);
    cout << endl;
    cout << miArbol.height() << endl;
    miArbol.print(4);
    return 0;
}
