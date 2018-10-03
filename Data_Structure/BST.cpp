#include <iostream>
#include "NodeT.h"

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
    void print();
    //Tarea 2
    int maxWidth();
    NodeT nearstRelative();
    BST(BST &tree);
    bool operator==(BST tree);
    void mirror();

  private:
    NodeT *root;
};

BST::BST()
{
    root = nullptr;
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
            father->setRight(new NodeT(data));
    }
}
