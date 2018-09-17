#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <stack>

using namespace std;


int calculadora(int x, int y, string d)
{
    
    if(d == "+")
        return x+y;
        
    else if(d == "-")
        return x-y;
            
    else if(d == "/")
        return x/y;
                
    else if(d == "*")
        return x*y;
    
    return NULL;
}

void pqResult(priority_queue<int> &pq,string d)
{
    int a,b;
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();
    if(d == "+")
    {
        return
        
    }
    
    else if(d == "-")
    
    else if(d == "/")
    
    else if(d == "*")
    
}

void qResult(queue<int> &q,string d);

void sResult(stack<int> &s,string d);

int main()
{
string d,data;
getline(cin, data);
    int a,b;
    while (data != "#")
    {
        priority_queue<int> pq;
        queue<int> q;
        stack<int> s;
        
        stringstream ss;
        ss<< data;
        while (ss >> d)
        {
            
            if(d == "+"||d == "*"||d == "/"||d == "-")
            {
                
                
            }
            else{
            s.push(stoi(d));
            pq.push(stoi(d));
            q.push(stoi(d));
            }
        }
        getline(cin, data);
    }
    
    return 0;
}
