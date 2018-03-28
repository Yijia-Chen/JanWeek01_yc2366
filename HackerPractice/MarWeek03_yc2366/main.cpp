//
//  main.cpp
//  Week3
//
//  Created by YJ C on 2/10/18.
//  Copyright © 2018 YJ C. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <limits>
#include <cfloat>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <list>
#include <sstream>
using namespace std;

#define lamda 0.2

//int main(){
//    ifstream infile;
//    infile.open("/Users/yjc/Documents/ECE4960/Week3/Week3/value.csv");
//    if(!infile.is_open()) cout<<"error: file open"<<endl;
//
//    list<string> mylist;
//    string myvalue;
//
//    while(infile.good()){
//        getline(infile,myvalue,'\n');
//        mylist.push_back(myvalue);
//
//    }
//
//
//    infile.close();
//    for (list<string>::iterator i = mylist.begin(); i != mylist.end(); ++i)
//        cout << *i << endl;
//
//
//    return 0;
//}

//double func(double x[], double y[], int size){
//    double t, a, b;
//    for(int i = 0; i < size; i++){
//
//
//    }
//
//    return 0;
//}
//
//double slop (double x[], double y[], int size){
//
//}
/*friday hp1*/
double calPi(int N){
    int i, count=0;
    double *x = new double[N];
    double *y = new double[N];
    double pi;

   // y[i] = random( );
    for(i = 1; i < N; i++){
        x[i] = 1.0*(rand() % 100 + 1)/100;
    //   cout << x[i] <<endl;
        y[i] = 1.0*(rand() % 100 + 1)/100;
        if ( x[i]*x[i] + y[i]*y[i] < 1 ) count++;
    }
    pi = 4.0*count/N;
    return pi;
}

/*friday hp2*/
//void distrbt(){
//    double rdm = 1.0*(rand() % 100 + 1)/100;
//    double v = -1.0/lamda*log(1-u);
//    double p;
//    v>=0 ? p = lamda*exp(-lamda*v) : p = 0;
//    
//    return p;
//}

int main(){
    int i;
    double piArray[6];
    for(i = 0; i < 6; i++){
    piArray[i] = calPi(pow(10,i+1));
    cout << piArray[i] <<endl;
    }

    return 0;
}














