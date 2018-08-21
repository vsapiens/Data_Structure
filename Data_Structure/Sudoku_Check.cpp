#include <iostream>

using namespace std;

void getNumbers(int iMat[9][9])
{
    for(int j =0; j<9;j++)
    {
        for(int i =0; i<9;i++)
        {
            cin>>iMat[j][i];
        }
    }
}

void checkMatrix(int iMat[9][9])
{
    int iTotSum=0,iColSum=0, iRowSum=0, iSum =0;
    bool check = true;
    
    for(int j =0; j<9;j++,iRowSum=0,iColSum =0)
    {
        for(int i =0; i<9;i++)
        {
            iRowSum += iMat[j][i];
            iColSum += iMat[i][j];
        }
        if(iRowSum != 45 || iColSum != 45)
            check = false;
        
 //       iTotSum += iRowSum;
    }
    int iIndex;
    for(int k = 1, iIndex=3; k< 4;k++,iSum = 0)
    {
        for(int j = iIndex*k-3; j<iIndex*k ;j++)
        {
            for(int i = iIndex*k-3; i<iIndex*k;i++)
            {
                
                iSum += iMat[j][i];
            }
        }
        if(iSum != 45)
            check = false;
        
    }
    if(/*iTotSum == 405 && */check)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    int iMat[9][9];
    getNumbers(iMat);
    checkMatrix(iMat);
    return 0;
}
