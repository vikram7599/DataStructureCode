#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int p, d;

ll recursionHelper(int **treatmentVal, int n, vector<int> doctorAvail, int d, int start, int dp[11][11][1001]){
    if(start == n){
        return 0;
    }

    if(d == 0){
        return INT_MAX;
    }

    if(d == 1){
        ll sum = 0;
        int doctor = doctorAvail[0];

        for(int i=n-1; i >= start; i--){
            sum += treatmentVal[doctor][i];
            dp[doctor][d][i] = sum;
        }
        //dp[doctor][d][start] = sum;
        return sum;
    }

    int x = INT_MAX, tog = 0;
    for(int i=0; i<d; i++){
        int doc = doctorAvail[i];
        if(dp[doc][d][start] != -1){
            x = min(x, dp[doc][d][start]);
            tog = 1;
        }
    }
    if(tog){
        cout << "Yes" << x<<endl;
        return x;
    }

    int minV = INT_MAX;
    int docUsed ;
    for(int j=0; j<d; j++){
        
        int currDoc = doctorAvail[j];
        vector<int> newdoctorAvail;
        for(int k =0; k<d; k++){
            if(k != j){
                newdoctorAvail.push_back(doctorAvail[k]);
            }
        }
        int patienTreat = 0;
        for(int i=start; i<n; i++){
            int currAns = 0;
            patienTreat += treatmentVal[currDoc][i];
            currAns = patienTreat;
            currAns += recursionHelper(treatmentVal, n, newdoctorAvail ,d-1,i+1, dp);
            
            
            // dp[currDoc][d][i] = currAns;

            if(currAns < minV){
                docUsed = currDoc;
                minV = currAns;
            }
        }
    }

    // dp[d][start] = minV;
    dp[docUsed][d][start] = minV;
    return minV;
}

int main(){
    
    freopen("in.txt", "r", stdin);
    cin >> p >> d;

    int **treatmentVal = new int*[d];
    
    for(int i=0; i<d; i++){
        treatmentVal[i] = new int[p];
        for(int j=0; j<p; j++){
            cin >> treatmentVal[i][j];
        }
    }
    vector<int> doctorAvail;
    for(int i=0; i<d; i++){
        doctorAvail.push_back(i);
    }

    int dp[11][11][1001];
    for(int i=0; i<d; i++){
        for(int j=0; j<d; j++){
            for(int k=0; k<p; k++){
                dp[i][j][k]=-1;
            }
        }
    }


    ll ans = recursionHelper(treatmentVal, p, doctorAvail, d, 0, dp);

    // for(int i=0; i<d; i++){
    //     for(int j=0; j<d; j++){
    //         for(int k=0; k<p; k++){
    //             cout << dp[i][j][k] <<" ";
    //         }
    //         cout << "    " ;
    //     }
    //     cout << endl;
    // }

    cout << ans <<endl;
}