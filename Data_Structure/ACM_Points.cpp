#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
 The first line contains two integers T (1 <= T <= 20), number of teams, P (1<= P <= 10) number of problems.
 The next T lines are the team’s names (one word per name).
 The next line contains an integer S (1 <= S <= 1000), number of solutions sent.
 The next S lines contains: the team name, the name of the problem (A, B, C, …), the time when this solutions was sent and the judgment (A = Accepted, W = Wrong Solution).
 
*/
using namespace std;

struct Team{
    string sName = "";
    int iAttempts[10], iSolved=0, iTime=0;
    
    Team()
    {
        for(int i=0; i<10; i++)
            iAttempts[i] = 0;
        
        iSolved = 0;
        sName = "";
    }
   /* bool operator >(const Team& A)const
    {
        
        if (iSolved==A.iSolved)
            return iTime > A.iTime;
        return iSolved > A.iSolved;
    };
    
    */
    
};

bool compareWin(const Team &A, const Team &B)
{
    if (B.iSolved==A.iSolved)
        return B.iTime > A.iTime;
    
    return B.iSolved < A.iSolved;
}


void modifyVector(vector<Team> &ACM, string sName,int cProb, int iTime, int cAccept)
{
    for(auto i = ACM.begin();i != ACM.end();i++)
    {
        if(i->sName == sName && !(cAccept == 'A'))
        {
            i->iAttempts[cProb-'A'] += 20;
        }
        
        else if(i->sName ==sName && (cAccept == 'A'))
        {
            i->iSolved++;
            i->iAttempts[cProb-0X41] += iTime;
            i->iTime += i->iAttempts[cProb-0X41];
        }
    }
}

void displayTable(vector<Team> ACM)
{
    int j = 1;
    for(auto i = ACM.begin();i != ACM.end();i++,j++)
    {
        cout<<j<<" - "<<i->sName<<" "<<i->iSolved;
        if(i->iSolved !=0)
            cout<<" "<<i->iTime<<endl;
        
        else cout<<" -"<<endl;
    }
}

int main()
{
    int iTeams, iProb, iSol;
    string sName;
    cin>>iTeams>>iProb;
    vector<Team> ACM;
    
    for (int i = 0; i < iTeams; i++)
    {
        cin>>sName;
        Team tTeam;
        tTeam.sName = sName;
        ACM.push_back(tTeam);
    }
    cin>>iSol;
    int iTime;
    string name;
    char cProb,cAccept;
    for(int i = 0; i < iSol; i++)
    {
        cin>>sName>>cProb>>iTime>>cAccept;
        modifyVector(ACM, sName, cProb, iTime, cAccept);
    }
    sort(ACM.begin(), ACM.end(),compareWin);
    displayTable(ACM);
    return 0;
}
