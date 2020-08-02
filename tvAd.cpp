#include<bits/stdc++.h>
using namespace std;

int helper(vector<pair<int, int>> &arr, vector<int> &effect, int n, int m, int index, int val, vector<vector<int>> &dp){
    if(index == n){
        return 0;
    }
    if(val >= m){
        return 0;
    }

    if(dp[index][val] != -1){
        return dp[index][val];
    }

    // if val > arr[index] , skip the current

    if(val > arr[index].first){
        int ans = helper(arr, effect, n,m, index+1, val, dp);
        dp[index][val] = ans;
    }


    else{           // if val <= arr[index] 
        int nextVal = arr[index].second + 5;
        int ans1 = helper(arr, effect, n, m, index+1, nextVal, dp) + effect[index];
        int ans2 = helper(arr, effect, n, m, index+1, val, dp);

        dp[index][val] = max(ans1, ans2);
    }// consider it and increase the val for next
    // do not consider it and pass the same value

    return dp[index][val];

}


int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second ;
    }
    vector<int> effect(n);
    for(int i=0; i<n; i++){
        cin >> effect[i];
    }

    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

    int ans = helper(arr, effect, n, m, 0,0, dp);

    cout << ans <<endl;
}