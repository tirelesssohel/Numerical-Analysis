#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i, j, k;
    cout << "Enter number of unknowns: ";
    cin >> n;

    float arr[n][n+1], ratio;

    cout << "Enter augmented matrix.." << endl;
    for(i = 0; i < n; i++){
        for(j = 0; j < n+1; j++){
            cin >> arr[i][j];
        }
    }

    // converting to diagonal matrix
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i != j){
                ratio = arr[j][i] / arr[i][i];
                for(k = 0; k < n+1; k++){
                    arr[j][k] = arr[j][k] - (ratio * arr[i][k]);
                }
            }
        }
    }

    // calculating the  roots
    cout << endl;
    for(i = 0; i < n; i++){
        cout << "Root " << i+1 << ": " << arr[i][n]/arr[i][i] << endl;
    }

return 0;
}
