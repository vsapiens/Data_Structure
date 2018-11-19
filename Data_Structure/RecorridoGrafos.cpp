#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#define N 10

using namespace std;

void iniMatAdj(bool matAdj[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)

        {
            matAdj[i][j] = false;
        }
    }
}

void leeMatAdj(bool matAdj[N][N], int e)
{

    int a, b;
    for (int i = 1; i <= e; i++)
    {
        cin >> a >> b;
        matAdj[a - 1][b - 1] = matAdj[b - 1][a - 1] = true;
    }
}

void printMatAdj(bool matAdj[N][N], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)

        {
            cout << (matAdj[i][j] ? "T" : "F") << "\t";
        }
        cout << endl;
        ;
    }
}

void BFS(bool matAdj[N][N], int v)
{
    queue<int> fila;
    fila.push(0);
    int data;
    vector<bool> status(v, false);
    status[0] = true;
    while (!fila.empty())
    {
        data = fila.front();
        fila.pop();
        cout << (data + 1) << " ";
        for (int j = 0; j < v; j++)
        {
            if (matAdj[data][j] && !status[j])
            {
                fila.push(j);
                status[j] = true;
            }
        }
    }
    cout << endl;
}


void leeListAdj(vector<vector<int> > &listAdj, int e) {
    int a, b;

    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        listAdj[a - 1].push_back(b - 1);
        listAdj[b - 1].push_back(a - 1);
    }
}

void printListAdj(vector<vector<int> > listAdj) {
    for (int i = 0; i < listAdj.size(); i++) {
        cout << i << " ";
        for (int j = 0; j < listAdj[i].size(); j++) {
            cout << " - " << listAdj[i][j];
        }

        cout << endl;
    }
}

void DFS(vector<vector<int> > &listAdj, int v) {
    stack<int> pila;
    pila.push(0);
    int data;
    vector<bool> status(v, false);

    while (!pila.empty()) {
        data = pila.top();
        pila.pop();

        if (!status[data]) {
            cout << (data + 1) << " ";
            status[data] = true;

            for (int i = listAdj[data].size() - 1; i >= 0; i--) {
                if (!status[listAdj[data][i]]) {
                    pila.push(listAdj[data][i]);
                }
            }
        }
    }

    cout << endl;
}

int main()
{

    bool matAdj[N][N];
    int v, e;
    cin >> v >> e;
   // vector<vector<int> > listAdj(v);
    //leeListAdj(listAdj,e);
    iniMatAdj(matAdj);
    leeMatAdj(matAdj, e);
    printMatAdj(matAdj, v);
    BFS(matAdj, v); 
    //printListAdj(listAdj);
    //DFS(listAdj,v);
    return 0;
}