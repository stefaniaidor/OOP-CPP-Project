#include <iostream>
#include <map>
#include <iterator>
#include "NaughtyCheck.cpp"
#include "AuxFunctions.h"
#include "Matrix.h"
#include <list>
using namespace std;

int main() {

    /**
     Adaug in lista de tip Letter scrisorile a 5 copii care contin:
                    numele, prenumele, varsta, orasul de provenienta, culoarea plicului si wishlist-ul fiecaruia
     */
    letters.push_back(new Letter("Smith", "Tony", 7, "Buenos Aires", "blue", {"Police Car", "Talking Tom", "Reading Book"}));
    letters.push_back(new Letter("William", "Jane", 9, "Mendoza", "pink", {"Frozen Princess", "Puzzle","Baby Riki"}));
    letters.push_back(new Letter("Oliver", "Connor", 13, "Rosario", "blue", {"Play Station"}));
    letters.push_back(new Letter("Thomas", "Jennifer", 8, "La Plata", "pink", {"Puppet House"}));
    letters.push_back(new Letter("Madison", "Emily", 6, "Santa Fe", "pink", {"Frozen Princess"}));

    /**
     listCheck este o lista de tip NaughtyCheck pe care o detin Elfii, unde se regaseste fiecare copil si statusul sau:
     bun sau rau
     */
    listCheck.push_back(new NaughtyCheck("Smith", "good"));
    listCheck.push_back(new NaughtyCheck("William","bad"));
    listCheck.push_back(new NaughtyCheck("Oliver","good"));
    listCheck.push_back(new NaughtyCheck("Thomas","bad"));
    listCheck.push_back(new NaughtyCheck("Madison","good"));

    /**
     myToys este o lista de tipul Toy, care reprezinta inventarul, continand numele jucariilor existente in atelier si pretul lor
     */
    myToys.push_back(new Toys("My Little Pony", 15));
    myToys.push_back(new Toys("Barbie Doll", 30));
    myToys.push_back(new Toys("Talking Tom", 25));
    myToys.push_back(new Toys("Frozen Princess", 55));
    myToys.push_back(new Toys("Police Car", 7));
    myToys.push_back(new Toys("Puzzle", 50));
    myToys.push_back(new Toys("Baby Riki", 9));
    myToys.push_back(new Toys("Play Station", 400));
    myToys.push_back(new Toys("Reading Book", 10));

    /**
     Declar 3 liste de tipul string, utile pentru realizarea cadourilor pentru fiecare copil, in functie de statusul lor.
        * toysForGood - reprezinta cadoul pentru copiii buni, care se va reactualiza la fiecare pas
        * toysForBad - reprezinta cadoul pentru copiii rai, care se va reactualiza la fiecare pas
        * foundToysForDelivery - o lista auxiliara in care se vor adauga initial dar acele jucarii din wishlist-ul fiecarui copil
                                care se afla pe inventar; se reactualizeaza la fiecare copil
     */
    list<string> toysForGood;
    list<string> toysForBad;
    list<string> foundToysForDelivery;

    for(it=letters.begin(); it!=letters.end();it++) {
            if (isGood(it.operator*()->name, listCheck)) {
                cout << "GOOD" << " " << it.operator*()->name << " " << it.operator*()->surname << " ";
                giftBags(it);
                cout << endl;
            } else{
                cout << endl << "BAD" << " " << it.operator*()->name << " " << it.operator*()->surname << " ";
                giftBags(it, true);
                cout << endl;
            }
        }

    cout<<"Total acadele: " << acadeleTotal<<endl;
    cout<<"Total carbuni: " << carbuni<<endl;
    cout<<"Buget extra total: " << acadeleTotal*1 + carbuni*0.5 <<" $." <<endl;

    getPackColor();

    City* Rovaniemi = new City("Rovaniemi",0);
    City* BuenosAires = new City("Buenos Aires",1);
    City* Rosario = new City("Rosario", 2);
    City* Mendoza = new City("Mendoza", 3);
    City* LaPlata = new City("La Plata", 4);
    City* SantaFe = new City("Santa Fe", 5);

    cities.push_back(Rovaniemi);
    cities.push_back(Rosario);
    cities.push_back(BuenosAires);
    cities.push_back(Mendoza);
    cities.push_back(LaPlata);
    cities.push_back(SantaFe);

    float *p;
    p=dijkstra(A,Rovaniemi->code);
    cout<<endl<<"Distance from Rovaniemi to each city: "<<endl;
    cout<<endl;
    printSolution(p);
    for(gpsIt =gps.begin(); gpsIt != gps.end(); gpsIt++)
    {
        if(gpsIt.operator*()->city->name=="Rovaniemi")
        {
            gps.remove(gpsIt.operator*());
        }
    }

    cout<<endl;

        gpsByDist = gps;
        gpsByDist.sort([] (const GPS *g1, GPS *g2) { return g1->distanceFromSource < g2->distanceFromSource;});

        cout<<"Plecare: Rovaniemi"<<endl;
        cout<<"Traseu: "<<endl;
        cout<<"Rovaniemi ----> ";
        for(gpsIt = gpsByDist.begin() ; gpsIt != gpsByDist.end() ; gpsIt++)
        {
            printf("%s ----> ", gpsIt.operator*()->city->name.c_str());
        }
        cout<< "Rovaniemi"<< endl;

}









