#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int *arr = new int[n];

        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        set<int> s;
        for(int i=0; i<n; i++){
            if(arr[i] != 0){
                s.insert(arr[i]);
            }
        }

        cout << s.size() << endl;
        delete [] arr;

    }
}