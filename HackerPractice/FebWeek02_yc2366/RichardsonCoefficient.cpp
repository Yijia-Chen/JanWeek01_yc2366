#include <iostream>
#include <cmath>
#include <limits>
#include <cfloat>
#include <fstream>
#include <cstdio>
#include <iomanip>

using namespace std;

double f(double x){
	return pow(x,3);
}

double firstDeri1(double x, double h){
	return (f(x+h)-f(x))/h;
}

double secondDeri1(double x, double h){
	return (firstDeri1(x+h,h)-firstDeri1(x,h))/h;
}

double firstDeri2(double x, double h){
	return -1/(2*h)*f(x+2*h)-3/(2*h)*f(x)+2/h*f(x+h);
}

double secondDeri2(double x, double h){
	return -1/(2*h)*firstDeri2(x+2*h,h)-3/(2*h)*firstDeri2(x,h)+2/h*firstDeri2(x+h,h);
} 

double E1(double x, double h){
	return h*secondDeri1(x,h)/2;
}

//double E01(double x, double h){  /////???????????????????????????????????????????????????????????
//	return 1/2*h*secondDeri1(x,h);
//}                                              f'' of equation3    2 or 4?????

double E2(double x, double h){
	return h*secondDeri2(x,h)/2;
}

double A1(double x, double h){
	return firstDeri1(x,h);
}

double A2(double x, double h){
	return firstDeri2(x,h);
}

int main(){
	double ita1, ita2, ita3, ita4;
	double x,h;
	ofstream myfile;
    myfile.open ("RichardsonCoefficient.txt");
	myfile<<"tabulate the relative\n---------------------------"<<endl;
	for(int i=-4; i>=-40; i--) {
		x=1;
		h=pow(2,i);
		myfile<<"\t"<<setw(15)<<E1(x,h)
			<<"\t"<<setw(15)<<E1(x,2*h) 
			<<"\t"<<setw(15)<<E2(x,h)<<endl;
	}	
	myfile<<"Estimate ita\n------------------------------------"<<endl;
	myfile<<"\t"<<setw(15)<<"1st order known"
			 <<"\t"<<setw(15)<<"1st order unknown"
			 <<"\t"<<setw(15)<<"2st order known"
			 <<"\t"<<setw(15)<<"2st order unknown"
			 <<endl;
	for(int i=-4; i>=-40; i--) {
		h=pow(2,i);
		ita1=E1(x,2*h)/E1(x,h);	
		ita2=(A1(x,4*h)-A1(x,2*h))/(A1(x,2*h)-A1(x,h));
		ita3=E2(x,2*h)/E2(x,h);		
		ita4=(A2(x,4*h)-A2(x,2*h))/(A2(x,2*h)-A2(x,h));
		myfile<<"\t"<<setw(20)<<ita1
			 <<"\t"<<setw(20)<<ita2
			 <<"\t"<<setw(20)<<ita3
			 <<"\t"<<setw(20)<<ita4
			 <<endl;
	    
	}
	myfile.close();
	return 0;	
}
