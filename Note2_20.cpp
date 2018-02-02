#include<iostream>
#include<math.h>

using namespace std;
//Observe oveflow handling in integers
int main(){
	long i = 1, intFactorial = 1;
	for (i= 2; i < 20; i++) {
		intFactorial *= i;
		cout<<i<<","<<intFactorial<<endl;
	}
	cout<<"----------------------------\n";
	for (i= 20; i > 1; i--) {
		intFactorial /= i;
		cout<<i<<","<<intFactorial<<endl;
	}
	return 0;
}
