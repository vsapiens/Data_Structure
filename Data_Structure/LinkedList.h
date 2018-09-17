//
//  LinkedList.h
//  Data_Structure
//
//  Created by Erick González on 8/21/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"

template <class T>
class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    bool isEmpty();
    void addFirst(T data);
    void addLast(T data);
    bool add(T data, int pos);
    void deleteFirst();
    void deleteLast();
    void del(int pos);
    int deleteAll();
    T get(int n);
    T set(T dato, int pos);
    bool change(int pos1, int pos2);
    void print();
    bool operator ==(LinkedList<T> dato);
    void operator +=(T d);
    void operator +=(LinkedList<T> dato);
    void operator =(LinkedList<T> dato);
    LinkedList(LinkedList<T> const &lista);
    void reverse();
    void shift(int n);
    void spin(int n);
    ~LinkedList();
    
private:
    Node<T> *head;
    int size;
    void borraTodo();
};

template <class T>
LinkedList<T>::LinkedList(){
    head = NULL;
    size = 0;
}
template <class T>
LinkedList<T>::~LinkedList()
{
    borraTodo();
}

template <class T>
void LinkedList<T>::borraTodo(){
    Node<T> * curr = head;
    while(head != NULL){
        head = head->getNext();
        delete curr;
        curr = head;
    }
}

template <class T>
LinkedList<T>::~LinkedList(){
    borraTodo();
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return (size == 0);
    
    // return(head == NULL);
}

