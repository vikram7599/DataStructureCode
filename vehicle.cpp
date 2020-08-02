#include<iostream>
using namespace std;
class Vehicle{
    private:
        int maxSpeed;
    protected:
        int numTyres;
    public:
        string color;

    Vehicle(){
        cout << "Vehicle Default Constructo" <<endl;
    }
    Vehicle(int x){
        numTyres = x;
        cout << "Vehicle constructor" <<endl;
    }
};