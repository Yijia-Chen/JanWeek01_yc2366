#include<iostream>
#include<math.h>

using namespace std;
//Generating NaN and INF in double
int main(){
	double x = 0.0, y = 0.0;
	double doubleResult1, doubleResult2;
		doubleResult1 = 1/x; 
		doubleResult2 = y/x;
		cout<<doubleResult1<<","<<doubleResult2<<endl;
	return 0;
}
