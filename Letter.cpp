#include<iostream>
#include<string>
#include<list>
using namespace std;

class Letter {

public:
    string name;
    string surname;
    int age;
    string city;
    string envelopeColour; //pink or blue
    list<string> wishlist;
    //Letter(string firstName, string lastName, int kidAge, string town, string colour, list<string> toys);
    //~Letter();

    Letter(string firstName, string lastName, int kidAge, string town, string colour, list<string> toys) {
        name=firstName;
        surname=lastName;
        age=kidAge;
        city=town;
        envelopeColour=colour;
        wishlist=toys;
}
    ~Letter(void){
    cout<<"Object is being deleted."<<endl;
    }
};


