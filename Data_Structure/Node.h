//
//  Node.h
//  Data_Structure
//
//  Created by Erick González on 8/21/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Node_h
#define Node_h

template <class T>
class Node
{
public:
    Node(T data){this->data=data;this->next = NULL;};
    Node(T data ,Node<T> *next){this->data= data;this->next= next;};
    T getData(){return this->data;};
    Node<T>* getNext(){return this->next;};
    void setData(T data){this->data= data;};
    void setNext(Node<T>* next){this->next= next;};
private:
    T data;
    Node<T> *next;
};
#endif /* Node_h */
