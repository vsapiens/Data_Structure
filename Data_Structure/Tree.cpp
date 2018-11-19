#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void leeListAdj(vector<vector<int> > &listAdj, int e){
	int a, b;
	for (int i=0; i<e; i++){
		cin >> a >> b;
		listAdj[a-1].push_back(b-1);
	}
}

void printListAdj(vector<vector<int> > &listAdj, int e){
	for (int i=0; i<listAdj.size(); i++){
		cout << i << " ";
		for (int j=0; j< listAdj[i].size(); j++){
			cout << " - " << listAdj[i][j];
		}
		cout << endl;
	}
}

bool isTree(vector<vector<int> > &listAdj, int v){

    if(v > listAdj.size()-1)
        return false;
    
    int contVisit = 1;
    stack<int> pila;
    pila.push(true);
    int data;
    vector<bool> status(v, false);

    while (!pila.empty()) {
        data = pila.top();
        pila.pop();

        if (!status[data]) {
            status[data] = true;
            for (int i = listAdj[data].size() - 1; i >= 0; i--) {
                if (!status[listAdj[data][i]]) {
                    pila.push(listAdj[data][i]);
                    contVisit++;
                }
                else return false;
            }
        }

    }
    return contVisit == listAdj.size();
}

int main(){

	int v, e;
	cin >> v >> e;
	vector<vector<int> > listAdj(v);
	leeListAdj(listAdj, e);
	printListAdj(listAdj, v);

    if(isTree(listAdj, v))
	    cout << "YES" << endl;
    else cout << "NO" << endl;
	return 0;
}