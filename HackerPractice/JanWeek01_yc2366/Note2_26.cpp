#include<iostream>
#include<math.h>

using namespace std;
//Observe the expection handling 
int main(){
// Make x with easily observable precision

	double x = 1.234567890123456; 
	int i = 1;

// The normalized number is above 4.9407*10^(-324)
	x *= pow(10,-307);

// Decrease the normalized number to the range of denormals
	for (i=1; i<20; i++) {
		x /= 10.0;
		cout<<x<<endl;
    } 

	return 0;
}

/*another way to observe the soft landing behavior:
take square root instead of division*/
  



