#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#define N 4

using namespace std;
struct asciiVal{
    int iValue;
    int index;
    asciiVal(int index, int iValue)
    {
        this->iValue = iValue;
        this->index = index;
    }

};

void readAsciiVal(vector<asciiVal> &aMap)
{
    string cWord;
    int index = 0;
    for(int i =0; i<N; i++)
    {
        cin>>cWord;

        for(int j=0; j<N;j++,index++)
        {
            asciiVal aWord(index,(int)cWord[j]);
            aMap.push_back(aWord);
        }
    }
}
void leeListAdj(vector<vector<int> > &listAdj, int e) {
    int a, b;

    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        listAdj[a - 1].push_back(b - 1);
        listAdj[b - 1].push_back(a - 1);
    }
}




int main()
{
    bool matAdj[N][N];
    int iGames, iWords, iPoints;
    string sWord;
    vector<cMap> Puzzle;
    vector<int, int> Index;

    cin>>iGames;
    readcMap(Puzzle);
    convert(Index, Puzzle);
    iniMatAdj(matAdj, Index);
    leeMatAdj(matAdj,16);

    for(int i =0 ;i<iGames;i++, iPoints = 0)
    {
        cin>> iWords;
        for(int j = 0; j<iWords;++j)
        {
            cin>>sWord;
            search(sWord,matAdj, iPoints);
        }
        cout<< "Game "<< iGames<<": "<< iPoints<<endl;
    }
    return 0;
}