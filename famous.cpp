#include<bits/stdc++.h>
using namespace std;

void fillPrimes(int n, vector<int> &primes){

    primes.push_back(2);
    primes.push_back(3);

    for(int i=4; i<=n; i++){
        int tog = 0;
        for(int j=2; j*j <= i; j++){
            if(i%j == 0){
                tog = 1;
                break;
            }
        }

        if(tog == 0){
            primes.push_back(i);
        }
    }
}

int solution(int N, int A[]){

    vector<int> primes;

    fillPrimes(N, primes);

    for(int i=0;i<primes.size(); i++){
        cout << primes[i] <<" ";
    }
    cout << endl;

    // vector<int> maxPrimes;
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int k=1, j = i+2; k<primes.size() && j < N; k++){
            int diff = A[j] - A[i];
            ans = ans + diff;
            j = i + primes[k];
        }
    }

    return ans;

}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << solution(n, arr) << endl;

}