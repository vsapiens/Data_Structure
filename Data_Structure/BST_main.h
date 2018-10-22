#include <iostream>
using namespace std;
#include "NodeT.h"
#include <stack>
#include <queue>
#include <cmath>
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
    void ancestors(int a);
    void whatLevelamI(int a);
    void print(int c);

    //Actividad CLASE BST2
    int count();

    //Tarea 2
    int maxWidth();
    NodeT *nearestRelative(NodeT *r, int a, int b);
    BST(const BST &tree);
    bool operator==(BST tree);
    void mirror();
    //Tarea 3
    int diameter();
    bool isBalanced();

    //Extra
    void printPathToLeaves();
    int min_Distance(int a, int b);
    int greatestNode(NodeT *r);
    int smallestNode(NodeT *r);
    int descendants(int data);
    int closestElement(int a);
    int getWidth(int level);
    void printKthDist(int distance);

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
    bool ancestors_aux(NodeT *r, int a);
    int actual_Level(NodeT *r, int a, int level);
    void printLeaves(NodeT *r);
    void printLevelbyLevel(NodeT *r);
    int cuenta(NodeT *r);
    int maxWidth(NodeT *r);
    void mirror(NodeT *r);

    //Extra
    void newNodeT(NodeT *Nold, NodeT *Nnew);
    int checkDistance(NodeT *r, int a, int b);
    void printWithStack(NodeT *r, std::stack<int> st);
    int distanceAux(NodeT *curr, int a);
    int countDescendants(NodeT *curr);
    int closest_Element(NodeT *r, int a);
    void findKthElement(NodeT *r, int iCounter);
    int getWidthAux(NodeT *curr, int level);
    int diameterAux(NodeT *r);
    bool isBalancedAux(NodeT *r);
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
void BST::ancestors(int a)
{
    NodeT *curr = root;
    stack<int> pila;
    while (curr != nullptr)
    {
        if (curr->getData() == a)
        {
            if (pila.empty())
                cout << "NO EXISTEN ANCESTROS" << endl;
            else
            {
                while (!pila.empty())
                {
                    cout << pila.top() << " ";
                    pila.pop();
                }
                cout << endl;
            }
            return;
        }
        pila.push(curr->getData());
        curr = (curr->getData() > a) ? curr->getLeft() : curr->getRight();
    }
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

    return (H_right > H_left) ? H_right + 1 : H_left + 1;
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
/*
Metodo Recursivo de Print por nivel
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
*/
void BST::printLevelbyLevel(NodeT *r)

{
    queue<NodeT *> fila;
    fila.push(r);
    NodeT *curr;
    while (!fila.empty())
    {
        curr = fila.front();
        fila.pop();
        cout << curr->getData() << " ";
        if (curr->getLeft() != nullptr)
            fila.push(curr->getLeft());

        if (curr->getRight() != nullptr)
            fila.push(curr->getRight());
    }
}
void BST::printLeaves(NodeT *r)
{

    if (r == nullptr)
        return;

    if (r->getLeft() == nullptr && r->getRight() == nullptr)
    {
        cout << r->getData() << " ";
    }
    else
    {
        printLeaves(r->getLeft());
        printLeaves(r->getRight());
    }
}
void BST::print(int c)
{
    // 1- PreOrder
    // 2- InOrder
    // 3- PostOrder
    // 4- PrintLeaves
    // 5- PrintLevelbyLevel
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
        printLeaves(root);
        break;
    case 5:
        printLevelbyLevel(root);
        //LevelbyLevel(root);
        break;
    }
}
/* Ancestros recursivo
bool BST::ancestors_aux(NodeT *r, int a)
{
    NodeT *curr = r;

    if (curr == nullptr)
        return false;

    if (curr->getData() == a)
        return true;

    bool isLeft = ancestors_aux(curr->getLeft(), a);

    bool isRight = false;

    if (!isLeft)
        isRight = ancestors_aux(curr->getRight(), a);

    if (isLeft || isRight)
        cout << curr->getData() << " ";

    return isLeft || isRight;
}
void BST::ancestors(int a)
{
    ancestors_aux(root, a);
    cout << endl;
}
*/
/* Metodo recursivo de actual level
int BST::actual_Level(NodeT *r, int a, int level)
{
    NodeT *curr = r;

    if (curr == nullptr)
        return 0;
    if (curr->getData() == a)
        return level;

    int nextLevel = actual_Level(curr->getLeft(), a, level + 1);
    if (nextLevel != 0)
        return nextLevel;

    return actual_Level(curr->getRight(), a, level + 1);
}
*/
void BST::whatLevelamI(int a)
{
    // cout << actual_Level(root, a, 1) << endl;
    NodeT *curr = root;
    int nivel = 0;
    while (curr != nullptr)
    {
        nivel++;
        if (curr->getData() == a)
        {
            cout << nivel << endl;
        }

        curr = (curr->getData() > a) ? curr->getLeft() : curr->getRight();
    }
    if (curr == nullptr)
        cout << -1 << endl;
}

