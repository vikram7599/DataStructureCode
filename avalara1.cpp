#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll *arr = new ll[n];
        for(ll i=0; i<n; i++){
            cin >> arr[i];
        }

        stack<ll> s;
        ll *vis = new ll[n];
        for(ll i=0; i<n; i++){
            vis[i] = 0;
        }

        s.push(0);
        for(ll i=1; i<n; i++){
            while(!s.empty() && arr[i] > arr[s.top()]){
                s.pop();
            }
            if(s.empty()){
                vis[i] += i;
            }
            else{
                ll val = (i - s.top()-1);
                vis[i] += val;
            }
            s.push(i);
        }
        stack<int> s2;

        s2.push(n-1);
        for(ll i=n-2; i>=0; i--){
            while(!s2.empty() && arr[i] > arr[s2.top()]){
                s2.pop();
            }

            if(s2.empty()){
                vis[i] += (n - 1 - i);
            }
            else{
                ll val = (s2.top() - i - 1);
                vis[i] += val;
            }
            s2.push(i);

        }

        ll maxV = 0;
        ll ans = 0;
        for(int i=0; i<n; i++){
            ll temp = ((vis[i]%1000000007) * ((i+1)%1000000007))%1000000007;
            
            if(temp > maxV){
                maxV = temp;
                ans  = i+1;
            }
        }

        cout << ans <<endl;
        delete [] arr;
        delete [] vis;
    }
}