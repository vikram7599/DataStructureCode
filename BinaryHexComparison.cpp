#include<bits/stdc++.h>
using namespace std;

int digitToValue(char val){

    if(val >= '0' && val <= '9'){
        return val-'0';
    }

    if(val >= 'A' && val <= 'F'){
        int ans = val-'A' + 10;
        return ans;
    }
}

int convertFromBase(string val, int base){
    if(base != 2 || base != 16){
        return -1;
    }

    int value =0;

    for(int i = val.size()-1; i>=0; i--){
        int digit = digitToValue(val[i]);

        if(digit < 0 || digit >= base){
            return -1;
        }
        int power = val.size()-1-i;

        value += digit * pow(base , power);
    }

    return value;

}

bool compareBinHex(string binary, string hexa){
    int n1 = convertFromBase(binary, 2);
    int n2 = convertFromBase(hexa, 16);

    if(n1 < 0 || n2 < 0){
        return false;
    }

    return n1 == n2;
}

int main(){

    string binary, hexa;

    cin >> binary >> hexa;

    cout << compareBinHex(binary, hexa) << endl;

}