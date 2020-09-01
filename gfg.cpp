#include<iostream>
using namespace std;

int helper(string str1, string str2, int **dp){
    if(str1.size() == 0){
        return str2.size();
    }
    if(str2.size() == 0){
        return str1.size();
    }
    
    int n = str1.size();
    int m = str2.size();
    
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    
    if(str1[0] == str2[0]){
        int ans = helper(str1.substr(1), str2.substr(1), dp) + 1;
        dp[n][m] = ans;
        return ans;
    }
    
    int ans1 = helper(str1.substr(1), str2, dp);
    int ans2 = helper(str1, str2.substr(1), dp);
    
    dp[n][m] = min(ans1, ans2) + 1;
    
    return dp[n][m];
    
}

int main()
 {
	//code
	int t;
	cin >> t;
	while(t--){
	    string str1, str2;
	    cin >> str1 >> str2;
	    
	    int n = str1.size();
	    int m = str2.size();
	    
	    int **dp = new int*[n+1];
	    for(int i=0; i<=n; i++){
	        dp[i] = new int[n+1];
	        for(int j=0; j<=n; j++){
	            dp[i][j] = -1;
	        }
	    }
	    int ans = helper(str1, str2, dp);
	    cout << ans <<endl;
	    
	    for(int i=0; i<=n; i++){
	        delete [] dp[i];
	    }
	    delete [] dp;
	}
	
	return 0;
}