#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    for(int k=1; k<=t; k++){
        int n;
        cin >> n;
        int *arr = new int[n];
        
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        int count = 0;
        
        int maxV = INT_MIN;
        
        for(int i=0; i<n; i++){
            if(arr[i] > maxV){
                maxV = arr[i];
                
                if(i== n-1 || arr[i] > arr[i+1]){
                    count++;
                }
            }
        }
        
        cout << "Case #" << k << ": " << count << endl;
        delete [] arr;
        
    }
    
}