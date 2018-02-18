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
    bool z;

	for(int i=rowPtr[x-1]; i<=rowPtr[x]-1;i++){
		if(colInd[i] == y-1){
			z=true;
			cout<<value[i];
		}
	}
	if(z==false) cout<<0;	
	
	return 0;
} 

int main(){
	int i,j;
	for(i=1;i<=5;i++){
		for(j=1;j<=5;j++){
			retrieveElement(i,j);
			cout<<" ";
			if(j==5) cout<<endl;
		}
	}
	
	return 0;
}