int BST::maxWidth(NodeT *r)
{
    queue<NodeT *> q;
    NodeT *curr1 = r;
    NodeT *curr2 = nullptr;
    int max = 0;

    if (curr1 == nullptr)
        return 0;

    q.push(r);

    while (!q.empty())
    {
        int width = q.size();
        if (max < width)
            max = width;

        while (width--)
        {
            curr2 = q.front();
            q.pop();

            if (curr2->getLeft())
                q.push(curr2->getLeft());

            if (curr2->getRight())
                q.push(curr2->getRight());
        }
    }
    return max;
}

int BST::maxWidth()
{
    return maxWidth(root);
}

NodeT *BST::nearestRelative(NodeT *r, int a, int b)
{
    //Recursivo
    NodeT *curr = r;

    if (r == nullptr)
        return 0;

    if (curr->getData() > b && curr->getData() > a)
        return nearestRelative(curr->getLeft(), a, b);

    if (curr->getData() < b && curr->getData() > a)
        return nearestRelative(curr->getRight(), a, b);

    return curr;
    /* Iterative
    stack<int> Rel;
    NodeT *curr1 = root;
    NodeT *curr2 = root;
    NodeT *aux = root;

    while (curr1 != nullptr && curr2 != nullptr)
    {

        Rel.push(aux->getData());

        if (curr1->getData() != a)
            curr1 = (curr1->getData() > a) ? curr1->getLeft() : curr1->getRight();

        if (curr2->getData() != b)
            curr2 = (curr2->getData() > b) ? curr2->getLeft() : curr2->getRight();

        if (curr1->getData() == a)
            aux = curr2;

        if (curr2->getData() == b)
            aux = curr1;
        }

    En caso de que se encuentre entre el padre e hijo
    int length = Rel.size();
    int Relative;

    for (int i = 0; i < Rel.size(); i++)
    {
        if (curr1->getData() == Rel.top() || curr2->getData() == Rel.top())
            Rel.pop();
        if (curr1->getData() != Rel.top() && curr2->getData() != Rel.top())
            return Rel.top();
    }
    */
}
void BST::newNodeT(NodeT *Nold, NodeT *Nnew)
{
    if (Nold == nullptr)
        return;

    if (Nold->getLeft() != nullptr)
        Nnew->setLeft(new NodeT(Nold->getLeft()->getData()));

    if (Nold->getRight() != nullptr)
        Nnew->setRight(new NodeT(Nold->getRight()->getData()));

    newNodeT(Nold->getLeft(), Nnew->getLeft());
    newNodeT(Nold->getRight(), Nnew->getRight());
}

BST::BST(const BST &tree)
{

    if (tree.root == nullptr)
    {
        root = nullptr;
        return;
    }
    root = new NodeT(tree.root->getData());

    newNodeT(tree.root, this->root);
}
bool checkequal(NodeT *curr1, NodeT *curr2)
{
    if (curr1 == nullptr && curr2 == nullptr)
        return true;

    if ((curr1 == nullptr && curr2 != nullptr) || (curr1 != nullptr && curr2 == nullptr))
        return false;

    if (curr1->getData() != curr2->getData())
        return false;

    return checkequal(curr1->getLeft(), curr2->getLeft()) && checkequal(curr1->getRight(), curr2->getRight());
}

bool BST::operator==(BST tree)
{
    return checkequal(root, tree.root);
}
void BST::mirror(NodeT *r)
{
    if (r == nullptr)
        return;

    NodeT *aux = r->getLeft();
    r->setLeft(r->getRight());
    r->setRight(aux);

    mirror(r->getLeft());
    mirror(r->getRight());
}
void BST::mirror()
{
    mirror(root);
}

int BST::cuenta(NodeT *r)
{
    if (r == nullptr)
        return 0;
    return 1 + cuenta(r->getLeft() + cuenta(r->getRight()));
}
int BST::count()
{
    return cuenta(root);
}
void BST::printWithStack(NodeT *r, std::stack<int> st)
{
    if (r == nullptr)
        return;

    if (r->getRight() == nullptr && r->getLeft() == nullptr)
    {
        st.push(r->getData());

        while (!st.empty())
        {
            std::cout << st.top() << " ";
            st.pop();
        }

        std::cout << std::endl;

        return;
    }

    st.push(r->getData());

    printWithStack(r->getLeft(), st);
    printWithStack(r->getRight(), st);
}

