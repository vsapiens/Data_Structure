#include <iostream>
using namespace std;
#include "Stack.h"
int main()
{
    stack<int> miPila;
    miPila.push(400);
    miPila.push(300);
    miPila.push(600);
    
    cout<<"La cantidad es: " <<miPila.size()<<endl;
    while (!miPila.empty()) {
        cout<<miPila.top()<<endl;
        miPila.pop();
    }
    
    return 0;
}
