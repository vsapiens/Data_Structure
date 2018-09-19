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

void pqResult(priority_queue<int,vector<int>,greater<int>> &pq,string d)
{
    int a,b;
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();
    pq.push(calculadora(b, a, d));
}
void qResult(queue<int> &q,string d)
{
    int a,b;
    a = q.front();
    q.pop();
    b = q.front();
    q.pop();
    q.push(calculadora(b, a, d));
}


void sResult(stack<int> &s,string d){
    int a,b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    s.push(calculadora(b, a, d));
}

int main()
{
string d,data;
getline(cin, data);
    while (data != "#")
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        queue<int> q;
        stack<int> s;
        
        stringstream ss;
        ss<< data;
        while (ss >> d)
        {
            
            if(d == "+"||d == "*"||d == "/"||d == "-")
            {
                pqResult(pq, d);
                qResult(q, d);
                sResult(s, d);
            }
            else{
            s.push(stoi(d));
            pq.push(stoi(d));
            q.push(stoi(d));
            }
        }
        cout<<s.top()<<" "<<q.front()<<" "<<pq.top()<<endl;
        
        
        getline(cin, data);
    }
    
    return 0;
}
