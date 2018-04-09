//
//  main.cpp
//  Week3
//
//  Created by Yijia Chen and Yazhi Fan on 4/8/18.
//  Copyright © 2018 Yijia Chen and Yazhi Fan All rights reserved.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <list>
#include <sstream>
using namespace std;

double f(double t){
    return exp(-t);
}

double forwardEuler(double t, double delta){
    return (1-delta)*f(t-delta);
}

double backwardEuler(double t, double delta){
    return f(t-delta)/(1+delta);
}

int main(){
    double t;
    double delta[]={0.5, 1.0, 2.0};
    for(int i = 0; i < sizeof(delta)/sizeof(delta[0]); i++){
        cout<<"delta is "<<delta[i]<<endl;
        for(t=0; t<=20; t+=delta[i]){
            cout<<backwardEuler(t, delta[i])<<"  groud truth: "<<f(t)<<endl;
        }
    }
    return 0;
}











