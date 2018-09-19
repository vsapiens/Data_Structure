#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

void performPostfix(const string d, stack<int>& s1, queue<int>& q1, priority_queue<int, vector<int>, greater<int> >& pq1) {
    int xS, xQ, xPQ, yS, yQ, yPQ, resultS, resultQ, resultPQ;
    
    xS = s1.top(); // x stack
    s1.pop();
    
    yS = s1.top(); // y stack
    s1.pop();
    
    xQ = q1.front(); // x queue
    q1.pop();
    
    yQ = q1.front(); // y queue
    q1.pop();
    
    xPQ = pq1.top(); // x priority queue
    pq1.pop();
    
    yPQ = pq1.top(); // y priority queue
    pq1.pop();
    
    if(d == "-") {
        resultS = yS - xS;
        resultQ = yQ - xQ;
        resultPQ = yPQ - xPQ;
        
    }
    else if(d == "+") {
        resultS = yS + xS;
        resultQ = yQ + xQ;
        resultPQ = yPQ + yPQ;
    }
    else if(d == "*") {
        resultS = yS * xS;
        resultQ = yQ * xQ;
        resultPQ = yPQ * xPQ;
    }
    
    s1.push(resultS);
    q1.push(resultQ);
    pq1.push(resultPQ);
}

void printContainers(stack<int> s1, queue<int> q1, priority_queue<int, vector<int>, greater<int> > pq1) {
    while(!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    
    while(!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    
    while(!pq1.empty()) {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    
    cout << endl;
}

int main () {
    int start_s=clock();
    string d, data;
    
    getline(cin, data);
    
    while (data != "#"){
        stack<int> s1;
        queue<int> q1;
        priority_queue<int, vector<int>, greater<int> > pq1;
        
        stringstream ss;
        
        ss << data;
        
        while (ss >> d) {
            int num;
            
            if(istringstream(d) >> num) { //si es un número lo mete al contenedor
                s1.push(num);
                q1.push(num);
                pq1.push(num);
            }
            else {
                performPostfix(d, s1, q1, pq1);
            }
        }
        
        printContainers(s1, q1, pq1);
        getline(cin, data);
    }
    
    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}