template <class T>
void LinkedList<T>::addFirst(T data){
    head = new Node<T>(data, head);
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data){
    if(this->isEmpty()){
        this->addFirst(data);
    }
    else{
        Node<T> *curr = head;
        while(curr->getNext() != NULL){
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}

template <class T>
void LinkedList<T>::deleteFirst(){
    if(!this-isEmpty()){
        Node<T> *curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
}

template <class T>
void LinkedList<T>::deleteLast(){
    if(size <= 1){
        deleteFirst();
    }
    else{
        Node<T> *curr = head;
        while(curr->getNext()->getNext() != NULL){
            curr = curr->getNext();
        }
        delete curr->getNext();
        curr->setNext(NULL);
        size--;
    }
}

template <class T>
bool LinkedList<T>::add(T data, int pos){
    if(pos > size){
        return false;
    }
    if(pos == 0){
        addFirst(data);
    }
    else if(pos == size){
        addLast(data);
    }
    else{
        Node<T> *curr = head;
        for(int i = 1; i < pos; i++){
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
        size++;
    }
    
    return true;
}

template <class T>
void LinkedList<T>::del(int pos){
    if(pos == 0){
        deleteFirst();
    }
    else if(pos == size-1){
        deleteLast();
    }
    else{
        Node<T> *curr = head;
        for(int i = 1; i < pos; i++){
            curr = curr->getNext();
        }
        Node<T> *temp = curr->getNext();
        curr->setNext(temp->getNext());
        delete temp;
        size--;
    }
}

template <class T>
int LinkedList<T>::deleteAll(){
    borraTodo();
    int cant = size;
    size = 0;
    return cant;
}


template <class T>
T LinkedList<T>::get(int posicion)
{
    Node<T> *curr = head;
    
    
        for (int i = 0; i < posicion; ++i)
            curr= curr->getNext();
        
        return  curr->getData();
}

template <class T>
T LinkedList<T>::set(T dato, int pos) {
  
    Node<T> *curr = head;
    
    for(int i = 0; i < pos; i++)
        curr = curr->getNext();
    
    T datoAnt = curr->getData();
    curr->setData(dato);
    
    return datoAnt;
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2) {
    
    Node<T> *node1 = head, *node2 = head, *node3 = NULL;
    
    //for(int i = 0; i < pos1; i++)
    //  node1 = node1->getNext();
    
    
    T dato1,dato2;
    
    //for(int i = 0; i < pos2; i++)
    //  node2 = node2->getNext();

    int posMen = (pos1 < pos2 ? pos1 : pos2);
    int posMay = (pos1 > pos2 ? pos1 : pos2);
    
    
    for(int i = 0; i < posMen; i++)
        node1 = node1->getNext();
    
        node2 = node1;
    
    for(int i = posMen; i < posMay; i++)
        node2 = node2->getNext();
    
    T dataAux = node1->getData();
    node1->setData(node2->getData());
    
    node2->setData(dataAux);
    return true;
}

template <class T>
void LinkedList<T>::print()
{
    
    Node<T> *curr = head;
    
    while(curr != NULL){
        
        std::cout<< curr->getData()<<" ";
        curr = curr->getNext();
    }
    std::cout<<std::endl;
}

/*
 
 • reverse : Invierte el contenido de la lista encadenada.
 • shift(int) : hace un corrimiento de int casillas en la lista encadenada. Si int
 es 2, la cero pasa a ser la 2 , la 1 la 3 y así en forma circular. Si int es -1
 la cero pasa a ser la última, la 1 la cero y así sucesivamente.
 • spin(int) : Realiza reverse intermedios por cada int elementos.
 • operator == : Revisa si dos listas encadenadas tienen el mismo
 contenido y en el mismo orden.
 • operator+= (T d) : Apendiza la información al final de la lista encadenada.
 • operator+= (LinkedList<T> l) : Apendiza toda la info de la lista
 endadenada l, al final de la lista encadenada.
 • LinkedList(LinkedList l) : Copy Constructor.
 • operator = : Asigna una lista encadenada complete
 */
template <class T>
bool LinkedList<T>::operator ==(LinkedList<T> Lista)
{
    
    Node<T> *curr = head;
    if (this->size != Lista.size)
        return false;
    else
    {
        for(int i = 0; i < size ; i++ )
        {
            if(curr->getData() != Lista.get(i))
                return false;
            
        }
        return true;
    }
    
}

template <class T>
void LinkedList<T>::operator +=(T d)
{
    addLast(d);
}
template <class T>
void LinkedList<T>::operator +=(LinkedList<T> lista)
{
     Node<T> *curr = head;
    while(curr->getNext() != NULL)
        curr = curr->getNext();
    
    curr->setNext(lista.head);
    size += lista.size;
}
template <class T>
void LinkedList<T>::operator =(LinkedList<T> Lista)
{
    deleteAll();
    Node<T> *curr1 = head;
    Node<T> *curr2 = Lista.head;
    
    while(curr2->getNext()!= NULL)
        curr1->setNext(curr2->getNext());
    
    curr2->setNext(nullptr);
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T> const &lista)
{
    *this = lista;
}    
template <class T>
void LinkedList<T>::reverse()
{
    Node<T> *curr1 = head;
    Node<T> *curr2 = curr1->getNext();
    curr1->setNext(nullptr);
    while(curr2->getNext()!= NULL)
    {
        head = curr2;
        curr2 =  curr2->getNext();
        head->setNext(curr1);
        curr1 = head;
    }
}
template <class T>
void LinkedList<T>::shift(int n)
{
    Node<T> *curr1 = head;
    n = n % size;
    
    for(int i = 0; i< n-1; i++)
        curr1 = curr1->getNext();

    Node<T> *curr2 = curr1;
    
    while(curr2->getNext()!= NULL)
        curr2 =curr2->getNext();
    
    
    curr2->setNext(head);
    head = curr1->getNext();
    curr1->setNext(NULL);
}

template <class T>
void LinkedList<T>::spin(int n)
{
    if(n>= size){
        reverse();
    }
    else if(n > 1){
        
        int iTimes = size /n;
        int extraNodes = size % n;
        Node<T> *curr,*prev,*next,*first,*head2;
        
        first = head;
        prev = head;
        next = head->getNext();
        for(int i = 0; i<n-1;i++)
        {
            head = next;
            next = next->getNext();
            head->setNext(prev);
            prev = head;
        }
        first->setNext(next);
        for(int i = 0; i<iTimes-1;i++)
        {
            prev = next;
            head2 = next;
            curr = prev;
            next = next->getNext();
            for(int j = 0; j<n-1;j++)
            {
                curr = next;
                next = next->getNext();
                curr->setNext(prev);
                prev = curr;
            }
            first->setNext(curr);
            head2->setNext(next);
            first = head2;
        }
            prev = next;
            head2 = next;
            curr = prev;
            next = next->getNext();
        
        for(int i = 0; i<extraNodes-1;i++)
        {
            curr = next;
            next = next->getNext();
            curr->setNext(prev);
            prev = curr;
        }
        first->setNext(curr);
        head2->setNext(nullptr);
    }
    
    /*
    Node<T> *curr1 = head;
    Node<T> *curr2 = head->getNext();
    Node<T> *curr3 = head;
    n=size/3;
    
    for(int i = 0; i > n; i++)
    {
    curr2->setNext(curr1);
    curr1= curr1->getNext();
    curr2 =curr2->getNext();
    }
    head = curr1;
    while(curr2->getNext()!= NULL)
    {
        
    }
    */
}


#endif /* LinkedList_h */
