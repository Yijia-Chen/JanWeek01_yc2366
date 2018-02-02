#include<iostream>
#include<math.h>

using namespace std;
//Observe NaN and INF handling in integers
int main(){
	int m = 0.0, n = 0.0;
	int intResult1, intResult2;
		intResult1 = 1/m; 
		intResult2 = m/n;
		cout<<intResult1<<","<<intResult2<<endl;
	return 0;
}
