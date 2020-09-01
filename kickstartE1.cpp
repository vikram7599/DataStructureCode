#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int j=1; j<=t; j++){
        int n;
        cin >> n;
        int *arr = new int[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        if(n <= 2){
            cout << "Case #" << j << ": 0" << endl;
            continue;
        }
        int maxLen = 2;
        int currDiff = arr[1] - arr[0];
        int currLen = 2;

        for(int i=2; i<n; i++){
            if(arr[i] - arr[i-1] == currDiff){
                currLen++;
                // cout << currLen << " "<<i <<endl;
            }
            else{
                
                maxLen = max(maxLen, currLen);
                // cout << maxLen << " " << i << endl;
                currLen = 2;
                currDiff = arr[i] - arr[i-1];

            }
        }
        maxLen = max(currLen, maxLen);

        cout << "Case #" << j << ": " << maxLen << endl;
        delete [] arr;
    }
}