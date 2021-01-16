#include "Lists.h"
#include <algorithm>
#include <iomanip>
#include "AuxVariables.h"
#define V 6
#ifndef PROIECTLABORATORPOO_AUXFUNCTIONS_H
#define PROIECTLABORATORPOO_AUXFUNCTIONS_H

#endif //PROIECTLABORATORPOO_AUXFUNCTIONS_H

/**
    isGood verifica statusul fiecarui copil de pe lista elfilor, in functie de numele lor
    returneaza true pentru cei buni, false pentru cei rai
 */
bool isGood(string nume, list<NaughtyCheck*> check){
    for(itr=check.begin(); itr!=check.end(); itr++){
        if(nume==itr.operator*()->getName()){
            if(itr.operator*()->getStatus()=="good")
                return true;
        }
    }
    return false;
}
/**
    printList afiseaza lista jucariilor existente pe inventar
 */
void printList(list<string> myList){
    for(list<string>::iterator itrr=myList.begin(); itrr!=myList.end(); itrr++){
        cout<<*itrr<<" ; ";
    }
}
/**
    getTotalPrice calculeaza pretul total al jucariilor existente intr-o lista, dupa caz, in functie de lista data ca parametru
 */
int getTotalPrice(list<string> pricing)
{
    for(list<string>::iterator it = pricing.begin(); it != pricing.end(); it++)
        for(toyIt = myToys.begin(); toyIt != myToys.end(); toyIt++)
        {
            if(toyIt.operator*()->toy == *it)
            {
                pretTotal+=toyIt.operator*()->price;
            }
        }
    return pretTotal;
}
/**
 2 functii giftBags, unde apare overloading:
 * prima creeaza cadoul pentru copiii buni
 * a doua creeaza cadoul pentru copiii rai, in functie de scrisoarea lor si carbunele care trebuie adaugat in cadou
 */
void giftBags(list<Letter*>::iterator lett) {
    int totalPriceForGood = 0;
    int priceBeforeNextGift = 0;
    wishes = lett.operator*()->wishlist;
    for (wishesIt = wishes.begin(); wishesIt != wishes.end(); wishesIt++) {
        for (toyIt = myToys.begin(); toyIt != myToys.end(); toyIt++) {
            if (toyIt.operator*()->toy == *wishesIt && totalPriceForGood < 100 && toyIt.operator*()->price < 100) {
                toysForGood.push_back(toyIt.operator*()->toy);
                totalPriceForGood += toyIt.operator*()->price;
            }

        }
    }
    if (toysForGood.empty())
    {
        toysForGood.push_back("Default 100$ Gift");
        priceBeforeNextGift = 100;
    }
    else {
        if (totalPriceForGood > 100) {
            toysForGood.pop_back(); //daca pretul jucariilor existente in inventar de pe wishlist ul copilului depaseste 100,
                                    // se elimina ultimul element adaugat in lista
            priceBeforeNextGift = getTotalPrice(toysForGood);//se acualizeaza si pretul, dupa ce se elimina jucaria care depasea bugetul total
        }
        else
            priceBeforeNextGift = getTotalPrice(toysForGood);
    }

    countAcadele= 100 - priceBeforeNextGift;
    cout<<endl;
    cout << "Toys for " << it.operator*()->name<< " : ";
    printList(toysForGood);
    cout << endl << "Total price: " << priceBeforeNextGift << endl;
    cout << "Total lollipops for " << it.operator*()->name<< " : " << countAcadele<<endl;
    acadeleTotal+=countAcadele;
    pretTotal = 0;
    toysForGood.clear();
}

void giftBags(list<Letter*>::iterator lett, bool carbune) {
    int totalPriceForBad = 0;
    int priceBeforeNextGift = 0;


    wishes = lett.operator*()->wishlist;
    for (wishesIt = wishes.begin(); wishesIt != wishes.end(); wishesIt++) {
        for (toyIt = myToys.begin(); toyIt != myToys.end(); toyIt++) {
            if (toyIt.operator*()->toy == *wishesIt && totalPriceForBad < 10 && toyIt.operator*()->price < 10) {
                toysForBad.push_back(toyIt.operator*()->toy);
                totalPriceForBad+=toyIt.operator*()->price;

            }

        }
    }
    if(toysForBad.empty()) {
        toysForBad.push_back("Default 10$ Gift");
        priceBeforeNextGift = 10;
    }
    else{
        if(totalPriceForBad > 10) {
            toysForBad.pop_back();
            priceBeforeNextGift = getTotalPrice(toysForBad);
        }
        else
            priceBeforeNextGift = getTotalPrice(toysForBad);
    }


    countAcadele = 10 - priceBeforeNextGift;
    cout<<endl;
    cout << "Toys for " << it.operator*()->name<< " : ";
    printList(toysForBad);
    cout << endl << "Total price: " << priceBeforeNextGift << endl;
    cout << "Total lollipops for " << it.operator*()->name<< " : " << countAcadele<<endl;
    carbuni++;
    acadeleTotal+=countAcadele;
    pretTotal=0;
    toysForBad.clear();
}
//calcularea ambalajelor roz si albastre
void getPackColor()
{       //folosesc try catch pentru evitarea cazului in care se introduce un ambalaj de alta culoare decat cele doua necesare:blue sau pink
        for (it = letters.begin(); it != letters.end(); it++) {
            try {
                if (it.operator*()->envelopeColour == "pink") {
                    girlsEnvelope++; //counter pentru ambalajele roz folosite
                } else if (it.operator*()->envelopeColour == "blue") {
                    boysEnvelope++; //counter pentru ambalajele albastre folosite
                }
                else
                    throw "Wrong colour";
            }
            catch (const char* msg) {
                cout<<"Exception occured. The envelope must be pink or blue."<<endl;
                exit(0);
            }
        }
        cout<<"Total envelopes for boys: "<<boysEnvelope<<endl;
        cout<<"Total envelopes for girls: "<<girlsEnvelope<<endl;
}

int minDistance(float dist[], bool sptSet[])
{
    // Initializez valoarea minima
    float min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

//afisarea array-ului cu distanta de la Rovaniemi la fiecare oras
void printSolution(float dist[])
{
    int i = 0;
    printf("City \t\t Distance\n");
    for(citiesIt=cities.begin();citiesIt!=cities.end(); citiesIt++)
    {
        printf("%s \t %.2f\n", citiesIt.operator*()->name.c_str(),dist[i]);
        gps.push_back(new GPS(citiesIt.operator*(),dist[i]));
        i++;
    }
}

float * dijkstra(float graph[V][V], int src)
{
    static float dist[V];

    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }


    return dist;
}

