#include <string>
#include "City.cpp"

using namespace std;

class GPS{
public:
    City* city;
    float distanceFromSource;

    bool operator == (const GPS *s) const { return "Rovaniemi" == s->city->name; }
    bool operator != (const GPS *s) const { return !operator==(s); }

    GPS(City* oras, float dist){
        city = oras;
        distanceFromSource = dist;
    }
};
