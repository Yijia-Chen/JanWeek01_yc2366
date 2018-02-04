#include<iostream>
#include<math.h>
#include <limits>
#include <cfloat>
using namespace std;

/*Write a small function to test +0 and -0, i.e., isPostiveZero(x) and isNegativeZero(x).
 Then in an upper-level function, 
 use +1.0; -1.0; DBL_MAX; - 1.0*DBL_MAX; +0; -0;  INF, NINF; NaN 
 to test these two functions and generate report!  
 Write a small function to test INF, NINF and NaN in a similar way. */
 
 bool isPostiveZero(float x){
 	return(1/x==1/0.0);  //or use INFINITY to replace "1/0.0"
 }
 
 bool isNegativeZero(float x){
 	return(1/x==1/(-0.0));  //or use -INFINITY to replace "1/0.0"
 }
 
 bool isINF(float x){
 	return(x==INFINITY);
 }
 
 bool isNINF(float x){
 	return(x==-INFINITY);
 }
 
 bool isNaN(float x){
 	return(x!=x);
 }
 
 int main(){
 	int i;
 	float test[9]={+1.0,-1.0,DBL_MAX,-1.0*DBL_MAX,+0,-1.0*0,INFINITY,-INFINITY,NAN};
 	cout<<"isPostiveZero, isNegativeZero, isINF, isNINF, isNaN"<<endl;
 	for(i=0;i<9;i++){
 		bool y1 = isPostiveZero(test[i]);
		bool y2 = isNegativeZero(test[i]);
		bool y3 = isINF(test[i]);
		bool y4 = isNINF(test[i]);
		bool y5 = isNaN(test[i]);
			
	 	cout<<test[i]<<":"<<y1<<","<<y2<<","<<y3<<","<<y4<<","<<y5<<endl;		
}
 	return 0;
 }
 
