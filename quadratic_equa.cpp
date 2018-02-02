#include<iostream>
#include<math.h>

using namespace std;

int main(){
	double a = 1e-20;
	double b = 1e3;
	double c = 1e3;
	double x1, x2, x3, x4, x5, x6;
	
	double delta = b*b-4*a*c;
	
	x1 = (-b+sqrt(delta))/(2*a);
	x2 = (-b-sqrt(delta))/(2*a);
	
	x3 = (2*c)/(-b+sqrt(delta));
	x4 = (2*c)/(-b-sqrt(delta)); 
	
	x5 = -c/b;
	x6 = -b/a+c/b;
		
//	cout<<x1<<"\n"<<x2<<"\n"<<x3<<"\n"<<x4<<"\n"<<x5<<"\n"<<x6<<endl;
	if (delta < 0) 
	   cout<<"this equation has no real root";
	else if(delta >= 0 && delta<1e-9)
	    cout<<x1<<"\n"<<x2;
	else cout<<x5<<"\n"<<x6;
	
	return 0;
} 
