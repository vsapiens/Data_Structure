#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#define N 4

using namespace std;
struct Puzzle{
    char cLetter;
    int index;
    Puzzle()
    {
        this->cLetter = '-';
        this->index = 0;
    }
    Puzzle(int index, char cLetter)
    {
        this->cLetter = cLetter;
        this->index = index;
    }
    void set(int index, char cLetter)
    {
        this->cLetter = cLetter;
        this->index = index;
    }
};
struct Undo
{
    int index;
    int indexString;
    void set(int index, int indexString)
    {
        this->index = index;
        this->indexString = indexString;
    }
    
};

void readPuzzle(vector<vector<Puzzle> > &aMap)
{
    char cMatrix[N][N];
    string cWord;
    int index = 0;
    for(int i =0; i<N; i++)
    {
        cin>>cWord;
        
        for(int j=0; j<N;j++/* ,index++ */)
        {
            //vector<Puzzle> vTemp;
            
            cMatrix[i][j] = cWord[j];
            /*             Puzzle aWord(index,cWord[j]);
             vTemp.push_back(aWord);
             aMap.push_back(vTemp); */
        }
    }
    Puzzle temp;
    for(int i =0; i<N; i++)
    {
        for(int j=0; j<N;j++,++index)
        {
            temp.set(-1, cMatrix[i][j]);
           aMap[index].push_back(temp);
            //bot to top
            if(i != N-1 )
            {
                temp.set(index+N, cMatrix[i+1][j]);
               aMap[index].push_back(temp);
                if(j != N-1)
                {
                    temp.set(index+1, cMatrix[i][j+1]);
                   aMap[index].push_back(temp);
                    
                    temp.set(index+N+1, cMatrix[i][j-1]);
                    aMap[index].push_back(temp);
                    
                }
                if(j != 0)
                {
                    temp.set(index-1, cMatrix[i][j-1]);
                   aMap[index].push_back(temp);
                    temp.set(index+N-1, cMatrix[i+1][j-1]);
                    aMap[index].push_back(temp);
                }
            }
            //bot
            if(i !=0)
            {
                temp.set(index-N, cMatrix[i-1][j]);
               aMap[index].push_back(temp);
                if(j != N -1)
                {
                    temp.set(index+1, cMatrix[i][j+1]);
                    aMap[index].push_back(temp);
                    temp.set(index-N+1, cMatrix[i-1][j+1]);
                    aMap[index].push_back(temp);
                }
                if(j != 0)
                {
                    temp.set(index-1, cMatrix[i][j-1]);
                   aMap[index].push_back(temp);
                    temp.set(index-N-1, cMatrix[i-1][j-1]);
                   aMap[index].push_back(temp);
                }
                
            }
        }
    }
}

int calculate(int iLength)
{
    if(iLength <= 4)
        return 1;
    
    if(iLength  == 5)
        return 2;
    
    if(iLength == 6)
        return 3;
    
    if(iLength == 7)
        return 5;
    
    return 11;
}


bool search(string sWord, vector<vector<Puzzle> > &listAdj, int index)
{
    stack<Undo> pila;
    int currIndex(0), puzzleIndex;
    vector<bool> status(N*N, false);
    
    Undo uProgress;
    uProgress.set(index,0);
    
    pila.push(uProgress);
    while (!pila.empty()) {
        puzzleIndex = pila.top().index;
        currIndex = pila.top().indexString;
        pila.pop();
        
        status[puzzleIndex] = true;
        
        for (int i = 1; i < listAdj[puzzleIndex].size(); ++i)
        {
            if (!status[listAdj[puzzleIndex][i].index])
            {
                if (listAdj[puzzleIndex][i].cLetter == sWord[currIndex + 1])
                {
                    if (currIndex+1 == sWord.length()-1)
                        return true;
                    
                    uProgress.set(listAdj[puzzleIndex][i].index, currIndex + 1);
                    pila.push(uProgress);
                }
            }
        }
    }
    return false;
}

bool startGame(vector<vector<Puzzle> > listAdj, string sWord)
{
    for(int i =0; i<N*N; i++)
    {
        if(listAdj[i][0].cLetter == sWord[0])
        {
            return search(sWord,listAdj,i);
        }
        
    }
    return false;
}

int main()
{
    
    int iGames, iWords, iPoints;
    
    
    
    cin>>iGames;
    
    for(int i =0 ;i<iGames;i++, iPoints = 0)
    {
        string sWord;
        vector<vector<Puzzle> > vPuzzle;
        readPuzzle(vPuzzle);
        cin>> iWords;
        for(int j = 0; j<iWords;++j)
        {
            cin>>sWord;
            if(startGame(vPuzzle,sWord))
            {
                iPoints += calculate(sWord.length());
            }
        }
        cout<< "Game "<< i+1<<": "<< iPoints <<endl;
    }
    return 0;
}
