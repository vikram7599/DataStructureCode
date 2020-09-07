#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int **arr = new int*[n];
        for(int i=0; i<n; i++){
            arr[i] = new int[n];
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int tog = 0;
        int ans = 0;
        for(int i=n-2, j= n-1; i>=0 && j >=1; i--, j--){
            int currVal =  i*n + (j+1);
            if((arr[i][j] == currVal && tog == 0) || (arr[i][j] != currVal && tog == 1)){
                continue;
            }
            else{
                ans++;
                if(tog == 0){
                    tog = 1;
                }
                else{
                    tog = 0;
                }
            }
        }

        cout << ans << endl;
        for(int i=0; i<n; i++){
            delete [] arr[i];
        }
        delete [] arr;
    }

}