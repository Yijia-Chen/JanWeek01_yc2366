#include <iostream>
#include <cmath>
#include <fstream>

#define cons 1/(2*sqrt(3))
#define realValue  2.3504
using namespace std;

double f(double x){
	return exp(x);
}

double rectangle(double x, double h){
	return h*f(x);
}

double trapezoid(double x, double h){
	return h*(0.5*f(x)+0.5*f(x+h));
}

double mid_point(double x, double h){
	return  h*f(x+0.5*h);
}

double simpson(double x, double h){
	return h*(f(x)/6+f(x+0.5*h)*4/6+f(x+h)/6);  
}

double two_point_gaussian(double x, double h){
	return h*(0.5*f(x+0.5*h-cons*h)+0.5*f(x+0.5*h+cons*h));
}


int main(){
	double h = 0.01;
	double IRect=0, ITrap=0, IMid=0, ISimp=0, ITwog=0;
	double ERect, ETrap, EMid, ESimp, ETwog;
	double i;
	
	for(i=-1; i<=1; i=i+h){
		IRect = IRect + rectangle(i,h);
		ITrap = ITrap + trapezoid(i,h);
		IMid = IMid + mid_point(i,h);
		ISimp = ISimp + simpson(i,h);
		ITwog = ITwog + two_point_gaussian(i,h);
	}

	ERect = realValue - IRect;
	ETrap = realValue - ITrap;  
	EMid = realValue - IMid;
	ESimp = realValue - ISimp;
	ETwog = realValue - ITwog;
	
	cout<<IRect<<" Error: "<<ERect<<endl;
	cout<<ITrap<<" Error: "<<ETrap<<endl;
	cout<<IMid<<" Error: "<<EMid<<endl;
	cout<<ISimp<<" Error: "<<ESimp<<endl;
	cout<<ITwog<<" Error: "<<ETwog<<endl;
	
	return 0;
}
