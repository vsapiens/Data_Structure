#include <iostream>
using namespace std;
#include "BST_main.h"
int main()
{
    BST miArbol;
    miArbol.add(12);
    miArbol.add(100);
    miArbol.add(50);
    miArbol.add(1);
    miArbol.add(65);
    miArbol.print(1);
    cout << endl;
    cout << miArbol.height() << endl;
    miArbol.ancestors(1);
    miArbol.whatLevelamI(1);
    return 0;
}
