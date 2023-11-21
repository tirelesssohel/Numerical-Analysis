//   Considering given function
//   f(x) = x^3-3x-5

// The derivative of f(x) is
//   f'(x) = 3x^2-3

// Source code for newton raphson method

#include <bits/stdc++.h>
using namespace std;

float functValue(float x){
    return x*x*x - 3*x - 5;
}

float derivativeFunctValue(float x){
    return 3*x*x - 3;
}

int main(){
    float initialRoot, finalRoot, absError;
    cout << "Enter initial root: ";
    cin >> initialRoot;

    cout << "Enter absolute error: ";
    cin >> absError;

    if((derivativeFunctValue(initialRoot)) == 0){
        cout << "Divided by zero error" << endl;
        return 0;
    }

    int itrCtr = 0;
    while(1){
        itrCtr++;
        finalRoot = initialRoot - (functValue(initialRoot) / derivativeFunctValue(initialRoot));

        if((abs(initialRoot - finalRoot)) <= absError){
            cout << "\nRoot = " << finalRoot << endl;
            cout << "Needed Iterations: " << itrCtr << endl;
            break;
        }else{
            initialRoot = finalRoot;
        }
    }

return 0;
}
