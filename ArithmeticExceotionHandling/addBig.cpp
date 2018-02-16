#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

double addBig(double x, double y){//x and y must have 16 percisions
	int sum [617] = { }; //DBL_MAX 1.7976931348623158e+308
	int ex, ey; //exponent of x and y
	double manx, many; //mantissa of x and y 
	if (x==0){
		ex = 0;
	}else{
		ex = (int)(log10(fabs(x)));
	}
	manx = x*pow(10,-1*ex);
	
	if (y==0){
		ey = 0;
	}else{
		ey = (int)(log10(fabs(y)));
	}
	many = y*pow(10,-1*ey);
	cout<<x<<" "<<ex<<" "<<setprecision(16)<<manx<<endl;
	cout<<y<<" "<<ey<<" "<<setprecision(16)<<many<<endl;
	
	for (int i= ex; i>ex-16; i--){
		sum[309+i]=sum[309+i]+(int)manx;
		//cout<<309+i<<"manx"<<manx<<endl;
		//cout<<sum[309+i]<<endl;
		manx= (manx-(int)manx)*10.0;
	}
		
	for (int i= ey; i>ey-16; i--){
		sum[309+i]=sum[309+i]+(int)many;
		//cout<<309+i<<"many"<<many<<endl;
		//cout<<sum[309+i]<<endl;
		many= (many-(int)many)*10;
	}
	//Now the result is stored in sum[]
	//Then we have to output it into two 16 digits double
	double result1, result2;
	int counter = 1;
	for (int i= 616; i>0; i--){
		
		if (sum[i]!=0){//first non zero
			
			if (counter<16){
				result1 = result1+sum[i]*pow(10,i-309);
				cout<<i<<"one "<<counter<<"  "<<setprecision(16)<<result1<<endl;
			}
			else if (counter<32){
				result2 = result2+sum[i]*pow(10,i-309);
				cout<<i<<"two "<<counter<<"  "<<setprecision(16)<<result2<<endl;
			}
			counter++;//add to counter
		}
	}

}
int main(){
	//addBig(1.111, 1.111);
	cout<<addBig(1.234567890123456e10, -0.234567890123456e10)<<endl;
	return 0;
}