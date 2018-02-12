#include<iostream>
#include<cmath>
#include <limits>
#include <cfloat>
#include <fstream>
#include <cstdio>

using namespace std;

double f1(double x){
	
	return x*x; 
} 

double f2(double x){
	return x*x + pow(10,10); 
}
   
/* n is indicator, when n=1, use f1, else use f2 */
double firstDerivative1(double x, double h, int n){
	if (n==1)
	return (f1(x+h) - f1(x))/h;
	else return (f2(x+h) - f2(x))/h;
}

double firstDerivative2(double x, double h, int n){
	if(n==1) 
	return (f1(x+h)-f1(x-h))/(2*h);
	else return (f2(x+h)-f2(x-h))/(2*h);
} 

int main(){
	double delta,h, x = 1;
	int i;
	ofstream myfile;
    myfile.open ("relativeError.txt");
	for(i=-1;i>=-18;i--){
		h = pow(10,i);
		delta = firstDerivative1(x,h,1)-2;
		myfile<<delta<<endl;
	}
	myfile<<"----------------------------------"<<endl;
	for(i=-1;i>=-18;i--){
		h = pow(10,i);
		delta = firstDerivative1(x,h,2)-2;
		myfile<<delta<<endl;
	}
	myfile<<"----------------------------------"<<endl;
	for(i=-1;i>=-18;i--){
		h = pow(10,i);
		delta = firstDerivative2(x,h,1)-2;
		myfile<<delta<<endl;
	}
	myfile<<"----------------------------------"<<endl;
	for(i=-1;i>=-18;i--){
		h = pow(10,i);
		delta = firstDerivative2(x,h,2)-2;
		myfile<<delta<<endl;
	}
	myfile<<"----------------------------------"<<endl;
	
	myfile.close();
	return 0;
}
