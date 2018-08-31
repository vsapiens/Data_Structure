#include <iostream>

using namespace std;

#include "Lista.h"

int main()
{
    List<int> Numero, Num;
   
    bool bTest = true,a, b;
    
    //Test Case 1:
    Numero.add(1);
    Numero.add(2);
    Numero.add(3);
    Numero.add(4);
    
    //Test Case 2:
    Num.add(4);
    Num.add(1);
    Num.add(2);
    Num.add(5);
    
    //Test Case 3:
    a = Numero.del(0);
    b = Numero.del(3);
    
   //Test Case 4:
    cout<<Numero.search(4)<<endl;
    
    // Test Case #5:
    Num.sort(!bTest);
    Numero.sort(!bTest);
    
    //Test Case 6:
    if(Num == Numero)
        cout<<"Son iguales"<<endl;
    
    
    return 0;
}
