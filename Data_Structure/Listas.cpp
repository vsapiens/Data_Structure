#include <iostream>

using namespace std;

template<typename T>
class List {
public:
    
    int getCant() {return iCant;};
    T getDato(int n){return arrDatos[n];};
    bool add(T dato);
    bool del(T dato);
    int search(T a);
    void sort(bool bTrue);
    void print();
    void operator =(T &a)
    {
        for(int i = 0; i<iCant; i++)
            this->arrDatos[i]= arrDatos[i];
        
    };
    bool operator ==(T a)
    {
        
        
    };
    List():iCant(0) {};
    
private:
    T arrDatos[10];
    int iCant;
};


int main()
{
    
    
    
    
    return 0;
}
