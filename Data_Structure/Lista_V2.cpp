
#include <iostream>

using namespace std;

template <class T>
class Lista {
public:
    Lista();
    Lista(Lista<T> *lista);
    int getCant();
    T getDato(int indice);
    bool add(T dato);
    bool del(T dato);
    int search(T dato);
    void sort(bool ascendiente);
    void operator=(Lista<T> lista);
    bool operator==(Lista<T> lista);
    void print();
    
private:
    T arrDatos[10] = { false };
    int iCant;
};

template <class T>
Lista<T>::Lista() {
    this->iCant = 0;
}

template <class T>
int Lista<T>::getCant() {
    return iCant;
}

template <class T>
void Lista<T>::operator=(Lista<T> lista) {
    for(int i = 0; i < iCant; i++) {
        arrDatos[i] = lista->arrDatos[i];
    }
}

template <class T>
Lista<T>::Lista(Lista<T> *lista) {
    iCant = lista->getCant();
    
    arrDatos = lista->arrDatos;
}

template <class T>
T Lista<T>::getDato(int indice) {
    return arrDatos[indice];
}

template <class T>
bool Lista<T>::add(T dato) {
    bool agregar = false;
    
    for(int i = 0; i < this->getCant(); i++) {
        if(arrDatos[i] != 0) {
            agregar = true;
            arrDatos[iCant] = dato;
            iCant++;
        }
    }
    
    return agregar;
}

template <class T>
bool Lista<T>::del(T dato) {
    bool encontrado = false;
    
    for(int i = 0; i < iCant; i++) {
        if(arrDatos[i] == dato)
            encontrado = true;
        arrDatos[i] = 0;
        iCant--;
    }
    
    if(encontrado) {
        for(int i = 0; i < iCant; i++) {
            if(arrDatos[i] == 0 && arrDatos[i + 1] != 0)
                arrDatos[i] = arrDatos[i + 1];
        }
    }
    
    return encontrado;
}

template <class T>
int Lista<T>::search(T dato) {
    int posicion = -1;
    
    for(int i = 0; i < iCant; i++) {
        if(arrDatos[i] == dato)
            posicion = i;
    }
    
    return posicion;
}

template <class T>
void Lista<T>::sort(bool ascendiente) {
    T dato;
    
    if(ascendiente) {
        for(int i = 0; i < iCant; i++) {
            if(arrDatos[i] > arrDatos[i + 1]) {
                dato = arrDatos[i + 1];
                arrDatos[i + 1] = arrDatos[i];
                arrDatos[i] = dato;
            }
        }
    }
    else {
        for(int i = 0; i < iCant; i++) {
            if(arrDatos[i] < arrDatos[i + 1]) {
                dato = arrDatos[i];
                arrDatos[i] = arrDatos[i + 1];
                arrDatos[i + 1] = dato;
            }
        }
    }
}

template <class T>
bool Lista<T>::operator==(Lista<T> lista) {
    bool igual = true;
    
    sort(true);
    lista.sort(true);
    
    for(int i = 0; i < iCant; i++) {
        if(arrDatos[i] != lista.arrDatos[i])
            igual = false;
    }
    
    return igual;
}

template <class T>
void Lista<T>::print() {
    for (int i = 0; i < iCant; i++)
        cout << i << " - " << arrDatos[i] << endl;
}

int main()
{
    Lista<int> Numero,Num;
    
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
    cout << Numero.search(4)<<endl;
    
    // Test Case #5:
    Num.sort(!bTest);
    Numero.sort(!bTest);
    
    //Test Case 6:
    if(Num == Numero)
        cout<<"Son iguales"<<endl;
    return 0;
}


