#include <iostream>
#include <string>
using namespace std;

class City{
    public:
        string name;
        int code;
        int childNr;

        City(string nume, int id){
            name = nume;
            code = id;
        }
};
