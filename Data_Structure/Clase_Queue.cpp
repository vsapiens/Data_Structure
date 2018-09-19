//
//  Clase_Queue.cpp
//  Data_Structure
//
//  Created by Erick González on 9/18/18.
//  Copyright © 2018 Erick González. All rights reserved.
//
#include "Clase_Queue.h"

#include <iostream>
using namespace std;
int main()
{
    queue<int> miPila;
    miPila.push(400);
    miPila.push(300);
    miPila.push(600);
    
    cout<<"La cantidad es: " <<miPila.size()<<endl;
    while (!miPila.empty()) {
        cout<<miPila.front()<<endl;
        miPila.pop();
    }
    
    return 0;
}
