
#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

#define lamda 0.2

double calPi(int N){
    int i, count=0;
    double *x = new double[N];
    double *y = new double[N];
    double pi;
    
    for(i = 1; i < N; i++){
        x[i] = 1.0*(rand() % 100 + 1)/100;
        y[i] = 1.0*(rand() % 100 + 1)/100;
        if ( x[i]*x[i] + y[i]*y[i] < 1 ) count++;
    }
    pi = 4.0*count/N;
    return pi;
}

int main(){
    int i;
    double piArray[6];
    for(i = 0; i < 6; i++){
    piArray[i] = calPi(pow(10,i+1));
    cout << piArray[i] <<endl;
    }

    return 0;
}














