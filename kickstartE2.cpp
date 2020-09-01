#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int j=1; j<=t; j++){
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int maxV = n;
        int nNew = n - c;
        int aNew = a - c;
        int bNew = b - c;

        if(aNew < 0 || bNew < 0 || aNew + bNew > nNew){
            cout << "Case #" << j << ": IMPOSSIBLE"<< endl;
            continue;
        }

        int *ansArr = new int[n];

        if(aNew == 0 && bNew == 0 && c == 1 && n > 1){
            cout << "Case #" << j << ": IMPOSSIBLE"<< endl;
            continue;
        }

        if(aNew == 0 && bNew == 0){
            for(int i=0; i<c/2; i++){
                ansArr[i] = maxV;
            }
            int q = c - c/2;
            for(int i=n-1; i>n-1-q; i--){
                ansArr[i] = maxV;
            }
            for(int i=c/2; i<=n-1-q; i++){
                ansArr[i] = 1;
            }
            cout << "Case #" << j << ": ";

            for(int i=0; i<n; i++){
                cout << ansArr[i] << " " ;
            }
            cout << endl;
            continue;
        }


        if(bNew < aNew){
            int startIndex = n-1-bNew;
            // cout << "1" <<endl;
            for(int i=startIndex; i> startIndex-c; i--){ // Filling common value
                // cout << i << " ";
                ansArr[i] = maxV;
            }
            // cout << endl;
            // cout << "2" << endl;
            for(int k=0, i =startIndex+1; i<n; i++, k++){ //filling bValues from right
                ansArr[i] = maxV-1-k;
                // cout << i <<" ";
            }
            // cout << endl;
            // cout <<"3" << endl;
            for(int i=0, k =aNew; i<aNew; i++, k--){
                ansArr[i] = maxV - k;
                // cout <<i <<" "; 
            }
            // cout << endl;
            // cout << "4" <<endl;
            for(int i=aNew; i<= startIndex-c; i++){
                ansArr[i] = 1;
                // cout <<i <<" ";
            }
            // cout << endl;
        }
        else{
            int startIndex = aNew;
            for(int i=startIndex; i<startIndex+c; i++){ // Filling common value
                ansArr[i] = maxV;
            }

            for(int k=0, i = startIndex-1; i>=0; i--, k++){ //filling aValues from left
                ansArr[i] = maxV-1-k;
            }

            for(int i=n-1, k =bNew; i > n-1-bNew; i--, k--){ // filling bValue from right
                ansArr[i] = maxV - k;
            }

            for(int i=startIndex+c; i<= n-1-bNew; i++){
                ansArr[i] = 1;
            }
        }

        
        
        

        cout << "Case #" << j << ": ";

        for(int i=0; i<n; i++){
            cout << ansArr[i] << " " ;
        }
        cout << endl;
        // delete [] arr;
        delete [] ansArr;
    }
}