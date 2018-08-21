#include <iostream>
using namespace std;



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

int main()
{
    
    
    
    
    return 0;
}
