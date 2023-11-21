//   Considering given function
//   f(x) = x^3-x-4

// We have to enter first initial root for which the function is positive
// And second initial root for which function is negative

#include <bits/stdc++.h>
using namespace std;

float rootFinder(float x, float y){
    return (x+y)/2;
}

float functValueCalculator(float x){
    return x*x*x - x - 4;
}

int main(){
    float firstRange, secondRange, absError;
    cout << "Enter first(function is positive) and second(function is negative) range: ";
    cin >> firstRange >> secondRange;

    cout << "Enter absolute error: ";
    cin >> absError;

    if(functValueCalculator(firstRange)*functValueCalculator(secondRange)>=0){
        cout << "\nYou have not entered correct range" << endl;
        return 0;
    }

    int itrCtr = 0;
    cout << "\nFirst Range\tSecond Range\tAbsolute Error" << endl;
    while(1){
        itrCtr++;
        float approxRoot = rootFinder(firstRange, secondRange);
        float functValue = functValueCalculator(approxRoot);

        if(functValue > 0){
            firstRange = approxRoot;
            if(abs(firstRange-secondRange) <= absError){
                cout << firstRange << "\t\t" << secondRange << "\t\t" << abs(firstRange-secondRange) << endl;
                cout << "\nRoot = " << firstRange << endl;
                cout << "Iterations needed = " << itrCtr << endl;
                break;
            }
        }else{
            secondRange = approxRoot;
            if(abs(firstRange-secondRange) <= absError){
                cout << firstRange << "\t\t" << secondRange << "\t\t" << abs(firstRange-secondRange) << endl;
                cout << "\nRoot = " << secondRange << endl;
                cout << "Iterations needed = " << itrCtr << endl;
                break;
            }
        }
        cout << firstRange << "\t\t" << secondRange << "\t\t" << abs(firstRange-secondRange) << endl;
    }

return 0;
}
