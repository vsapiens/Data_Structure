//
//  LL_Humberto.hpp
//  Data_Structure
//
//  Created by Erick González on 9/6/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef LL_Humberto_hpp
#define LL_Humberto_hpp

#include <stdio.h>

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
    T get(int pos);
    T set(T data, int pos);
    bool change(int pos1, int pos2);
    int getSize();
    void print();
    LinkedList<T> split(int n);
    bool check();
    void operator =(LinkedList<T> Lista);
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
void LinkedList<T>::borraTodo(){
    Node<T> *curr = head;
    while (head != NULL){
        head = head->getNext();
        delete curr;
        curr = head;
    }
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
LinkedList<T>::~LinkedList(){
    borraTodo();
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return (size == 0);
    
    //    return (head == NULL);
}

template <class T>
void LinkedList<T>::addFirst(T data){
    head = new Node<T>(data, head);
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data){
    if (this->isEmpty()){
        this->addFirst(data);
    }
    else{
        Node<T> *curr = head;
        while (curr->getNext() != NULL){
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}

template <class T>
void LinkedList<T>::deleteFirst(){
    if (!this->isEmpty()){
        Node<T> *curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
}

template <class T>
void LinkedList<T>::deleteLast(){
    if (size <= 1){
        deleteFirst();
    }
    else{
        Node<T> *curr = head;
        while (curr->getNext()->getNext() != NULL){
            curr = curr->getNext();
        }
        delete curr->getNext();
        curr->setNext(NULL);
        size--;
    }
}

template <class T>
bool LinkedList<T>::add(T data, int pos){
    if (pos > size){
        return false;
    }
    if (pos == 0){
        addFirst(data);
    }
    else if (pos == size){
        addLast(data);
    }
    else{
        Node<T> *curr=head;
        for (int i=1; i<pos; i++){
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data,curr->getNext()));
        size++;
    }
    return true;
}

template <class T>
void LinkedList<T>::del(int pos){
    if (pos == 0){
        deleteFirst();
    }
    else if (pos == size-1){
        deleteLast();
    }
    else{
        Node<T> *curr = head;
        for (int i=1; i<pos; i++){
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
T LinkedList<T>::get(int pos){
    Node<T> *curr = head;
    for (int i=0; i<pos; i++){
        curr = curr->getNext();
    }
    return curr->getData();
}

template <class T>
T LinkedList<T>::set(T data, int pos){
    Node<T> *curr = head;
    for (int i=0; i<pos; i++){
        curr = curr->getNext();
    }
    T dataAux = curr->getData();
    curr->setData(data);
    return dataAux;
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2){
    if (pos1 < 0 || pos2 < 0 || pos1 >= size || pos2 >= size){
        return false;
    }
    if (pos1 == pos2){
        return true;
    }
    Node<T> *curr1 = head;
    
    int posMen = (pos1 < pos2 ? pos1 : pos2);
    int posMay = (pos1 > pos2 ? pos1 : pos2);
    
    /*    if (pos1 > pos2)
     posMay = pos1;
     else
     posMay = pos2;
     */
    for (int i=0; i<posMen; i++){
        curr1 = curr1->getNext();
    }
    Node<T> *curr2 = curr1;
    for (int i=posMen; i<posMay; i++){
        curr2 = curr2->getNext();
    }
    T dataAux = curr1->getData();
    curr1->setData(curr2->getData());
    curr2->setData(dataAux);
    return true;
}

template <class T>
int LinkedList<T>::getSize(){
    return size;
}

template <class T>
void LinkedList<T>::print(){
    Node<T> *curr = head;
    cout << "INICIO"<<endl;
    while (curr != NULL){
        cout << curr->getData()<< " ";
        curr = curr->getNext();
    }
    cout << endl<<"FIN"<<endl;
}

/*
 split
 Input: Número que determina la partición
 Process: divide la lista en 2, en caso de ser menor el tamaño se conserva la lista
 Output: La lista enncadenada modificada
 */
template <class T>
LinkedList<T> LinkedList<T>::split(int n)
{
    Node<T> *curr1 = head;
    Node<T> *curr2 = head;
    LinkedList<T> lista;
    int iCounter;
    //Excepciones a la regla
    if(size == 0 || size == 1 || size < n || size == n)
        return *this;
    //Llega hasta el penultimo para poder aterrizarlo a NULL
    for(int i  = 0; i< n-1;i++)
        curr1 = curr1->getNext();
    
    //Acomoda la lista encadenada original hasta la partición y nos da el apuntador a la segunda parte de la lista
    curr2 = curr1->getNext();
    curr1->setNext(nullptr);
    size = n;
    
    curr1 = curr2;
    lista.head = curr1;
    //Añade el primer nodo a la lista
    lista.addFirst(curr2->getData());
    //Añade todos los nodos a la lista
    while(curr2->getNext() != NULL)
    {
        curr2 = curr2->getNext();
        lista.addLast(curr2->getData());
        iCounter++;
    }
    curr2->setNext(nullptr);
    //Determina la size de la nueva lista
    lista.size = iCounter+1;
    
    //Regresa la lista
    return lista;
}

/*
 check
 Input: Nada
 Process: checa si la longitud concuerda con el size
 Output: True en caso de que sean verdad
 */
template <class T>
bool LinkedList<T>::check()
{
    //Apuntador a la head
    Node<T> *curr1 = head;
    
    if(head == NULL)
        return size == 0;
    
    int iCounter = 1;
    //Recorre toda la lista para verificar si
    while(curr1->getNext() != NULL)
    {
        curr1 = curr1->getNext();
        iCounter++;
    }
    return iCounter == this->size;
    
}
#endif /* LL_Humberto_hpp */
