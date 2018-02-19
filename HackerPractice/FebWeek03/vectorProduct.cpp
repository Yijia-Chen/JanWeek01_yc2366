//
//  main.cpp
//  Week3
//
//  Created by YJ C on 2/10/18.
//  Copyright © 2018 YJ C. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <limits>
#include <cfloat>
#include <fstream>
#include <cstdio>
#include <iomanip>

using namespace std;

int retrieveElement(int x, int y){
    int value[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int rowPtr[6] = {0,3,6,9,10,12};
    int colInd[12] ={0,1,4,0,1,2,1,2,4,3,0,4};
    bool z=false;
    
    for(int i=rowPtr[x-1]; i<=rowPtr[x]-1;i++){
        if(colInd[i] == y-1){
            z=true;
            return value[i];
        }
    }
    return 0;
}

int productAx(int matrix[5][5], int vecx[5][1]){
// Compute the product of Ax = b
    int vecb[5][1]={0,0,0,0,0};
    for(int k=0; k<5; k++){
        for(int l=0; l<5; l++){
            vecb[k][0] += matrix[k][l]*vecx[l][0];
        }
        cout<<vecb[k][0]<<endl;
    }
    return 0;
}


int main(){
    int i,j;
    
    int matrix[5][5]={{1,2,0,0,3},{4,5,6,0,0},{0,7,8,0,9},{0,0,0,10,0},{11,0,0,0,12}};
    int vecx[5][1] = {5,4,3,2,1};
    int vecb[5][1]={0,0,0,0,0};
    
    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){
            vecb[i-1][0] += retrieveElement(i, j)*vecx[j-1][0];
            if(j==5)  cout<<vecb[i-1][0]<<endl;
        }
    }
    productAx(matrix, vecx);
    return 0;
}
