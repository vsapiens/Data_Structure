//
//  main.cpp
//  Data_Structure
//
//  Created by Erick González on 7/12/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


int getNumber();
void getMat();
void rotateMatrix(int,int[4][4]);

int getNumber(){
    int x = 0;
    cin>>x;
    return x;
}

void getMat(int iMat[4][4]){
    int iNumber =0;
    for(int iRow = 0 ; iRow < 4 ;iRow++)
    {
        for(int iCol =0; iCol< 4;iCol++)
        {
            cin>>iNumber;
            iMat[iRow][iCol] = iNumber;
        }
    }
}


void rotateMatrix(int iSpin,int iMat[4][4]){
    int iRotate = 0;
    if(iSpin < 0)
    {
        iSpin *= -1;
        iSpin = iSpin % 4;
        iSpin *= -1;
        iSpin += 4;
        iRotate = iSpin;
    }
    else iRotate = iSpin % 4;
    
    switch (iRotate) {
        case 1:
            for (int iRowIndex = 0; iRowIndex < 4; iRowIndex++ )
            {
                
                for(int iColIndex = 3; iColIndex >= 0; iColIndex--)
                {
                    cout<< iMat[iColIndex][iRowIndex];
                    if (iColIndex !=0)
                        cout<<" ";
                }
                cout<<endl;
                
            }
            
            break;
        case 2:
            for (int iRowIndex = 3; iRowIndex >= 0; iRowIndex--)
            {
                for(int iColIndex = 3; iColIndex >=0 ; iColIndex--)
                {
                    cout<< iMat[iRowIndex][iColIndex];
                    if (iColIndex != 0)
                        cout<<" ";
                }
                cout<<endl;
            }
            
            break;
        case 3:
            for (int iRowIndex = 3; iRowIndex >= 0; iRowIndex--)
            {
                for(int iColIndex = 0; iColIndex < 4; iColIndex++)
                {
                    cout<< iMat[iColIndex][iRowIndex];
                    if (iColIndex !=3)
                        cout<<" ";
                }
                cout<<endl;
            }
            break;
            
        default:
            for (int iRowIndex = 0; iRowIndex < 4; iRowIndex++)
            {
                for(int iColIndex = 0; iColIndex < 4; iColIndex++)
                {
                    cout<< iMat[iRowIndex][iColIndex];
                    if (iColIndex !=3)
                        cout<<" ";
                }
                cout<<endl;
            }
            break;
    }
}


int main()
{
    int iMat[4][4];
    int iNumber = getNumber();
    getMat(iMat);
    rotateMatrix(iNumber, iMat);
    return 0;
}
