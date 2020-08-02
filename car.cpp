#include<iostream>
#include "vehicle.cpp"
using namespace std;
class Car : public Vehicle{
    public:
        int numGears;
    
    Car( ) : Vehicle(){
        cout << "Car constructor" <<endl;
    }

    void print(){
        cout << numTyres << " " << color << " " << numGears << endl;
    }
};

class Honda : public Car{
    public:
        int numGears;
    
    void print(){
        cout << numTyres << " " << color << " " << numGears << endl;
    }

    Honda(int y) : Car(){
        cout << "Honda Constructor" <<endl;
    }
};