#include <bits/stdc++.h>
using namespace std;

float f(float x){
    return 1/(1+x*x);
}

int main(){
    float a, b, sumOfOdd = 0, sumOfEven = 0;
    int n;

    cout << "Give a, b and n: ";
    cin >> a >> b >> n;
    float h = (b-a)/n, x[n], y[n];

    x[0] = a;
    x[n] = b;

    y[0] = f(x[0]);
    y[n] = f(x[n]);

    cout << endl << "x\t\ty" << endl;
    cout << x[0] << "\t\t" << y[0] << endl;

    for(int i = 1; i < n; i++){
        x[i] = x[i-1] + h;
        y[i] = f(x[i]);
        // sum += y[i];
        if(i%2==0){
            sumOfEven += y[i];
        }else{
            sumOfOdd += y[i];
        }
        cout << x[i] << "\t\t" << y[i] << endl;
    }
    cout << x[n] << "\t\t" << y[n] << endl;


    float result = (h/3)*((y[0]+y[n]) + (4*sumOfOdd) + (2*sumOfEven));

    cout << endl << "Sum is = " << result << endl;

    return(0);
}
