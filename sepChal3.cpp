#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int *arr = new int[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int *forward = new int[n];
        

        for(int i=0; i<n; i++){
            forward[i] = 0;
            
        }

        for(int i=0; i<n; i++){
            int val = 0;
            int tempArr[6] = {0};
            //int greater = 0;
            for(int j=i+1; j<n; j++){
                if(arr[i] > arr[j]){
                    val++;
                }
                tempArr[arr[j]]++;
            }
            //cout << val << " Val \n";

            for(int j=i-1; j>=0; j--){
                int x = arr[j];
                if(x >= arr[i]){
                    if(x > arr[i])
                    val++;
                    // continue;
                    int y = x-1;
                    while(y >= 0 ){
                        if(tempArr[y] > 0){
                            val++;
                            break;
                        }
                        y--;
                    }
                }
                
            }

            if(val > n){
                val = n-1;
            }
            forward[i] = val;
        }
        
        // for(int i=0; i<n; i++){
        //     cout << forward[i] << endl;
        // }
        

        int maxV = 0;
        int minV = INT_MAX;

        for(int i=0; i<n; i++){
            maxV = max(maxV, forward[i]);
            minV = min(minV, forward[i]);
        }
        
        cout << minV+1 << " " << maxV+1 << endl;
        cout << endl;
        delete [] arr;
        delete [] forward;
        


    }
}



