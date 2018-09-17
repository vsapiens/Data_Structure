//
//  Queue.cpp
//  Data_Structure
//
//  Created by Erick González on 9/14/18.
//  Copyright © 2018 Erick González. All rights reserved.
//
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
struct punto
{
    int x,y;
    bool operator <(const punto &otro) const{
        if(x == otro.x)
            return y > otro.y;
        return x < otro.x;
    }
};

int main()
{
    queue<int> q1;
    stack<int> s1;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
     priority_queue<punto> pq3;
    int n, dato;
    cin>>n;
    
 /*   for(int i =1; i <=n; i++)
    {
        cin>>dato;
        q1.push(dato);
        s1.push(dato);
        pq1.push(dato);
        pq2.push(dato);
    }
    
    cout<<endl<<"La fila es: ";
    while(!q1.empty()){
        cout<<q1.front()<< " ";
        q1.pop();
    }
    cout<<endl<<"La pila es: ";
    while(!s1.empty()){
        cout<<s1.top()<< " ";
        s1.pop();
    }
    cout<<endl<<"La fila priorizada es: ";
    while(!pq1.empty()){
        cout<<pq1.top()<< " ";
        pq1.pop();
    }
    cout<<endl<<"La fila priorizada mayor es: ";
    while(!pq2.empty()){
        cout<<pq2.top()<< " ";
        pq2.pop();
    }
    cout<<endl;*/
    punto aux;
    for(int i = 0 ; i <n;i++)
    {
        cin>>aux.x>>aux.y;
        pq3.push(aux);
    }
    cout<<endl<<"La fila priorizada punto es: ";
    while(!pq3.empty()){
        aux =pq3.top();
        cout<<aux.x<< "-"<<aux.y<<endl;
        pq3.pop();
    }
    
}
