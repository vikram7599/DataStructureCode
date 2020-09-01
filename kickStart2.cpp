#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int j=1; j<=t; j++){
        int k;
        cin >> k;

        int *arr = new int[k];
        for(int i=0; i<k; i++){
            cin >> arr[i];
        }

        vector<int> vec;
        
        for(int i=0; i<k; i++){
            if(i == 0 || arr[i-1] != arr[i]){
                vec.push_back(arr[i]);
            }
        }

        int upCount = 0;
        int doCount = 0;
        int ans = 0;
        for(int i=1; i<vec.size(); i++){
            if(vec[i] > vec[i-1]){
                upCount += 1;
                doCount = 0;
            }
            else{
                doCount += 1;
                upCount = 0;
            }
            if(upCount > 3 || doCount > 3){
                ans++;
                upCount = 0;
                doCount = 0;
            }

        }
        cout << "Case #" << j << ": " << ans << endl;
        delete [] arr;
        //delete [] countArr;
    }
}