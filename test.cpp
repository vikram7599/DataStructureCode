#include <iostream>
#include <unordered_map>
#include <string>
#include<vector>
using namespace std;

int printPairs(int *input, int n, int k) {
    vector< pair<int,int> > v;
	for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int ans1 = input[i] - input[j];
            int ans2 = input[j] - input[i];
            if(ans1 == k){
                if(input[i] < input[j]){
                    v.push_back(make_pair(input[i], input[j]));
                }else{
                    v.push_back(make_pair(input[j], input[i]));
                }
            }
            if(ans2 == k){
                if(input[i] < input[j]){
                    v.push_back(make_pair(input[i], input[j]));
                }else{
                    v.push_back(make_pair(input[j], input[i]));
                }
            }
        }
    }
    
    return v;
}




int main() {
	int *arr = new int[4];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;		

	int ans = printPairs(arr, 4, 2);
	cout << ans <<endl;

}