void BST::printPathToLeaves()
{
    std::stack<int> st;
    printWithStack(root, st);
}
int BST::smallestNode(NodeT *r)
{
    if (r->getLeft() == nullptr)
    {
        return r->getData();
    }
    smallestNode(r->getLeft());
}
int BST::greatestNode(NodeT *r)
{
    if (r->getRight() == nullptr)
    {
        return r->getData();
    }
    greatestNode(r->getRight());
}
int BST::countDescendants(NodeT *curr)
{
    if (curr == nullptr)
    {
        return 0;
    }
    return countDescendants(curr->getLeft()) + countDescendants(curr->getRight()) + 1;
}

int BST::descendants(int data)
{
    if (root == nullptr)
    {
        return -1;
    }

    NodeT *curr = root;
    while (curr != nullptr && curr->getData() != data)
    {
        curr = (data > curr->getData()) ? curr->getRight() : curr->getLeft();
    }

    return countDescendants(curr) - 1;
}
void BST::findKthElement(NodeT *r, int iCounter)
{
    if (r == nullptr)
    {
        return;
    }
    if (iCounter == 0)
    {
        cout << r->getData() << endl;
    }

    findKthElement(r->getLeft(), iCounter - 1);
    findKthElement(r->getRight(), iCounter - 1);
}

void BST::printKthDist(int distance)
{
    findKthElement(root, distance);
}

int BST::getWidthAux(NodeT *curr, int level)
{
    if (curr == nullptr)
    {
        return 0;
    }

    if (level == 0)
    {
        return 1;
    }

    else if (level >= 1)
    {
        return getWidthAux(curr->getLeft(), level - 1) + getWidthAux(curr->getRight(), level - 1);
    }
}
int BST::getWidth(int level)
{

    NodeT *curr = root;
    queue<NodeT *> q;
    int currLevel = 0;

    if (curr == nullptr)
        return 0;
    q.push(curr);
    while (!q.empty())
    {
        int queueSize = q.size();
        if (currLevel == level)
        {
            return queueSize;
        }
        while (--queueSize)
        {
            if (q.front()->getLeft() != nullptr)
                q.push(q.front()->getLeft());

            if (q.front()->getRight() != nullptr)
                q.push(q.front()->getRight());

            q.pop();
        }
        ++currLevel;
    }
    return getWidthAux(root, level);
}

int BST::distanceAux(NodeT *curr, int a)
{
    if (curr->getData() == a)
        return 0;

    else if (curr->getData() > a)
        return 1 + distanceAux(curr->getLeft(), a);

    return 1 + distanceAux(curr->getRight(), a);
}
/*
int BST::checkDistance(NodeT *r, int a, int b)
{
    NodeT *curr;
    if (r == nullptr)
        return 0;
    if (r->getData() > a && r->getData() > b)
    {
        curr = r->getLeft();
        return checkDistance(curr, a, b);
    }
    else if (curr->getData() < a && curr->getData() < b)
    {
        curr = r->getRight();
        return checkDistance(curr, a, b);
    }

    else if (curr->getData() > a && curr->getData() < b)
        return distanceAux(root, a) + distanceAux(root, b);
}
int BST::min_Distance(int a, int b)
{
    if (a > b)
    {
        swap(a, b);
    }
    return checkDistance(root, a, b);
}
*/
int closest_element(NodeT *curr, int a)
{
    stack<int> nearest;
    NodeT *curr2;

    if (curr == nullptr)
        return 0;

    while (curr != nullptr)
    {
        curr2 = curr;
        if (curr->getData() == a)
            return curr->getData();

        curr = (curr->getData() > a) ? curr->getLeft() : curr->getRight();
        nearest.push(curr->getData());

        if (curr2->getData() < a && curr->getData() > a)
            return nearest.top();
    }
    return 0;
}
int BST::closestElement(int a)
{
    return closest_element(root, a);
}
bool BST::isBalancedAux(NodeT *r)
{
    return (r == nullptr) ? true : (abs(height_aux(r->getLeft()) - height_aux(r->getRight())) < 2 && isBalancedAux(r->getLeft()) && isBalancedAux(r->getRight()));
}
bool BST::isBalanced()
{
    return isBalancedAux(root);
}

int BST::diameterAux(NodeT *r)
{
    if (r == nullptr)
        return 0;

    int diameter = diameterAux(r->getLeft()) + diameterAux(r->getRight()) + 1;

    int leftDiameter = diameterAux(r->getLeft());
    int rightDiameter = diameterAux(r->getRight());

    return ((diameter > leftDiameter) ? (diameter > rightDiameter ? diameter : rightDiameter) : (leftDiameter > rightDiameter ? leftDiameter : rightDiameter));
}
int BST::diameter()
{
    return diameterAux(root);
}
