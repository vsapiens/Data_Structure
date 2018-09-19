#ifndef Queue_h
#define Queue_h
#include "Node.h"
template<typename T>
class queue{
public:
    queue();
    ~queue();
    
    T front();
    void push(T data);
    void pop();
    int size(){return tam;};
    bool empty(){return final == nullptr;};
    
private:
    Node<T> *final;
    int tam;
};


template<typename T>
queue<T>::queue():final(nullptr),tam(0){};

template<typename T>
queue<T>::~queue(){
    if(final!= nullptr)
    {
        Node<T> *curr = final->getNext();
        final->setNext(nullptr);
        final = curr;
        while(final !=nullptr)
            final = final->getNext();
        delete curr;
        curr = final;
        
    }
    
    
};


template<typename T>
T queue<T>::front(){
    return final->getNext()->getData();
};


template<typename T>
void queue<T>::pop(){
    Node<T> *curr = final->getNext();
    
    if (final->getNext() == final){
        final = nullptr;
    }
    else{
        final->setNext(curr->getNext());
    }
    delete curr;
    --tam;
};
template<typename T>
void queue<T>::push(T dato){
    if (final == nullptr){
        final = new Node<T>(dato);
        final->setNext(final);
    }
    else{
        final->setNext(new Node<T>(dato,final->getNext()));
        final = final->getNext();
    }
    ++tam;
    
};


#endif /* Queue_h */
