#include<iostream>
#include<string>

using namespace std;

class Toys{
public:
    string toy;
    int price;

    Toys(string toyName, int toyPrice){
        toy=toyName;
        price=toyPrice;
    };
};