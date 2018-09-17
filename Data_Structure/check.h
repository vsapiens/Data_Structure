//
//  check.h
//  Data_Structure
//
//  Created by Erick González on 9/7/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef check_h
#define check_h
#include "LL_Humberto.hpp"

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

#endif /* check_h */
