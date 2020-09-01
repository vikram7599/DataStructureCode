#include<bits/stdc++.h>
using namespace std;

void pairsort(int a[], int b[], int n) 
{ 
    pair<int, int> pairt[n]; 
  
    // Storing the respective array 
    // elements in pairs. 
    for (int i = 0; i < n; i++)  
    { 
        pairt[i].first = a[i]; 
        pairt[i].second = b[i]; 
    } 
  
    // Sorting the pair array. 
    sort(pairt, pairt + n); 
      
    // Modifying original arrays 
    for (int i = 0; i < n; i++)  
    { 
        a[i] = pairt[i].first; 
        b[i] = pairt[i].second; 
    } 
} 
  

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int *arr = new int[n];
        int *ind = new int[n];
    
        for(int i=0; i<n; i++){
            cin >> arr[i];
            ind[i] = i;
        }

        pairsort(arr, ind, n);

        int maxV1 = ind[n-1];
        int minV1 = ind[0];

        if(abs(maxV1 - minV1) == 1){
            cout << ((n-1)*n)/2 << endl;
            continue;
        }

        int minV2 = ind[1];
        int diff = abs(ind[n-1] - ind[1]);
        int left = n-1 - diff + 1;

        int ans1 = (left * (left+1))/2;

        int maxV2 = ind[n-2];
        diff = abs(ind[n-2] - ind[0]);
        int right = n- 1- diff + 1;

        int ans2 = (right * (right + 1))/2;

        cout << max(ans1 , ans2) << endl;
        
    }
}