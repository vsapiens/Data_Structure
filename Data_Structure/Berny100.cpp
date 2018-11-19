#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;

struct Person
{
    string sName;
    int iAge;
    Person(string sName, int iAge)
    {
        this->sName = sName;
        this->iAge = iAge;
    }
};
void iniMatAdj(vector<vector <bool> > vAdj, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)

        {
            vAdj[i][j] = false;
        }
    }
}

void leeMatAdj(vector<vector <bool> > vAdj, int e)
{
    int a, b;
    for (int i = 1; i <= e; i++)
    {
        cin >> a >> b;
        vAdj[a - 1][b - 1] = true;
    }
}
bool operator <(const Person &p1, const Person &p2)
{
     return p1.iAge < p2.iAge || (p1.iAge ==p2.iAge && p1.iAge< p2.iAge);
}

void findAge(unordered_map<string, vector<Person > > &mDesc, vector<Person> vOut)
 {
    vector<Person> mList;
    unordered_map<string, vector<Person > >::iterator it;
    it = mDesc.find("Berny");
    
    
 }
int main()
{
    int iTimes, iAge;
    string sNameFather, sNameSon;
    unordered_map<string, vector<Person > > mDesc; 
    unordered_map<string, vector<Person > >::iterator it; 
    vector<Person> vOut;

    cin>>iTimes;

    for(int i = 0; i<iTimes;++i)
    {
        vector<Person> vPerson;
        cin>>sNameFather>>sNameSon>> iAge;
        
        Person son(sNameSon, iAge);
        
        it = mDesc.find(sNameFather);
        if(it == mDesc.end())
            {
                vPerson.push_back(son);
                mDesc.insert(pair<string, vector<Person > > (sNameFather,vPerson));

            }
        else if ( it != mDesc.end())
        {
            it->second.push_back(son);
        }
    }

    findAge(mDesc, vOut);
    sort(vOut.begin(),vOut.end());
    Person pOut("",0);
    int i = vOut.size();
    while(!vOut.empty())
    {
        pOut = vOut.at(i);
        cout<< pOut.sName << " "<< pOut.iAge<<endl;
        vOut.pop_back();
        --i;
    }

    return 0;
};