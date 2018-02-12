#include <iostream>
#include <cmath>
#include <limits>
#include <cfloat>
#include <fstream>
#include <cstdio>
#include <iomanip>

using namespace std;

double f(double t){
	return exp(-t);
}

double forEular(double t, double delta){
	if(t==0) 
		return 1;
	else
		return (1-delta)*forEular(t-delta,delta);
}

double backEular(double t, double delta){
	if(t==0) 
		return 1;
	else
		return 1/(1+delta)*backEular(t-delta,delta);
}

int main(){
	int i;
	double t;
	double delta[3] ={0.5,1.0,2.0};
	ofstream myfile;
    myfile.open ("forBackEular.txt");
	for(i=0;i<=2;i++){
		myfile<<"delta="<<delta[i]<<"---------------------------------------"<<endl;
		for(t=0;t<20;t+=delta[i]){
		 	myfile<<left<<setw(15)<<f(t)
			 <<left<<setw(15)<<forEular(t,delta[i])
			 <<left<<setw(15)<<backEular(t,delta[i])
			 <<endl;
		}
	}	
		myfile.close();	
	return 0;
}
