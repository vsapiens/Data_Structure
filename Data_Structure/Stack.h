
#include "Node.h"
#ifndef Stack_h
#define Stack_h
template<class T>
class stack{
public:
    stack();
    ~stack();
    
    void push(T data);
    void pop();
    T top(){return tope->getData();};
    int size(){return tam;};
    bool empty(){return tope == nullptr;};
    
private:
    Node<T> *tope;
    int tam;
    
};

template<class T>
stack<T>::stack():tam(0),tope(nullptr){};


template<class T>
stack<T>::~stack()
{
    Node<T> *curr = tope;
    while (tope != nullptr){
        tope = tope->getNext();
        delete curr;
        curr = tope;
    }
}

template<class T>
void stack<T>::push(T data)
{
    tope = new Node<T>(data,tope);
    ++tam;
}

template<class T>
void stack<T>::pop()
{
    Node<T> *curr = tope;
    tope = tope->getNext();
    delete curr;
    --tam;
}
#endif
