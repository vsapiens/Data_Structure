//
//  LL_Humberto.cpp
//  Data_Structure
//
//  Created by Erick González on 9/6/18.
//  Copyright © 2018 Erick González. All rights reserved.
//
#include <iostream>
using namespace std;
#include "LL_Humberto.hpp"



int main(){
    LinkedList<string> miLista;
    
    miLista.addFirst("HOLA");
    miLista.addFirst("CRAYOLA");
    miLista.addLast("TIEMPO");
    miLista.add("ULTIMO", 2);
    /*    for (int i=0; i<miLista.getSize(); i++){
     cout << miLista.get(i)<<" ";
     }*/
    //    miLista.print();
    //    miLista.deleteFirst();
    //    miLista.print();
    //    miLista.deleteLast();
    //    miLista.print();
    //    miLista.deleteAll();
    //    miLista.print();
    //    miLista.addLast("YA");
    miLista.print();
    miLista.change(1,2);
    miLista.print();
    cout << "Salida: "<<miLista.set("ED",3)<<endl;
    miLista.print();
    
    LinkedList<int> *tuLista = new LinkedList<int>();
    tuLista->addLast(10);
    tuLista->addFirst(7);
    tuLista->addLast(500);
    tuLista->add(15,1);
    tuLista->print();
    delete tuLista;
    
    
    
}
