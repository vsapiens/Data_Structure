#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

#define N 4

struct Node
{
    int index;
    char data;
    
    Node() {}
    
    Node(int i, char d)
    {
        index = i;
        data = d;
    }
    
    void setAtt(int i, char d)
    {
        index = i;
        data = d;
    }
};

struct SearchItem
{
    int graphIdx;
    int wordIdx;
    
    SearchItem() {}
    
    void setAtt(int g, int i)
    {
        graphIdx = g;
        wordIdx = i;
    }
};

void readBoard(vector<vector<Node> > &graph)
{
    char matrix[N][N];
    
    string input;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> input;
        
        for (int j = 0; j < N; ++j)
        {
            matrix[i][j] = input[j];
        }
    }
    
    int count = 0;
    Node node;
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j, ++count)
        {
            //First element is reserved to store the current's node data, stored as index -1
            node.setAtt(-1, matrix[i][j]);
            graph[count].push_back(node);
            
            if (i != N - 1)
            {
                node.setAtt(count + N, matrix[i + 1][j]);
                graph[count].push_back(node);
                
                if (j != N - 1)
                {
                    node.setAtt(count + 1, matrix[i][j + 1]);
                    graph[count].push_back(node);
                    
                    node.setAtt(count + N + 1, matrix[i + 1][j + 1]);
                    graph[count].push_back(node);
                }
                
                if (j != 0)
                {
                    node.setAtt(count - 1, matrix[i][j - 1]);
                    graph[count].push_back(node);
                    
                    node.setAtt(count + N - 1, matrix[i + 1][j - 1]);
                    graph[count].push_back(node);
                }
            }
            
            if (i != 0)
            {
                node.setAtt(count - N, matrix[i - 1][j]);
                graph[count].push_back(node);
                
                if (j != N - 1)
                {
                    node.setAtt(count + 1, matrix[i][j + 1]);
                    graph[count].push_back(node);
                    
                    node.setAtt(count - N + 1, matrix[i - 1][j + 1]);
                    graph[count].push_back(node);
                }
                
                if (j != 0)
                {
                    node.setAtt(count - 1, matrix[i][j - 1]);
                    graph[count].push_back(node);
                    
                    node.setAtt(count - N - 1, matrix[i - 1][j - 1]);
                    graph[count].push_back(node);
                }
            }
        }
    }
}

int calculateScore(string s)
{
    if (s.length() < 5)
        return 1;
    
    if (s.length() < 6)
        return 2;
    
    if (s.length() < 7)
        return 3;
    
    if (s.length() < 8)
        return 5;
    
    return 11;
}

bool hasMatch(const vector<vector<Node>> &graph, string w, int i)
{
    vector<bool> status(N * N, false);
    stack<SearchItem> s;
    
    int currWordIdx = 0, currGraphIdx;
    
    SearchItem item;
    
    //Set first element as a SearchItem object starting from i, at word index 0
    item.setAtt(i, 0);
    
    s.push(item);
    
    while (!s.empty())
    {
        currGraphIdx = s.top().graphIdx;
        currWordIdx = s.top().wordIdx;
        s.pop();
        
        status[currGraphIdx] = true;
        
        //Add all adjacent nodes to be processed
        for (int i = 1; i < graph[currGraphIdx].size(); ++i)
        {
            if (!status[graph[currGraphIdx][i].index])
            {
                //Check if the adjacent node has matching char
                if (graph[currGraphIdx][i].data == w[currWordIdx + 1])
                {
                    if (currWordIdx+1 == w.length()-1)
                        return true;
                    
                    item.setAtt(graph[currGraphIdx][i].index, currWordIdx + 1);
                    s.push(item);
                }
            }
        }
    }
    
    return false;
}

int playBoggle(const vector<vector<Node>> &graph, string w)
{
    for (int i = 0; i < N * N; i++)
    {
        if (graph[i][0].data == w[0])
        {
            if (hasMatch(graph, w, i))
            {
                return calculateScore(w);
            }
        }
    }
    
    return 0;
}

int main()
{
    int games;
    cin >> games;
    
    int words, score = 0;
    
    for (int i = 0; i < games; ++i)
    {
        vector<vector<Node>> graph(N * N);
        
        readBoard(graph);
        cin >> words;
        
        for (int j = 0; j < words; ++j)
        {
            string w;
            cin >> w;
            score += playBoggle(graph, w);
        }
        
        cout << "Game " << i + 1 << ": " << score << endl;
        score = 0;
    }
    
    return 0;
}
