//
//  Header.h
//  Data_Structure
//
//  Created by Erick González on 9/7/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include "LL_Humberto.hpp"
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
    int iCounter = 0;
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
#endif /* Header_h */
