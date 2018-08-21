#include <iostream>

using namespace std;

int burbuja(int a[], int n)
{
    bool interruptor = true;
    int tmp = 0, iCompare = 0;
    for (int pasada=0; pasada<n-1 && interruptor; pasada++) {
        interruptor = false;
        // no se han hecho intercambios
        for (int j=0; j<n-1-pasada; j++) {
            iCompare++;
            if (a[j+1] < a[j]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                interruptor = true;
            }
        }
    }
    return iCompare;
}


int ordInsercion (int a[], int n)
{
    int i, j, aux, iCompare =0;
    for (i = 1; i < n; i++) //  El índice j explora sublista a[i-1]..a[0] buscando posición correcta del elemento destino, para asignarlo en a[j]
    {      j = i;
        iCompare++;
        bool iFirst = true;
        aux = a[i]; // se localiza el punto de inserción explorando hacia abajo
      while (j > 0 && aux < a[j-1]) //  desplazar elementos hacia arriba para hacer espacio
        {
            if(!iFirst)
            {
                iCompare++;
            }
            a[j] = a[j-1];
            j--;
            iFirst = false;
        }
        a[j] = aux;
        
    }
        return iCompare;
}

int main()
{
    int iNumber = 0, a[10000], b[10000], iBurbuja, iInsert;
    cin>> iNumber;
    bool descending = true;
    for(int iCounter = 0; iCounter < iNumber; iCounter++)
    {
        cin>>a[iCounter];
        b[iCounter] = a[iCounter];
        if(a[iCounter]>a[iCounter-1] && iCounter != 0) descending = false;
        
    }
    
    iBurbuja = burbuja(a, iNumber);
    
    iInsert = ordInsercion(b, iNumber);
    
 //  cout<<"Bubble: " <<iBurbuja<<endl;
// cout<<"Insert: " <<iInsert<<endl;
    
    if(iBurbuja<iInsert)
        cout<<"BUBBLE"<<endl;
    else if(iBurbuja>iInsert)
        cout<<"INSERTION"<<endl;
    else if(iBurbuja == iInsert || !descending)
        cout<<"EQUAL"<<endl;
    
    return 0;
}
