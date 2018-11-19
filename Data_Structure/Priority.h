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
    void push(int dato);
    void pop(int dato);

    int top()
    {
        if (!vHeap.empty())
            return vHeap[1];
        return -1;
    };

    int size() { return vHeap.size() - 1; };
    bool empty() { return vHeap.empty(); };

  private:
    std::vector<int> vHeap;
    bool bPriority;
    void deleteRoot(std::vector<int> vHeap);
    bool checkGreater(int a, int b);
};

Heap::Heap()
{
    bPriority = true;
}
Heap::Heap(bool bPriority)
{
    this->bPriority = bPriority;
}

void Heap::push(int dato)
{
    if (vHeap.empty())
    {
        vHeap.at(1) = dato;
        return;
    }

    vHeap.push_back(dato);
    int n = vHeap.size();

    while (n / 2 >= 0 && (vHeap[n] > vHeap[n / 2]))
    {
        std::swap(vHeap[n], vHeap[n / 2]);
        n /= 2;
    }
}

bool Heap::checkGreater(int a, int b)
{
    return this->bPriority ? a > b : a < b;
}

void Heap::pop(int dato)
{
    std::swap(vHeap[1], vHeap[vHeap.size() - 1]);
    vHeap.pop_back();

    for (int i = 0; i < vHeap.size() / 2; ++i)
    {

        if (checkGreater(vHeap[i * 2 - 1], vHeap[i * 2]))
        {
            if (!checkGreater(vHeap[i], vHeap[i * 2 - 1]))
                std::swap(vHeap[i], vHeap[i * 2 - 1]);
        }
        else
        {
            if (!checkGreater(vHeap[i], vHeap[i * 2]))
                std::swap(vHeap[i], vHeap[i * 2]);
        }
    }
}
