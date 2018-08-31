//
//  Lista.h
//  Data_Structure
//
//  Created by Erick González on 8/21/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Lista_h
#define Lista_h

using namespace std;
template<typename T>
class List {
public:
    List();
    List(List<T> &dato);
    int getCant() {return iCant;};
    T getDato(int n){return arrDatos[n];};
    bool add(T dato);
    bool del(T dato);
    int search(T a);
    void sort(bool bTrue);
    void print();
    bool operator =(List<T> &dato);
    bool operator ==(List<T> dato);
    
private:
    T arrDatos[10];
    int iCant;
};

template<typename T>
bool List<T>::operator ==(List<T> dato)
{
    {
        if(this->iCant == 0 || this->iCant != dato.getCant() ||dato.getCant() == 0 )
            return false;
        
        for(int i = 0; i<iCant; i++)
        {
            if(this->arrDatos[i] != dato.arrDatos[i])
                return false;
        }
        
        return true;
}
}

template<typename T>
List<T>::List():iCant(0){
    
    for(int i = 0; i<10; i++)
        arrDatos[i]= *new T;
};


template<typename T>
List<T>::List(List<T> &dato)
{
    this->iCant = dato.getCant();
    
    for(int i = 0; i<iCant; i++)
        this->arrDatos[i] = dato.arrDatos[i];
    
};
template<typename T>
bool List<T>::operator =(List<T> &dato)
{
    if(iCant ==  0)
        return false;

    this->arrDatos = dato.arrDatos;
    iCant = dato.getCant();
    
    return true;
}

    
template<typename T>
bool List<T>::add(T dato)
{
    if(iCant<10)
    {
        this->arrDatos[iCant] = dato;
        this->iCant++;
        return true;
    }
    
    return false;
}

template<typename T>
bool List<T>::del(T dato)
{
    bool bFound = false;
    
    if(iCant == 0)
        return false;
    
    for(int i = 0; i<iCant; i++)
    {
        if(arrDatos[i] == dato)
        {
            bFound = true;
            arrDatos[i] = arrDatos[i+1];
            iCant--;
        }
    
    }
    
    if(bFound)
        return true;
    /*
    if(bFound && (j+1 != iCant))
    {
    for(int i = j; i < iCant; i++)
    {
        this->arrDatos[i] = this->arrDatos[i+1];
    }
        this->iCant--;
        return true;
    }
    if (bFound && (j+1 == iCant))
    {
        
         for(int i = j; i < iCant; i++)
        this->arrDatos[i] = this->arrDatos[i+1];
    }
    */
    return false;
}


template<typename T>
void List<T>::sort(bool bTrue)
{
    bool inter = true;
    int n = iCant;
     T tmp;
        
        for (int pasada=0; pasada<n-1 && inter; pasada++)
        {
            inter = false;
                    // no se han hecho intercambios
            for (int j=0; j<n-1-pasada; j++)
            {
                if (arrDatos[j+1] < arrDatos[j])
                {
                    tmp = arrDatos[j];
                    arrDatos[j] = arrDatos[j+1];
                    arrDatos[j+1] = tmp;
                    inter = true;
                }
            }
        }
    
    List<T> tmp1;
    
    if(!bTrue)
    {
        for(int i = 0; i<iCant; i++)
        tmp1.arrDatos[iCant-i-1]= this->arrDatos[i];
        
        for(int i = 0; i<iCant; i++)
        this->arrDatos[i] = tmp1.arrDatos[i];

    }
    
}

template<typename T>
void List<T>::print()
{
    for(int i = 0; i<iCant; i++)
        cout<<i<<" - "<<this->arrDatos[i]<<endl;
}


template<typename T>
int List<T>::search(T dato)
{
    for(int i = 0; i<iCant; i++)
    {
        if(this->arrDatos[i] == dato)
            return i;
    }
    return -1;
}

#endif /* Lista_h */
