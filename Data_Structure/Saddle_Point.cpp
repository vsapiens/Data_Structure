#include <iostream>
using namespace std;

void getMat(int iDimension, int iMat[10][10])
{
    for(int iRow = 0 ; iRow < iDimension ;iRow++)
    {
        for(int iCol =0; iCol< iDimension;iCol++)
        {
            cin>>iMat[iRow][iCol];
        }
    }
}

bool verifyMatMax(int iMat[10][10], int iDimension, int iColumn,int iMax)
{
    bool bMax = true;
    for(int iIndex =0; iIndex< iDimension && bMax; iIndex++)
    {
        if(iMat[iIndex][iColumn]>iMax)
            bMax = false;
    }
    return bMax;
}

bool verifyMatMin(int iMat[10][10], int iDimension, int iColumn, int iMin)
{
    bool bMin = true;
    for(int iIndex =0; iIndex< iDimension && bMin; iIndex++)
    {
        if(iMat[iIndex][iColumn]< iMin)
            bMin = false;
    }
    return bMin;
}

void verifyMat(int iMat[10][10],int iDimension)
{
    bool bFound = false;
    int  iColIndexMax = 0, iColIndexMin = 0, iMax = iMat[0][0], iMin = iMat[0][0];
    for(int iRow = 0 ; iRow < iDimension && !bFound;iRow++,iMin = iMat[iRow][0],iMax = iMat[iRow][0])
    {
        for(int iCol = 0; iCol < iDimension;iCol++)
        {
            if(iMat[iRow][iCol]>iMax)
            {
                iMax = iMat[iRow][iCol];
                iColIndexMax = iCol;
            }
            
            if(iMat[iRow][iCol]<iMin)
            {
                iMin = iMat[iRow][iCol];
                iColIndexMin = iCol;
            }
        }
        if (verifyMatMax(iMat, iDimension, iColIndexMin, iMin))
        {
            cout<< iRow<<" "<< iColIndexMin<<endl;
            bFound = true;
        }
        if (verifyMatMin(iMat, iDimension, iColIndexMax, iMax))
        {
            cout<< iRow<<" "<< iColIndexMax<<endl;
            bFound = true;
        }
    }
    if(!bFound)
        cout<<"-1 -1"<<endl;
}
int main()
{
    int iDimension,iMat[10][10];;
    cin>>iDimension;
    getMat(iDimension, iMat);
    verifyMat(iMat,iDimension);
    return 0;
}
