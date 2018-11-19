/*
Operaciones Tipicas
insertar nodo
insertar arco
borrar nodo
borrar un arco
*/
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#define N 10
using namespace std;

void anchura(bool mat[20][20], int n)
{
    queue<int> fila;
    fila.push(0);
    vector<bool> vis(n, 0);
    vis[0] = true;
    int sale;
    while (!fila.empty())
    {
        sale = fila.front();
        fila.pop();
        cout << sale + 1 << " ";
        for (int i = 0; i < n; i++)
        {
            if (mat[sale][i] && !vis[i])
            {
                fila.push(i);
                vis[i] = true;
            }
        }
    }
    cout << endl;
}

void profundidad(bool mat[20][20], int n)
{
    stack<int> pila;
    pila.push(0);
    vector<bool> vis(n, 0);
    int sale;
    while (!pila.empty())
    {
        sale = pila.top();
        pila.pop();
        if (!vis[sale])
        {
            cout << (sale + 1) << " ";
            vis[sale] = true;
            for (int i = n - 1; i >= 0; i--)
            {
                if (!vis[i] && mat[sale][i])
                {
                    pila.push(i);
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    bool mat[20][20];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    profundidad(mat, n);
    anchura(mat, n);
}