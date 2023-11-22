// gauss elimination method in c++
#include <bits/stdc++.h>
using namespace std;


int main(){
    int i, j, n, k, x, y;
    float sum, ratio;

    cout << "Enter the number of unknowns: ";
    cin >> n;

    float arr[n][n+1], value[n];

    cout << "Enter augmented matrix.." << endl;
    for(i = 0; i < n; i++){
        for(j = 0; j < n+1; j++){
            cin >> arr[i][j];
        }
    }



  
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j > i){
                ratio = arr[j][i] / arr[i][i];
                for(k = 0; k < n+1; k++){
                    arr[j][k] = arr[j][k] - (ratio * arr[i][k]);
                }
            }
        }
    }


  

    value[n-1] = arr[n-1][n] / arr[n-1][n-1];

    for(i = n-2; i >= 0; i--){
        sum = 0;
        for(j = i+1; j < n; j++){
            sum = sum + (arr[i][j] * value[j]);
        }
        value[i] = (arr[i][n] - sum) / arr[i][i];
    }


  
    cout << endl;
    for(i = 0; i < n; i++){
        cout << "Root " << i+1 << ": " << value[i] << endl;
    }

return 0;
}
