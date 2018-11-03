/* Constructor de Default – Fila vacía con prioridad de mayor valor
• Constructor con un parametro(prioridad) – Recibe un valor booleano
    si es true la prioridad es mayor valor si es falso la prioridad es menor
    valor.
• push – Mete un entero a la fila
• pop – Saca un entero de la fila
• top – Observa el entero con la mas alta prioridad
• size – Regresa el tamaño de la fila
• empty – Regresa verdadero si la fila esta vacía y falso en caso contrario
 */
#include <vector>
class Heap
{

  public:
    Heap();
    Heap(bool bPriority);
    bool push(int dato);
    bool pop(int dato);

    int top()
    {
        if (!vHeap.empty())
            return vHeap[0];
        return -1;
    };

    int size() { return vHeap.size(); };
    bool empty() { return vHeap.empty(); };

  private:
    std::vector<int> vHeap;
    bool bPriority;
    bool deleteRoot(std::vector<int> vHeap);
};

Heap::Heap()
{
    bPriority = true;
}
Heap::Heap(bool bPriority)
{
    this->bPriority = bPriority;
}

bool Heap::push(int dato)
{
}

bool Heap::deleteRoot(std::vector<int> vHeap)
{

    std::swap(vHeap[0], vHeap[vHeap.size() - 1]);
    vHeap.pop_back();
}
bool deleteData(std::vector<int> vHeap, int iPos)
{
}

bool Heap::pop(int dato)
{
    if (dato == vHeap[0])
        return deleteRoot(vHeap);

    for (int i = 0; i < vHeap.size(); i++)
    {
        if (vHeap[i] == dato)
            return deleteData(vHeap, i);
    }
    return false;
}
