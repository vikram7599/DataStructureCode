#include<iostream>
using namespace std;



int helper(int a, string b){
    return 1;
}

int helper(string b, int a){
    return 2;
}

int main(){

    int ans1 = helper(1, "Vikram");
    int ans2 = helper("Vikram", 1);

    cout << "Ans1 : " << ans1 <<endl;
    cout << "Ans2 : " << ans2 <<endl;
}